  /*******************************************************************************
  * Project  : Send Homework                                                    *
  * Compiler : Arduino 1.5.5-r2                                                 *
  * Board    : Arduino Mega 2560                                                *
  * Device   : Tiny RTC I2C module                                              *
  *          : LCD 16x4                                                         *
  *          : Keypad 4x4 module                                                *
  *          : Sensor(LDR)                                                      *
  * Link     : -                                                                * 
  * Author   : Bavensky :3                                                      *
  * E-Mail   : Aphirak_Sang-ngenchai@hotmail.com                                *
  * Date     : 26/11/2014 [dd/mm/yyyy]                                          *
  *******************************************************************************/ 
  /******************************* Include Library ******************************/
  #include <LiquidCrystal.h>
  #include <Wire.h>
  
  /******************************* Define LCD Pin ******************************/
  #define  RS  12
  #define  EN  11
  #define  D4  10
  #define  D5  9
  #define  D6  8
  #define  D7  7
  LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
  
  /*********************** Initialize Real Time Clock****************************/
  #define DS1307_ADDRESS 0x68   // Address IC 0x68
  byte zero = 0x00; 
  int _weekDay, _second, _minute, _hour;
  int _monthDay, _month, _year; 
  int control, d1, d2; 
  
  void setup()
  {
    lcd.begin(16,4);  
    Wire.begin();
    Serial.begin(19200);
    //setDateTime();  // when you want to adjust time 
    
  }
  
  void loop()
  {
    lcd.home();
    lcd.print(" Project_RMUTL  ");
    lcd.setCursor(0, 1);
    lcd.print("Send_homework..!");
    printDateTime();
  }
   
  void printDateTime()
  {
    // Read time now
    now_datetime();
  
    // print the data from DS1307
    lcd.setCursor(0, 2);
    if(_weekDay == 1) lcd.print("Sun");
    if(_weekDay == 2) lcd.print("Mon");
    if(_weekDay == 3) lcd.print("Tue");
    if(_weekDay == 4) lcd.print("Wed");
    if(_weekDay == 5) lcd.print("Thu");
    if(_weekDay == 6) lcd.print("Fri");
    if(_weekDay == 7) lcd.print("Sat");
    lcd.print(" ");  
    lcd.print(_monthDay);
    lcd.print("/");
    lcd.print(_month);
    lcd.print("/");
    _year = _year + 2000;
    lcd.print(_year);
    lcd.print("  ");
    
    lcd.setCursor(0, 3);
    lcd.print("Time : ");
    lcd.print(_hour);
    lcd.print(":");
    lcd.print(_minute);
    lcd.print(":");
    lcd.print(_second);
    lcd.print("  ");
  }
  
  
