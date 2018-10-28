// James Iorgovan
// Date: Fall 2018
// Lab Partner: Christian Rivera
// Lab 7 - Arduino to Arduino communication
// Description - Button press on one arduino should toggle the state of the LED on the other (on/off) and not keep the LED lit while being pressed. 
// Assumptions - The arduinos will be connected to their own grounds. The LED pin is in pin 9. The button is on pin 4. We used pins 0 (RX) and 1 (TX) to connect our arduinos
// and to send a signal. 
// References - Lab 2 and Lab 6

const int ledPin = 9;
const int buttonPin = 4;
int input = 0;
int ledState = 0;
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int bytesAvailable = Serial.available();  // returns number of bytes to be read
  
  for (int i = 0; i < bytesAvailable; i++) {
    Serial.read();  //reads one byte from the wire
      ledState = 1 - ledState;
      }

  if (ledState) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  
  //
  if (digitalRead(buttonPin)) {
    if (buttonState == 0) {
      Serial.write('a');
    }
    buttonState = 1;
  }
  else {
    buttonState = 0;
  }
}
