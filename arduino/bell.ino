#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WebSocketClient.h>

#define SSID "WLAN Name"
#define PSK  "WLAN Password"

char path[] = "/";
char host[] = "j.braun.mooo.com";

WebSocketClient webSocketClient;

// Use WiFiClient class to create TCP connections
WiFiClient client;
ESP8266WiFiMulti WiFiMulti;

void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D5, OUTPUT);
  digitalWrite(D0, LOW);
  digitalWrite(D5, LOW);
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Connecting ");

  WiFiMulti.addAP(SSID, PSK);
  while (WiFiMulti.run() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  if (client.connect("j.braun.mooo.com", 8081)) {
    Serial.println("Connected");
  } else {
    Serial.println("Connection failed");
    ESP.restart();
  }

  webSocketClient.path = path;
  webSocketClient.host = host;

  if (webSocketClient.handshake(client)) {
    Serial.println("Handshake successful");
  } else {
    Serial.println("Handshake failed.");
    ESP.restart();
  }
}

void loop() {
  String data;
  
  // put your main code here, to run repeatedly:
  if (client.connected()) {
    
    webSocketClient.getData(data);
    if (data.length() > 0) {
      if (data.equals("bell")) {
        digitalWrite(D0, HIGH);
        delay(500);
        digitalWrite(D0, LOW);
        delay(250);
        digitalWrite(D0, HIGH);
        delay(250);
        digitalWrite(D0, LOW);
        delay(250);
        digitalWrite(D0, HIGH);
        delay(500);
        digitalWrite(D0, LOW);
      }
      Serial.print("Received data: \"");
      Serial.print(data);
      Serial.print("\"");
    }
    
  } else {
    Serial.println("Client disconnected.");
    while (1) {
      // Hang on disconnect.
    }
  }
  
  // wait to fully let the client disconnect
  delay(100);
}
