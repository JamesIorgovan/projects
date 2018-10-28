//Name: James Iorgovan
//Date: Fall 2018
//Assignemnt: Lab 4 - More complicated input
//Description: The display of the photoresistorshould state the relative amount of light in the room 
//(dark, partially dark, medium, partially light, fully lit).
//Assumptions: I assume that the photoresistor will not act up like the potentiometer did from lab 3. Also, the wiring of the lab 
//won't exactly matter, as long as we have it similar to the photo.
//References: Code snippet - "http://playground.arduino.cc/Learning/PhotoResistor"
//                           "https://www.instructables.com/id/How-to-use-a-photoresistor-or-photocell-Arduino-Tu/"
//                           "http://learn.adafruit.com/photocells"
//                            Lab 3
// include the library code:
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int photoResistor = A0, firstLine;
int brightness = 0, value = 0;

void setup(){
  
  lcd.begin(16, 2);
  pinMode(photoResistor, INPUT);
  Serial.begin(9600);
}

void myDisplay(String var){
  
  lcd.clear();
  lcd.print(var);
}

void loop(){
  
  brightness = analogRead(photoResistor);   // read in unput
  displayValue(brightness);
  delay(100);
}

void displayValue(int brightness){
    
  if(brightness <= 300){
    myDisplay("dark");
  }
  
  else if(brightness <= 400){
    myDisplay("partially dark");
  }
  
  else if(brightness <= 500){
    myDisplay("medium");
  }
  
  else if(brightness <= 600){
    myDisplay("partially lit");
  }
  
  else if(brightness <= 620){
    myDisplay("fully lit");
  }
}
