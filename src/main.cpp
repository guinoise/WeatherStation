#include <configs.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Variables
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
static uint16_t loop_delay = 10000;
AsyncWebServer server(80);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Setup.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


void setup(void) {
  Serial.begin(115200);
  Serial.println("Setting WIFI_STA mode");
  WiFi.mode(WIFI_STA);
  Serial.printf("Setting WiFi hostname %s\n", hostName);
  WiFi.setHostname(hostName);
  Serial.printf("Connecting to SSID %s\n", ssid);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.printf("Connected to : %s \n", ssid);
  Serial.printf("IP address   : %s \n", WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "Hi! I am ESP8266.");
  });

  AsyncElegantOTA.begin(&server);    // Start ElegantOTA
  server.begin();
  Serial.println("HTTP server started");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Loop.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop(void) {
}