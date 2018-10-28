//Name: James Iorgovan
//Date: Fall 2018
//Assignemnt: Lab 5 - Multiple inputs and outputs
//Description: Imagine 4 LEDs. They are all unlit as you stand in a bright room. But as you cup your hand over it, the LEDs begin to light up. It kind of how street lights work.
//as soon as there is a certain dimness, more lights turn on. Also, for the buzzer, it will be controlled by the potentiometer. As you increase the potentiometer value,
//the buzzer sound increases. For this we will use a map function because orignially the values go from 0-1023, but for the map function it is 0-255.
//Assumptions: I think that the easy part about this will be similar to lab 4. My method of having certain LEDs to light up is by having a hard code that digitalWrites which
//LEDs will stay lit while others stay turned off. The values will be based on how little light the photoresistor takes in.
//References: Code snippet - Lab 2, Lab 3, Lab 4
//            Setup help -   https://www.arduino.cc/en/Reference/AnalogWrite
//                           https://www.arduino.cc/en/Reference/Map
//                           https://www.arduino.cc/en/Reference/AnalogRead
//                           http://www.ardumotive.com/how-to-use-a-buzzer-en.html



const int potentiometer = A0, photoResistor = A1; // the number of the potentiometer and photoResistor analog pin
int brightness = 0; // value of photoResistor
int potentiometerVal = 0; // value of potentiometer
const int LED1 = 7, LED2 = 6, LED3 = 5, LED4 = 4; // the number of the LED pin
const int buzzer = 3; //buzzer to arduino pin 3 because the tilda (pulse width modulation)

void setup(){

  pinMode(photoResistor, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 1 as an output
  delay(100); 
  Serial.begin(9600);
  

}

void loop(){

  int val = analogRead(A0);
  val = map(val, 0, 1023, 0, 255);   // change value of potentiometer 
  analogWrite(3, val);
  
  potentiometerVal = analogRead(potentiometer); // read value of potentiometer
  brightness = analogRead(photoResistor); // read brightness input to photoResistor
  displayValue(brightness);
}

  void displayValue(int brightness){
  
  if(brightness <= 500){      //As the value of the brightness is less than or equal to 500, all LEDs will stay lit.
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
  }
  
  else if(brightness <= 550){ //As the value of the brightness is less than or equal to 550, 3 LEDs will stay lit.
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
  }

  else if(brightness <= 600){ //As the value of the brightness is less than or equal to 600, 2 LEDs will stay lit.
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
  }

  else if(brightness <= 700){  //As the value of the brightness is less than or equal to 700, 1 LED will stay lit.
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
  }

  else if(brightness <= 800){ //As the value of the brightness is less than or equal to 800, no LEDs will stay lit.
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
  }
 }
