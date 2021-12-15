#include <WiFi.h>
#include <HTTPClient.h>

#define JOYSTICK_X 34
#define JOYSTICK_Y 35
#define JOYSTICK_BUTTON 32
//#define DEBUG

const char* ssid = "TCPBerry_2.4";
const char* password =  "Vmware1!";
const char* serverName = "http://172.16.5.4:3000/api";
unsigned long lastTime = 0;
unsigned long timerDelay = 40;
bool button;

void setup(){
  Serial.begin(9600);
  #ifdef DEBUG
  Serial.begin(9600);
  while(!Serial.available()){;;}
  #endif
  WiFi.begin(ssid, password);
  pinMode(JOYSTICK_X, INPUT);
  pinMode(JOYSTICK_Y, INPUT);
  pinMode(JOYSTICK_BUTTON, INPUT_PULLUP);
  button = digitalRead(JOYSTICK_BUTTON);
}


void loop() {
  if ((millis() - lastTime) > timerDelay) {
    int x = analogRead(JOYSTICK_X);
    int y = analogRead(JOYSTICK_Y);

    #ifdef DEBUG
    Serial.print("XPOSITION= " + String(x));
    Serial.print(",\tYPOSITION= " + String(y));
    Serial.println(",\tSWITCH= " + String(digitalRead(JOYSTICK_BUTTON)));
    #endif
    
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;

      http.begin(serverName);
      
      http.addHeader("Content-Type", "application/json");

      if(button != digitalRead(JOYSTICK_BUTTON)){
        Serial.println(button);
        button = !button;
        http.POST("{\"xPosition\":"+String(x)+",\"yPosition\":"+String(y)+",\"switch\":"+String(button)+"}");
      }else{
        http.PATCH("{\"xPosition\":"+String(x)+",\"yPosition\":"+String(y)+"}");
      }
      #ifdef DEBUG
      Serial.println("Data send!");
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
