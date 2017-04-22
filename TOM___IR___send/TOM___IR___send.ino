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

const int BUTTON1_LED = 7;
const int BUTTON2_LED = 8;

IRsend mySender;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON1_PIN , INPUT);
  pinMode(BUTTON2_PIN , INPUT);

  pinMode(BUTTON1_LED , OUTPUT);
  pinMode(BUTTON2_LED , OUTPUT);
  
  delay(2000); while (!Serial); //delay for Leonardo
  Serial.println(F("Every time you press a key is a serial monitor we will send."));
}

void loop() {
  int b1value = analogRead(BUTTON1_PIN);
  if (b1value < 10){
    mySender.send(SONY,0xa8bca, 20);//Sony DVD power A8BCA, 20 bits
    Serial.println(F("Button1 Pressed"));
    digitalWrite(BUTTON1_LED , HIGH); //analogWrite ok too
  }else{
    Serial.println(F("Button1 NOT Pressed"));
    digitalWrite(BUTTON1_LED , LOW);
  }

  int v = analogRead(BUTTON2_PIN);
  Serial.println(v);
  if (v < 10 ){
    mySender.send(SONY,0xa8bca, 20);//Sony DVD power A8BCA, 20 bits
    Serial.println(F("Button2 Pressed"));
    digitalWrite(BUTTON2_LED , HIGH);
  }else{
    digitalWrite(BUTTON2_LED , LOW);
    Serial.println(F("Button2 NOT Pressed"));
  }
  delay(500);

  //Serial.println("Nothing");
  //}
}

