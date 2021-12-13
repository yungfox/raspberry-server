#include <WiFi.h>
#include <HTTPClient.h>

#define JOYSTICK_X 32
#define JOYSTICK_Y 33
#define JOYSTICK_BUTTON 34
#define DEBUG

const char* ssid = "";
const char* password =  "";
const char* serverName = "http://:3000/api";
unsigned long lastTime = 0;
unsigned long timerDelay = 1000;

void setup(){
  #ifdef DEBUG
  Serial.begin(9600);
  while(!Serial.available()){;;}
  #endif
  WiFi.begin(ssid, password);
  pinMode(JOYSTICK_BUTTON, INPUT_PULLUP);
}

void loop() {
  if ((millis() - lastTime) > timerDelay) {
    int x = analogRead(JOYSTICK_X);
    int y = analogRead(JOYSTICK_Y);
    bool button = digitalRead(JOYSTICK_BUTTON);

    #ifdef DEBUG
    Serial.print("XPOSITION= " + String(x));
    Serial.print(",\tYPOSITION= " + String(y));
    Serial.println(",\tSWITCH= " + String(button));
    #endif
    
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;

      http.begin(serverName);
      
      http.addHeader("Content-Type", "application/json");

      http.POST("{\"xPosition\":"+String(x)+",\"yPosition\":"+String(y)+",\"switch\":\""+String(button)+"\"}");
      #ifdef
      Serial.println("Post send!");
      #endif
    }
    else {
      #ifdef DEBUG
      Serial.println("WiFi Disconnected");
      #endif
    }
    lastTime = millis();
  }
}
