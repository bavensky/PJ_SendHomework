  /*******************************************************************************
  * Project  : Send Homework                                                    *
  * Compiler : Arduino 1.5.5-r2                                                 *
  * Board    : Arduino Mega 2560                                                *
  * Device   : Tiny RTC I2C module                                              *
  *          : LCD 16x4                                                         *
  *          : Keypad 4x4 module                                                *
  *          : Sensor(IRsensor x 4) with opamp                                  *
  *          : Drive 7-segment (Max7219)                                        *
  * Link     : -                                                                * 
  * Author   : Bavensky :3                                                      *
  * E-Mail   : Aphirak_Sang-ngenchai@hotmail.com                                *
  * Date[now]: 29/01/2015 [dd/mm/yyyy]                                          *
  *******************************************************************************/ 
  /******************************* Include Library ******************************/
  #include <LiquidCrystal.h>
  #include "LedControl.h"
  #include <Wire.h>
  #include <stdio.h>
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
  /********************* Connect max7219 to arduino pin *************************/
  // arduino pin 4 is connected to the DataIn (1)
  // arduino pin 3 is connected to the CLK    (13)
  // arduino pin 2 is connected to LOAD       (12)
  LedControl segment = LedControl(4,  3,  2);
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
  int count_detect1 = 0;
  int count_detect2 = 0;
  int count_detect3 = 0;
  int count_detect4 = 0;
  // int allkeypad = 0, asterisk = 0, hashtag  = 0;
  
  int time_hour_box1 = 0, time_minute_box1 = 0;
  int time_hour_box2 = 0, time_minute_box2 = 0;
  int time_hour_box3 = 0, time_minute_box3 = 0;
  int time_hour_box4 = 0, time_minute_box4 = 0;

  int delaytime = 250;      //  หน่วงเวลาสำหรับการแสดงผล 7 segment
  /************************  Save to EEProm  ************************************/
  byte savehour_a;  byte  saveminute_a;
  byte savehour_b;  byte  saveminute_b;
  byte savehour_c;  byte  saveminute_c;
  byte savehour_d;  byte  saveminute_d; 
  
  //  Box A  //
  byte  readhour_a    = EEPROM.read(10);
  byte  readminute_a  = EEPROM.read(11);
  
  //  Box B  //
  byte  readhour_b    = EEPROM.read(12);
  byte  readminute_b  = EEPROM.read(13);
  
  //  Box C  //
  byte  readhour_c    = EEPROM.read(14);
  byte  readminute_c  = EEPROM.read(15);
  
  //  Box D  //
  byte  readhour_d    = EEPROM.read(16);
  byte  readminute_d  = EEPROM.read(17);
  
  /***************************  LDR Variable ************************************/
  //  Rang from sensor detect
  #define  DETECT  880
  
  //  Define Pin connect  //
  #define  SENSOR_BOX_A1  A8
  #define  SENSOR_BOX_A2  A9
  
  #define  SENSOR_BOX_B1  A10
  #define  SENSOR_BOX_B2  A11
  
  #define  SENSOR_BOX_C1  A12
  #define  SENSOR_BOX_C2  A13
  
  #define  SENSOR_BOX_D1  A14
  #define  SENSOR_BOX_D2  A15
  
  //  init variable from sensor  //
  int read_sensor_A1  =  0;
  int read_sensor_A2  =  0;
  
  int read_sensor_B1  =  0;
  int read_sensor_B2  =  0;
  
  int read_sensor_C1  =  0;
  int read_sensor_C2  =  0;
  
  int read_sensor_D1  =  0;
  int read_sensor_D2  =  0;
  
  //  sum book in box  
  int sum_boxa_tens = 0;
  int sum_boxa_units = 0;
  
  int sum_boxb_tens = 0;
  int sum_boxb_units = 0;
  
  int sum_boxc_tens = 0;
  int sum_boxc_units = 0;
  
  int sum_boxd_tens = 0;
  int sum_boxd_units = 0;
  /**************************** End Variable ************************************/
  
  void setup()
  {
    lcd.begin(16,4);  
    Wire.begin();
    Serial.begin(19200);
    
    pinMode(lockedled, OUTPUT);
    pinMode(unlockedled, OUTPUT);
    
    //  config pin IR sensot input  //    
    pinMode(SENSOR_BOX_A1, INPUT);
    pinMode(SENSOR_BOX_A2, INPUT);
    pinMode(SENSOR_BOX_B1, INPUT);
    pinMode(SENSOR_BOX_B2, INPUT);
    pinMode(SENSOR_BOX_C1, INPUT);
    pinMode(SENSOR_BOX_C2, INPUT);
    pinMode(SENSOR_BOX_D1, INPUT);
    pinMode(SENSOR_BOX_D2, INPUT);
  
    digitalWrite(lockedled, 1);
    digitalWrite(unlockedled, 0);
    
    //  init max7219_7-segment  //
    segment.shutdown(0,false);
    segment.setIntensity(0,  3);     //  ความสว่าง  8 ปานกลาง
    segment.clearDisplay(0);         // เคลียหน้าจอ 7 segment

    //setDateTime();  // when you want to adjust time now
    
    // print eeprom to serial  //
      Serial.print(readhour_a);
      Serial.print("\t");
      Serial.print(readminute_a);
      Serial.print("\t");
      
      Serial.print(readhour_b);
      Serial.print("\t");
      Serial.print(readminute_b);
      Serial.print("\t");
      
      Serial.print(readhour_c);
      Serial.print("\t");
      Serial.print(readminute_c);
      Serial.print("\t");
      
      Serial.print(readhour_d);
      Serial.print("\t");
      Serial.print(readminute_d);
  }
  
  void loop()
  {
    lcd.home();
    lcd.print(" Project_RMUTL  ");
    lcd.setCursor(0, 1);
    lcd.print("Send_homework..!");
    printDateTime();
    
//  show 7 segment
   //showdisplay(0,  7,  5);    //  0  คือไอซีตัวที่ 1   /  7 คือหลักที่ 7  /  5 คือตัวเลขที่จะให้แสดง 0-15  
   
// Enter to mode working
    //input_password();

// Check book when student sent home work
    bookcount(); 
    
    read_irsensor();
    Serial.print("IRsensor  =  ");
    Serial.print(read_sensor_A1);
    Serial.print("    ");
    Serial.println(read_sensor_A2);
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
    if(_monthDay < 10) lcd.print("0");  
    lcd.print(_monthDay);
    lcd.print("/");
    if(_month < 10) lcd.print("0");  
    lcd.print(_month);
    lcd.print("/");
    _year = _year + 2543;
    lcd.print(_year);
    lcd.print("  ");
    
    lcd.setCursor(0, 3);
    lcd.print("Time : ");
    lcd.print(_hour);
    lcd.print(".");
    if(_minute < 10) lcd.print("0");
    lcd.print(_minute);
    lcd.print(".");
    if(_second < 10) lcd.print("0");
    lcd.print(_second);
    lcd.print("  ");
  }  
