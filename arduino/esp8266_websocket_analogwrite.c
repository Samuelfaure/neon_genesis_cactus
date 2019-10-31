#include <ESP8266WiFi.h>
#include <WebSocketsServer.h>

#ifndef ESP8266_LED
#define ESP8266_LED 2
#define STASSID "my_wifi_name"
#define STAPSK  "my_wifi_password"
#endif

// Constants
const char* ssid     = STASSID;
const char* password = STAPSK;

int light_power;

// Globals
WebSocketsServer webSocket = WebSocketsServer(80);

// Called when receiving any WebSocket message
void onWebSocketEvent(uint8_t num,
                      WStype_t type,
                      uint8_t * payload,
                      size_t length) {
  // Figure out the type of WebSocket event
  if (type == WStype_TEXT) {
    light_power = atoi((char*)payload);

    if (light_power >= 1023) {
      light_power = 1022;
    }

    if (light_power <= 0) {
      light_power = 1;
    }
    analogWrite(ESP8266_LED, light_power);
  }
}
void setup() {
  pinMode(ESP8266_LED, OUTPUT);
  digitalWrite(ESP8266_LED, HIGH);
  // Start Serial port
  Serial.begin(9600);

  // Connect to access point
  Serial.println("Connecting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) {
    delay(500);
    Serial.print(".");
  }

  // Print our IP address
  Serial.println("Connected!");
  Serial.print("My IP address: ");
  Serial.println(WiFi.localIP());

  // Blip when connected to wifi
  digitalWrite(ESP8266_LED, LOW);
  delay(1000);
  digitalWrite(ESP8266_LED, HIGH);
  // Start WebSocket server and assign callback
  webSocket.begin();
  webSocket.onEvent(onWebSocketEvent);
}

void loop() {
  // Look for and handle WebSocket data
  webSocket.loop();
}
