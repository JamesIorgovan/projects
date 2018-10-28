//Name: James Iorgovan
//Date: Fall 2018
//Assignemnt: Lab 6 - Communication
//Description: Arduino will get user input for the date(mm/dd/yyyy) & time(hh/mm/ss) from the user via the serial monitor in the arduino 
//software. Will include: Date which includes day, month and year as well as Time which  includes hour, minutes and seconds.
//Assumptions: I think the tedious part will just be making all the conditions. I have to be able to say that certain months do not have
//certain days (such as Febuary which only has 28 days and 29 days after every 4 years).
//References: Code snippets - Lab 3, Lab 5
//                            http://arduino.cc/en/Reference/Serial#.UwYyzfldV8E
//                            http://arduino.cc/en/Serial/Available#.UwYy2PldV8E
//                            http://arduino.cc/en/Serial/ReadBytesUntil#.UwYy6_ldV8E
#include <Time.h>
#include <TimeLib.h>
#include <LiquidCrystal.h>


//-----------------------------------------------------------------------------------------
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int valid_month, valid_day, valid_year;       //initialize valid date
int valid_hour, valid_minute, valid_second;   //initialize valid time
int valid_date = 1, valid_time = 1;     //tracker to check if date and time are valid



//-----------------------------------------------------------------------------------------
void setup() {  
  lcd.begin(16, 2);
  Serial.begin(9600);
  int clear_buffer;


//-----------------------------------------------------------------------------------------
      //take user input for date
      Serial.println("Enter mm/dd/yyyy:");
      while(Serial.available() == 0){}
      valid_month = Serial.parseInt();
      valid_day = Serial.parseInt();
      valid_year = Serial.parseInt();

     
      //check if month input is valid
      if(valid_month < 1 || valid_month > 12){
        lcd.clear();
        Serial.print("INVALID MONTH");   //print to serial monitor
        lcd.print("INVALID MONTH");
      }

      //check if year input is valid (setTime lib min input is 1970)
      else if(valid_year < 1970){
      lcd.clear();
      Serial.print("INVALID YEAR");   //print to serial monitor
      lcd.print("INVALID YEAR");
        
      }
    
      //check if day input is valid
      else if(valid_day < 1 || valid_day > 31){
      lcd.clear();
      Serial.print("INVALID DAY");   //print to serial monitor
      lcd.print("INVALID DAY");
      }

       // check that Feburary does not have input more than 28 or less than 1
       else if(valid_month == 2){
           if (valid_day < 1 || valid_day > 28)
              lcd.clear();
              Serial.print("INVALID DAY");   //print to serial monitor
              lcd.print("INVALID DAY");
      }


       // check that the months with 30 days do not have input more than 30 or less than 1
       else if(valid_month == 4 || valid_month == 6 || valid_month == 9 || valid_month == 11){
           if (valid_day < 1 || valid_day > 30)
             lcd.clear();
      }

     // check that the months with 31 days do not have input more than 31 or less than 1
     else if(valid_month == 1 || valid_month == 3 || valid_month == 5 || valid_month == 7 || valid_month == 8 || valid_month == 10 || valid_month == 12){
          if (valid_day < 1 || valid_day > 31)
            lcd.clear();
      }

      while(Serial.available()){
        clear_buffer = Serial.parseInt();
      }


//-----------------------------------------------------------------------------------------      
      Serial.println("Enter hh/mm/ss:");
      while(Serial.available() == 0){}
      valid_hour = Serial.parseInt();
      valid_minute = Serial.parseInt();
      valid_second = Serial.parseInt();

      //check if hour input is valid
      if(valid_hour < 1 || valid_hour > 23){
      lcd.clear();
      Serial.print("INVALID HOUR");  //print to serial monitor
      lcd.print("INVALID HOUR");
      }

      //check if minute input is valid
      else if(valid_minute < 0 || valid_minute > 59){
      lcd.clear();
      Serial.print("INVALID MINUTE");   //print to serial monitor
      lcd.print("INVALID MINUTE");
      }

      //check if second input is valid
      else if(valid_second < 0 || valid_second > 59){   
      lcd.clear();
      Serial.print("INVALID SECOND");   //print to serial monitor
      lcd.print("INVALID SECOND");
      }

      //if both date and time are valid
      if(valid_time == 1 && valid_date == 1 ){   
       setTime(valid_hour, valid_minute, valid_second, valid_day, valid_month, valid_year);
      }
      


//-----------------------------------------------------------------------------------------
    //prints information to serial monitor
    Serial.println();
    Serial.print("Month: ");
    Serial.println(valid_month);
    Serial.print("Day: ");
    Serial.println(valid_day);    
    Serial.print("Year: ");
    Serial.println(valid_year);

    Serial.print("Hour: ");
    Serial.println(valid_hour);
    Serial.print("Minute: ");
    Serial.println(valid_minute);
    Serial.print("Second: ");
    Serial.println(valid_second);
    Serial.println();
}

//-----------------------------------------------------------------------------------------
void loop() {
  // check if either time or date are not valid
    if(valid_date == 0 || valid_time == 0){
      return;
    }

    //date
    lcd.setCursor(0,0);
    lcd.print("Date: ");
    lcd.setCursor(6,0);
    lcd.print( month());
    lcd.setCursor(8,0);
    lcd.print("/");
    lcd.setCursor(9,0);
    lcd.print( day());
    lcd.setCursor(11,0);
    lcd.print("/");
    lcd.setCursor(12,0);
    lcd.print( year());

    //time
    lcd.setCursor(0,1);
    lcd.print("Time: ");
    lcd.setCursor(6,1);
    lcd.print( hour());
    lcd.setCursor(8,1);
    lcd.print(":");
    lcd.setCursor(9,1);
    lcd.print( minute());
    lcd.setCursor(11,1);
    lcd.print(":");
    lcd.setCursor(12,1);
    lcd.print( second());

    delay(1000);
    lcd.clear();
  
}
