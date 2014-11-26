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
    now_datetime();
  
    //print the data from DS1307
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
  
  byte decToBcd(byte val)
  {
    // Convert normal decimal numbers to binary coded decimal
    return ( (val/10*16) + (val%10) );
  }
  
  byte bcdToDec(byte val)  
  {
    // Convert binary coded decimal to normal decimal numbers
    return ( (val/16*10) + (val%16) );
  }
  
  /****** Set Date Time ***********************************/
  void setDateTime()
  {
    /*******  Config to time *****************************/
    byte set_second =      0;    // Set Second 0-59
    byte set_minute =      26;   // Set Minute 0-59
    byte set_hour =        22;    // Set Hour   0-23
    byte set_weekDay =     4;    // Set Day of Week  1-7
    byte set_monthDay =    26;   // Set Day of Month 1-31
    byte set_month =       11;   // Set Month  1-12
    byte set_year  =       14;   // Set Year   0-99
    
    /*******************************************************
    * BIT7 | BIT6 | BIT5 | BIT4 | BIT3 | BIT2 | BIT1 | BIT0
    * ------------------------------------------------------
    * OUT  |  X   |  X   | SQWE |  X   |  X   | RS1  | RS0
    *  0   |  X   |  X   |  0   |  X   |  X   |  0   |  0
    ********************************************************/
    /* Comment :
        OUT  Mean  Output control level of the SQW out
        SQWE Mean  Square Wave Enable output depends upon the rs1 rs0 
        RS   Mean  Rate Select control square wave output when enable
                   |  RS1  RS0  SQWoutput  |
                   |   0    0      1 Hz    |
                   |   0    1   4.096 kHz  |
                   |   1    0   8.192 kHz  |
                   |   1    1  32.768 kHz  |  */
    byte control  =    0b10010011; 

    byte  d1;
    byte  d2;
  
    // Write to address ds1307
    Wire.beginTransmission(DS1307_ADDRESS);  
    Wire.write(zero);  //stop Oscillator
    Wire.write(decToBcd(set_second));
    Wire.write(decToBcd(set_minute));
    Wire.write(decToBcd(set_hour));
    Wire.write(decToBcd(set_weekDay));
    Wire.write(decToBcd(set_monthDay));
    Wire.write(decToBcd(set_month));
    Wire.write(decToBcd(set_year));
    Wire.write(control);
    Wire.write(12);    //data address 08
    Wire.write(34);    //data address 09
    Wire.write(zero);  //start 
    Wire.endTransmission();
  
  }
  
  void now_datetime()
  {
    //  Read from address ds1307
    Wire.beginTransmission(DS1307_ADDRESS);
    Wire.write(zero);
    Wire.endTransmission();
    
    Wire.requestFrom(DS1307_ADDRESS, 10);
    _second = bcdToDec(Wire.read());
    _minute = bcdToDec(Wire.read());
    _hour = bcdToDec(Wire.read() &0b111111);  // 24 hour time
    _weekDay = bcdToDec(Wire.read());         // 1-7 ->Sunday - Saturday
    _monthDay = bcdToDec(Wire.read());
    _month = bcdToDec(Wire.read());
    _year = bcdToDec(Wire.read());
    control = Wire.read();
    //d1 = Wire.read();
    //d2 = Wire.read();
  }
