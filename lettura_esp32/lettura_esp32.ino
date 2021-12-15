#include <WiFi.h>
#include <HTTPClient.h>
#include <analogWrite.h>
#include <ArduinoJson.h>

#define LED1 32
#define LED2 33
#define LED3 25
//#define DEBUG

const char* ssid = "TCPBerry_2.4";
const char* password =  "Vmware1!";
const char* serverName = "http://172.16.5.4:3000/api";
unsigned long lastTime = 0;
unsigned long timerDelay = 40;

void setup(){
  #ifdef DEBUG
  Serial.begin(9600);
  while(!Serial.available()){;;}
  #endif
  WiFi.begin(ssid, password);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  if ((millis() - lastTime) > timerDelay) {
    
    //Check WiFi connection status
    if(WiFi.status() == WL_CONNECTED){
      HTTPClient http;

      http.begin(serverName);
      
      http.addHeader("Content-Type", "application/json");

      if(http.GET() == 200){
        String json = http.getString();
        StaticJsonDocument<256> doc;
        
        DeserializationError error = deserializeJson(doc, json);
        // Test if parsing succeeds.
        if (error) {
          #ifdef DEBUG
          Serial.print(F("deserializeJson() failed: "));
          Serial.println(error.f_str());
          #endif
          return;
        }

        #ifdef DEBUG
        Serial.println("Get received!");
        String date = doc["date"];
        int xPosition = doc["xPosition"];
        int yPosition = doc["yPosition"];
        bool switchBtn = doc["switch"];
        Serial.println("DATE= " + date + "\n" + "XPOSITION= " + xPosition + "\n" + "YPOSITION= " + yPosition + "\n" + "SWITCH= " + switchBtn + "\n--------");
        #endif

        analogWrite(LED1,int(doc["xPosition"]) / 16.0588235);
        analogWrite(LED2,int(doc["yPosition"]) / 16.0588235);
        digitalWrite(LED3,bool(doc["switch"]));
      }
    }
    else {
      #ifdef DEBUG
      Serial.println("WiFi Disconnected");
      #endif
    }
    lastTime = millis();
  }
}
