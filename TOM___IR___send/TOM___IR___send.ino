/* send.ino Example sketch for IRLib2
 *  Illustrates how to send a code.
 */
#include <IRLibSendBase.h>    // First include the send base
//Now include only the protocols you wish to actually use.
//The lowest numbered protocol should be first but remainder 
//can be any order.
#include <IRLib_P01_NEC.h>    
#include <IRLib_P02_Sony.h>   
#include <IRLibCombo.h>     // After all protocols, include this
// All of the above automatically creates a universal sending
// class called "IRsend" containing only the protocols you want.
// Now declare an instance of that sender.

const int BUTTON1_PIN = A1;
const int BUTTON2_PIN = A2;

const int BUTTON1_LED_PIN = 7;
const int BUTTON2_LED_PIN = 8;

bool DEBUG = true;

IRsend mySender;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON1_PIN, INPUT);
  pinMode(BUTTON2_PIN, INPUT);
  pinMode(BUTTON1_LED_PIN, OUTPUT);
  pinMode(BUTTON2_LED_PIN, OUTPUT);
  
  delay(2000); while (!Serial); //delay for Leonardo
  Serial.println(F("Ready!"));
}

void loop() {
  
  bool button1State = updateButton(BUTTON1_PIN, BUTTON1_LED_PIN);
  if(button1State){
    mySender.send(SONY,0xa8bca, 20);
    if(DEBUG) Serial.println(F("button1 pressed"));
  }

  bool button2State = updateButton(BUTTON2_PIN, BUTTON2_LED_PIN);
  if(button2State){
    mySender.send(SONY,0xa8bca, 20);
    if(DEBUG) Serial.println(F("button2 pressed"));
  }
  
  if(DEBUG) delay(100);
}


//return true if button is pressed
bool updateButton(int buttonPin, int LEDpin){
  int bValue = digitalRead(buttonPin);
  if (bValue == HIGH){
    digitalWrite(LEDpin, HIGH); //analogWrite ok too
    return true;
  }else{
    digitalWrite(LEDpin, LOW);
    return false;
  }
}
