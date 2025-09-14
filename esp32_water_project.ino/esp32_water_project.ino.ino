#include <WiFi.h>
#include <ThingSpeak.h>

// WiFi credentials
const char* ssid = "YOUR SS ID";
const char* password = "YOUR WIFI PASSWORD";

// ThingSpeak credentials
unsigned long channelID = "YOUR CHANNEL ID";    // e.g., 1234567
const char* writeAPIKey = "YOUR API KEY FROM THINGSPEAK";

WiFiClient client;

// Sensor pins
#define TRIG_PIN 5
#define ECHO_PIN 18
#define TURBIDITY_PIN 34

// Function to measure distance
float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2; // cm
  return distance;
}

// Function to read turbidity
int getTurbidity() {
  return analogRead(TURBIDITY_PIN); // Raw ADC value (0–4095)
}

void setup() {
  Serial.begin(115200);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");

  ThingSpeak.begin(client);
}

void loop() {
  // Read sensors
  float waterLevel = getDistance();
  int turbidityValue = getTurbidity();

  // Print for debugging
  Serial.print("Water Level (cm): ");
  Serial.println(waterLevel);
  Serial.print("Turbidity Value: ");
  Serial.println(turbidityValue);

  // Send to ThingSpeak
  ThingSpeak.setField(1, waterLevel);
  ThingSpeak.setField(2, turbidityValue);

  int response = ThingSpeak.writeFields(channelID, writeAPIKey);

  if (response == 200) {
    Serial.println("Data sent to ThingSpeak successfully!");
  } else {
    Serial.println("Error sending data. HTTP error code: " + String(response));
  }

  delay(600000); // Minimum 15 sec delay for ThingSpeak
}
