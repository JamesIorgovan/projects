// James Iorgovan
// Date: Fall 2018
// Lab 8 - Interrupts
// Description - When the first button is pressed, the display should display "Interrupted!"
// When the user presses button 2 the display goes back to displaying "Secs elapsed", and restarts the time a 0 seconds.
// Assumptions - The tricky part is having the interrupt displaying for as long as you do not hit the button that
//starts the display again. I will try to implement this by having a counter that resets each time it recursively
//traverses through a loop that will check if the values is equal to a certain number or not.
// References - Lab 6
//              "http://arduino.cc/en/Reference/attachInterrupt"
//              "https://www.arduino.cc/en/Reference/Millis"

#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,7,6,5,4);

int interruptPin = 2;    //button pin to interrupt
int resetPin = 3;        //button pin to reset time counter
int counter = 0;         //counts seconds
int buttonValue = 0;     //tracks button counter
int firstInterrupt = 0;  //track interrupt instances 

//-----------------------------------------------------------------------------
void setup(){
  lcd.begin(16, 2);
  pinMode(interruptPin, INPUT);
  pinMode(resetPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), resetCounter, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), start_Display_Again, CHANGE);
  }

//-----------------------------------------------------------------------------
void resetCounter(){
  lcd.clear();
  counter = 0;
  buttonValue = 1;
}

//-----------------------------------------------------------------------------
void start_Display_Again(){
  buttonValue = 0;  //reset button counter
}

//-----------------------------------------------------------------------------
void loop(){
  if(buttonValue != 1){  //activate interruption 
  lcd.setCursor(0,0);
  lcd.print("Secs elapsed:");
  lcd.setCursor(7,1);
  lcd.print(counter);
  
  if(firstInterrupt == 0){
    buttonValue = digitalRead(interruptPin);
    firstInterrupt = 1;
  }
    counter++;
  }else{
    lcd.setCursor(0,0);
    lcd.print("Interrupted!");
  }
  
  delay(1000); //1 sec
  lcd.clear();
} //end main loop
