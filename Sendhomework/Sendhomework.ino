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
  * Date[now]: 18/12/2014 [dd/mm/yyyy]                                          *
  *******************************************************************************/ 
  /******************************* Include Library ******************************/
  #include <LiquidCrystal.h>
  #include <Wire.h>
  #include <Keypad.h>
  #include <Password.h>
  #include <EEPROM.h>        // Mega2560 4KB have 0 - 2047 address
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
  
  /*********************** Create Keypad and Password ***************************/
  int locked = 1; 
  int passinput = 0;
  long ledflashvar = 0;
  long ledflashtime = 300;  
  int lockedled = 5;
  int unlockedled = 6;
  const byte ROWS = 4;   // Four Rows
  const byte COLS = 4;  //  Four Columns
  Password password = Password("A");  // Chang your password
  
  // Define the Keymap
  char keys[ROWS][COLS] = {  
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}  
  };
  
  byte rowPins[ROWS] = { 50,51,52,53 };  
  byte colPins[COLS] = { 46,47,48,49, };
  
  // Create the Keypad
  Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
  
  /******************************** Variable ************************************/
  int _box1hour = 0, _box1minute = 0;
  int _box2hour = 0, _box2minute = 0;
  int _box3hour = 0, _box3minute = 0;
  int _box4hour = 0, _box4minute = 0;
  int box1=0, box2=0, box3=0, box4=0;
  int a_tens_hour = 0, a_unit_hour = 0, a_tens_minute = 0, a_unit_minute = 0;
  int b_tens_hour = 0, b_unit_hour = 0, b_tens_minute = 0, b_unit_minute = 0;
  int c_tens_hour = 0, c_unit_hour = 0, c_tens_minute = 0, c_unit_minute = 0;
  int d_tens_hour = 0, d_unit_hour = 0, d_tens_minute = 0, d_unit_minute = 0;
  int menu = 0;
  int allkeypad = 0, asterisk = 0, hashtag  = 0;
  int time_hour_box1 = 0, time_minute_box1 = 0;
  
  
  void setup()
  {
    lcd.begin(16,4);  
    Wire.begin();
    Serial.begin(19200);
    
    pinMode(lockedled, OUTPUT);
    pinMode(unlockedled, OUTPUT);
    
    digitalWrite(lockedled, 1);
    digitalWrite(unlockedled, 0);
    
    //setDateTime();  // when you want to adjust time 
    
  }
  
  void loop()
  {
    lcd.home();
    lcd.print(" Project_RMUTL  ");
    lcd.setCursor(0, 1);
    lcd.print("Send_homework..!");
    printDateTime();

/// Enter to mode working
    input_password();
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
    lcd.print(" : ");  
    lcd.print(_monthDay);
    lcd.print("/");
    lcd.print(_month);
    lcd.print("/");
    _year = _year + 2543;
    lcd.print(_year);
    lcd.print("  ");
    
    lcd.setCursor(0, 3);
    lcd.print("Time : ");
    lcd.print(_hour);
    lcd.print(".");
    lcd.print(_minute);
    lcd.print(".");
    lcd.print(_second);
    lcd.print("  ");
  }
  
  void readkeypad()
  {
    char key = keypad.getKey();
    if(key == '0') allkeypad = 0;
    if(key == '1') allkeypad = 1;
    if(key == '2') allkeypad = 2;
    if(key == '3') allkeypad = 3;
    if(key == '4') allkeypad = 4;
    if(key == '5') allkeypad = 5;
    if(key == '6') allkeypad = 6;
    if(key == '7') allkeypad = 7;
    if(key == '8') allkeypad = 8;
    if(key == '9') allkeypad = 9;

    if(key == '*') asterisk = 1;
    if(key == '#') hashtag  = 1;
  }
  
