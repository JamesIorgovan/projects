//Name: James Iorgovan
//Date: Fall 2018
//Assignemnt: Lab 1 - Get started with Arduino
//Description: There are two LEDs, one red one green. They will each blink at different times
//at a constant interval but never simultaneously.
//Assumptions: The tricky part will be getting the loop function to get both LEDs to blink
//one at a time. As for connecting the LEDs, jumper wires, and resistors is not that much of an 
//issue due to watching guides on how to assemble.
//References: Code snippet - "https://www.arduino.cc/en/Tutorial/Blink"

/*int white4 = 2;
int white3 = 3;
int blue2 = 4;
int yellow2 = 5;
int white2 = 6;
int white = 7;
int green2 = 8;
int blue = 9;
int yellow = 10; */
int green = 8;
int red = 12;
int onBoard = 13;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
 /* pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);*/
  pinMode(8, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(onBoard, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(onBoard, LOW);    // turn the LED off by making the voltage LOW
  delay(0);                       // wait for a second
  {
  digitalWrite(red, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(red, LOW);    // turn the LED off by making the voltage LOW
  delay(0);}               
                              //NOTE: My first assumption was to just copy the digitalWrite and
                              //delay functions inside of the loop for the 2nd and 3rd blinkers.
                              //This worked and I went a step futher to test this hypothesis
                              //with 10 more blinkers. I am however pondering on how to
                              //condense this hard-code into a sort of formula.
 // {
  digitalWrite(green, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(green, LOW);    // turn the LED off by making the voltage LOW
  delay(0);}  
/* {
  digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(0);}  
  {
  digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(0);}  
  {
  digitalWrite(green2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(green2, LOW);    // turn the LED off by making the voltage LOW
  delay(0);}  
  {
  digitalWrite(white, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(white, LOW);    // turn the LED off by making the voltage LOW
  delay(0);}  
  {
  digitalWrite(white2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(white2, LOW);    // turn the LED off by making the voltage LOW
  delay(0);}  
  {
  digitalWrite(yellow2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow2, LOW);    // turn the LED off by making the voltage LOW
  delay(0);}  
  {
  digitalWrite(blue2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue2, LOW);    // turn the LED off by making the voltage LOW
  delay(0);}  
  {
  digitalWrite(white3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(white3, LOW);    // turn the LED off by making the voltage LOW
  delay(0);}  
  {
  digitalWrite(white4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(white4, LOW);    // turn the LED off by making the voltage LOW
  delay(0);} */
}
