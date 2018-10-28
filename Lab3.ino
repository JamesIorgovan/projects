//Name: James Iorgovan
//Date: Fall 2018
//Assignemnt: Lab 3 - Scrolling output
//Description: Display your name and your favorite quote appear on the 16x2 display, name 
//on first line and quote on the second line. The quote should not all fit on the screen and 
//so should scroll across the screen. Your name should not scroll across the screen, only the quote should scroll.  
//Assumptions: I think the difficult part will be having the text wrap around the LCD. I might approach this by 
//having a counter reset.
//References: Lab 1, Lab 2

// include the library code:
#include <LiquidCrystal.h>


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String quote = "Why does Amanda do that";

void setup() {
  lcd.begin(16, 2);
}

void loop() {

int q = quote.length();

  for (int positionCounter = 16; positionCounter >= 0; positionCounter--) {
    lcd.setCursor(0,0);
    lcd.print("James Iorgovan");
    
    
    lcd.setCursor(positionCounter,1); // will start increase by 1 until pos. 16 if pC is less than or equal to 0
    lcd.print(quote);
    
    delay(150);
    lcd.clear();
  }

  for(int positionCounter = 1; positionCounter < q; positionCounter++) {
    lcd.setCursor(0,0);
    lcd.print("James Iorgovan");

    lcd.setCursor(0,1);
    lcd.print(&quote[positionCounter]); // call address of quote instead of just one character

    
    delay(200);
   lcd.clear();
    
  }
}
