
// James Iorgovan
// Date: Fall 2018
// Lab 9 - Graphing sensor data on a PC
// Description - Connect two analog devices to the arduino and plot the data received on the computer using processing.
// Assumptions - Never done a lab like this so it should be very interesting getting actual data to display 
// References - "http://arduino.cc/en/Tutorial/Graph"
//              "https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing#introduction"
//              "https://www.processing.org/download/?processing"

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
}

void loop() {
  // send the value of analog input 0:
  Serial.println(analogRead(A0));
  Serial.println(analogRead(A1));
  delay(2);
}
