#include<Wire.h>
#include "FirebaseESP8266.h"
#include<ESP8266WiFi.h>

const byte ledPin = D3; //Pin number of the LED
char FIREBASE_AUTH [] = " "; //Your Firebase Web API Key
char FIREBASE_HOST [] = " "; //Your Firebase URL
char WIFI_SSID [] = " ";     //Your WIFI SSID
char WIFI_PASSWORD [] = " "; //Your WIFI Password

FirebaseData firebaseData;
int led;
void setup(){
  Serial.begin(115200);
  pinMode(ledPin,OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
void loop(){
  if (Firebase.getInt(firebaseData,"/data")){ // Your Firebase data path
    led = firebaseData.intData();
    if(led == 1){
      digitalWrite(ledPin, HIGH);
      Serial.println("LED is ON");
    }
    else if (led == 0){
      digitalWrite(ledPin, LOW);
      Serial.println("LED is OFF");
    }
  }
    else{
      Serial.println(firebaseData.errorReason());
    }
    delay(3000);
}
