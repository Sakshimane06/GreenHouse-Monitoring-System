# GreenHouse-Monitoring-System
## About the project
A green house is where plants such as flowers and vegetables are grown. Green houses help to protect crops from many diseases, particularly those that are soil borne and splash onto plants in the rain. Numerous farmers fail to get good profits from the greenhouse crops for the reason that they can’t manage two essential factors, which determines plant growth as well as productivity. 
  1) Green house temperature
  2) Green House Humidity
To overcome such challenges, this greenhouse monitoring and control system comes to rescue.
To ensure the best possible plant growth, the suggested system, including temperature, moisture, soil humidity, light intensity, and so on, must be continuously monitored and managed. This work demonstrates a management system for greenhouse facilities based on the Internet of Things (IOT). The system can detect visible conditions such as humidity, soil moisture, temperature. All environmental data is transmitted to Thingspeak, a remotely accessible online platform, using the NodeMCU esp8266.

#### Features
  1) Real-time monitoring of temperature, humidity, soil moisture, and light intensity
  2) Remote data transmission and visualization using ThingSpeak
  3) Automated control system for optimal greenhouse conditions

#### Prerequisite
Before you begin, ensure you have met the following requirements:
###### Hardware:
  1) NodeMCU ESP8266
  2) DHT11 or DHT22 sensor (for temperature and humidity)
  3) Soil moisture sensor
  4) Light intensity sensor (e.g., LDR)
  5) Relay module (for controlling devices like fans, heaters, or pumps)
  6) Breadboard and connecting wires
###### Software:
  1) Arduino IDE
  2) ThingSpeak account (for data visualization)
  3) Libraries for sensors and ThingSpeak (installable via Arduino IDE Library Manager)

#### Installation
###### Open the project in Arduino IDE:
Open the '.ino' file in the Arduino IDE.
###### Install required libraries:
###### Configure your ThingSpeak account:
Create a new channel in ThingSpeak.
Note the 'Channel ID' and 'API Key'.
###### Update the code with your ThingSpeak credentials:
Open the .ino file in the Arduino IDE.
Replace placeholders with your actual 'Channel ID' and 'API Key'.
###### Upload the code to NodeMCU:
Connect your NodeMCU to your computer via USB.
Select the appropriate board and port in the Arduino IDE.
Click 'Upload' to flash the code onto the NodeMCU.
