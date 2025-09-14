Smart IoT-Based Water Tank Monitoring System

This project is an IoT-enabled smart water tank monitoring system built using an ESP32, an ultrasonic distance sensor (JSN-SR04T), and a turbidity sensor. It continuously measures water level and water quality (turbidity), then uploads the data to ThingSpeak for real-time monitoring and visualization.

🚀 Features

📊 Real-time water level measurement using an ultrasonic sensor.

🌊 Water quality detection using a turbidity sensor.

☁️ Automatic data upload to ThingSpeak Cloud.

💻 Easy monitoring from any device via the ThingSpeak dashboard.

🔌 Powered directly via USB (laptop/adapter/power bank).

🛠️ Components Used

ESP32 Development Board

JSN-SR04T Ultrasonic Distance Sensor (for water level)

Turbidity Sensor (for water clarity detection)

Jumper wires

Breadboard

USB Cable (for power & programming)

🔌 Circuit Connections
Component	ESP32 Pin	Notes
Ultrasonic TRIG	GPIO 5	Output
Ultrasonic ECHO	GPIO 18	Input
Turbidity Sensor	GPIO 34	Analog Input
VCC (both sensors)	5V / VIN	Power supply
GND (both sensors)	GND	Common ground
