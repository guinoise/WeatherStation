# WeatherStation
Code based on the kit *KeeYees WiFi Weather Station Kit for IoT with Tutorial, GY-BME280 Temperature Humidity Atmospheric Pressure Sensor + 1.3" OLED IIC LCD Display + 2 Set Jumper Wire + 400 Pin Breadboard*. The tutorial was not available, so need to do the coding. 
The instruction from https://www.uctronics.com/download/Amazon/K0061_ESP8266_KIT.pdf was a reference
## Material
- ESP8266 from NodeMCU
# Configuration / Secrets
The configuration variables and constants like WiFi SSID and password are stored in the file `src/configs.h`. This file can NOT be commited in git. Copy the file `src/configs.h.example` before compiling and changes values to yours.