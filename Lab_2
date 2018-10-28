//Name: James Iorgovan
//Date: Fall 2018
//Assignemnt: Lab 2 - Input and Output
//Description: 3 LEDs controlled by two buttons. The LEDs will increase and decrease in bit binary fashion from 1-7.
//One button will increase the bit by 1 and the other decrease by 1. Once 7 is reached, LEDs will continue to stay on
//and nothing will change if user keeps pressing the increase button.
//Assumptions: My first assumption is to first of all get the LEDs to light up controlled by the buttons. This will set
//a foundation (even though the lights will not stay on/off when I hit the increase/decrease button, but will flash).
//I will have to use bit masking in order to iterate throughout the 3 LEDs. 
//References: Code snippet - "https://www.arduino.cc/en/Tutorial/Button"
//                           "https://www.arduino.cc/en/Tutorial/BitMask"
//                           "https://www.arduino.cc/reference/en/language/structure/bitwise-operators/bitshiftleft/"
//                           "https://www.arduino.cc/reference/en/language/variables/data-types/bool/"


const int buttonPinDEC = 3, buttonPinINC = 2;                 // the number of the pushbutton pin
const int ledPin11 =  11, ledPin12 = 12, ledPin13 = 13;       // the number of the LED pin
int buttonStateOn = 0, buttonStateOff = 0;                    // variable for reading the pushbutton status
int buttonPinIncreaseState = 0, buttonPinDereaseState = 0;    // variable for reading the pushbutton status
int count = 0;                                                // count variable to keep track of the # of bit

void setup() {
  // initialize the LED pins as an output:
  pinMode(ledPin11, OUTPUT);
  pinMode(ledPin12, OUTPUT);
  pinMode(ledPin13, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPinDEC, INPUT);
  pinMode(buttonPinINC, INPUT); }

// check whether bool = true in order to bit shift led light up, if so LED = HIGH, else LED = LOW
void bitShiftLed(int LED, bool on){
  if(on) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW); } }

void loop() {
  buttonPinIncreaseState = digitalRead(buttonPinINC);
  buttonStateOff = digitalRead(buttonPinDEC);

  if ((buttonPinIncreaseState == HIGH) && (buttonPinIncreaseState != buttonPinDereaseState)  // increment bit shift
       (count!=7)) {
      count = count + 1; }
  
  if ((buttonStateOff == HIGH) && (buttonStateOff != buttonStateOn)  // decrement bit shift
      && (count!=0)) {
      count = count - 1; }

  bool mask1 = ((count >> 2) % 2) == 1;   // bit shift operations
  bool mask2 = ((count >> 1) % 2) == 1;
  bool mask3 = ((count >> 0) % 2) == 1;

  bitShiftLed(ledPin11, mask1);
  bitShiftLed(ledPin12, mask2);
  bitShiftLed(ledPin13, mask3);

  buttonStateOn = buttonStateOff;  
  buttonPinDereaseState = buttonPinIncreaseState; } // see that when button is on even after pressing 7 times and off when 7 times decremented
