//////////////////////////////  Setting time cound box A //////////////////////////////  
  void setting_timeA()
  {
sethourA:             
    a_tens_hour = 0; 
    a_unit_hour = 0;
    
    lcd.setCursor(0, 0);
    lcd.print("Setting Time    "); 
    lcd.setCursor(0, 1);
    lcd.print("Box A           ");
    
    lcd.setCursor(0, 2);
    lcd.print("Time : ");
    lcd.print(_hour);
    lcd.print(":");
    lcd.print(_minute);
    lcd.print(":");
    lcd.print(_second);
    lcd.print("   ");
       
    lcd.setCursor(0, 3);
    lcd.print("Set  : ");
    if(EEPROM.read(10) < 10) lcd.print("0");
    lcd.print(EEPROM.read(10));  //readhour_a 
    lcd.print(":");
    if(EEPROM.read(11) < 10) lcd.print("0");
    lcd.print(EEPROM.read(11));  //readminute_a
    lcd.print("   ");

    box1 = 2;
    while(box1 == 2)  { 
      now_datetime();
      lcd.setCursor(0, 2);
      lcd.print("Time : ");
      lcd.print(_hour);
      lcd.print(":");
      lcd.print(_minute);
      lcd.print(":");
      lcd.print(_second);
      lcd.print("   ");
       
      lcd.setCursor(0, 3);
      lcd.print("Set  : ");
      lcd.blink();
      delay(100);
       
      char key = keypad.getKey();
      switch (key)  {
        case '0' : lcd.print("0");  a_tens_hour = 0;  break;
        case '1' : lcd.print("1");  a_tens_hour = 1;  break;
        case '2' : lcd.print("2");  a_tens_hour = 2;  break;
        case '3' : lcd.print("3");  a_tens_hour = 3;  break;
        case '4' : lcd.print("4");  a_tens_hour = 4;  break;
        case '5' : lcd.print("5");  a_tens_hour = 5;  break;
        case '6' : lcd.print("6");  a_tens_hour = 6;  break;
        case '7' : lcd.print("7");  a_tens_hour = 7;  break;
        case '8' : lcd.print("8");  a_tens_hour = 8;  break;
        case '9' : lcd.print("9");  a_tens_hour = 9;  break;
        case '#' : menu = 0;        box1 = 0;         break;  // ออกจากการตั้งเวลา
        case '*' : box1 = 3;                          break;  // ตกลง / ยืนยัน    
       }
     }  // end 
     
    while(box1 == 3)  {
      now_datetime();
      lcd.setCursor(0, 2);
      lcd.print("Time : ");
      lcd.print(_hour);
      lcd.print(":");
      lcd.print(_minute);
      lcd.print(":");
      lcd.print(_second);
      lcd.print("   ");
       
      lcd.setCursor(0, 3);
      lcd.print("Set  : ");
      lcd.print(a_tens_hour); 
      lcd.blink();
      delay(100);
       
      char key = keypad.getKey();
      switch (key)  {
        case '0' : lcd.print("0"); a_unit_hour = 0; break;
        case '1' : lcd.print("1"); a_unit_hour = 1; break;
        case '2' : lcd.print("2"); a_unit_hour = 2; break;
        case '3' : lcd.print("3"); a_unit_hour = 3; break;
        case '4' : lcd.print("4"); a_unit_hour = 4; break;
        case '5' : lcd.print("5"); a_unit_hour = 5; break;
        case '6' : lcd.print("6"); a_unit_hour = 6; break;
        case '7' : lcd.print("7"); a_unit_hour = 7; break;
        case '8' : lcd.print("8"); a_unit_hour = 8; break;
        case '9' : lcd.print("9"); a_unit_hour = 9; break;
        case '#' : menu = 0;       box1 = 0;        break;  // ออกจากการตั้งเวลา
         
        case '*' : 
          time_hour_box1 = a_tens_hour*10 + a_unit_hour; //asterisk = 0;   
          if(time_hour_box1 >= 24)  {
            goto sethourA;
          }
          else  {
            box1 = 4;
          }
          break;
      }  
    }  //end
    
setminuteA:  
    a_tens_minute = 0;
    a_unit_minute = 0;
    box1 = 4;
    while(box1 == 4)  {
      now_datetime();
      lcd.setCursor(0, 2);
      lcd.print("Time : ");
      lcd.print(_hour);
      lcd.print(":");
      lcd.print(_minute);
      lcd.print(":");
      lcd.print(_second);
      lcd.print("   ");
      
      lcd.setCursor(0, 3);
      lcd.print("Set  : ");
      if(time_hour_box1 <= 10)  lcd.print("0");
      lcd.print(time_hour_box1);   
      lcd.print(":");
      lcd.blink();
      delay(100);
       
      char key = keypad.getKey();
      switch (key)  {
        case '0' : lcd.print("0"); a_tens_minute = 0; break;
        case '1' : lcd.print("1"); a_tens_minute = 1; break;
        case '2' : lcd.print("2"); a_tens_minute = 2; break;
        case '3' : lcd.print("3"); a_tens_minute = 3; break;
        case '4' : lcd.print("4"); a_tens_minute = 4; break;
        case '5' : lcd.print("5"); a_tens_minute = 5; break;
        case '6' : lcd.print("6"); a_tens_minute = 6; break;
        case '7' : lcd.print("7"); a_tens_minute = 7; break;
        case '8' : lcd.print("8"); a_tens_minute = 8; break;
        case '9' : lcd.print("9"); a_tens_minute = 9; break;
        case '#' : menu = 0;       box1 = 0;          break;  // ออกจากการตั้งเวลา
        case '*' : box1 = 5;                          break;  // ตกลง / ยืนยัน       
      }
    }  // end
     
    while(box1 == 5)  {
      now_datetime();
      lcd.setCursor(0, 2);
      lcd.print("Time : ");
      lcd.print(_hour);
      lcd.print(":");
      lcd.print(_minute);
      lcd.print(":");
      lcd.print(_second);
      lcd.print("   ");
       
      lcd.setCursor(0, 3);
      lcd.print("Set  : ");
      if(time_hour_box1 < 9) lcd.print("0");
      lcd.print(time_hour_box1);   
      lcd.print(":");
      lcd.print(a_tens_minute);
      lcd.blink();
      delay(100);
       
      char key = keypad.getKey();
      switch (key)  {
        case '0' : lcd.print("0"); a_unit_minute = 0; break;
        case '1' : lcd.print("1"); a_unit_minute = 1; break;
        case '2' : lcd.print("2"); a_unit_minute = 2; break;
        case '3' : lcd.print("3"); a_unit_minute = 3; break;
        case '4' : lcd.print("4"); a_unit_minute = 4; break;
        case '5' : lcd.print("5"); a_unit_minute = 5; break;
        case '6' : lcd.print("6"); a_unit_minute = 6; break;
        case '7' : lcd.print("7"); a_unit_minute = 7; break;
        case '8' : lcd.print("8"); a_unit_minute = 8; break;
        case '9' : lcd.print("9"); a_unit_minute = 9; break;
        case '#' : menu = 0;       box1 = 0;          break;  // ออกจากการตั้งเวลา
         
        case '*' :
          time_minute_box1 = a_tens_minute*10 + a_unit_minute;
          if(time_minute_box1 > 59)  {
            goto setminuteA;
          }
          else  {
            lcd.clear();         
            lcd.home();
            lcd.print("Setting Time    "); 
            lcd.setCursor(0, 1);
            lcd.print("Box A           ");
            lcd.setCursor(0, 2);
            lcd.print("Time = ");
            if(time_hour_box1 <= 10)  lcd.print("0");
            lcd.print(time_hour_box1);
            lcd.print(":");
            if(time_minute_box1 <= 10)  lcd.print("0");
            lcd.print(time_minute_box1);
            lcd.setCursor(0, 3);
            lcd.print("    Success !   ");
           
            EEPROM.write(10, time_hour_box1);
            EEPROM.write(11, time_minute_box1);
           
            delay(3000);
            box1 = 0;
          }
          break;  // ตกลง / ยืนยัน       
      }
     }  // end  
  }  // end set time box A

  
//////////////////////////////  Setting time cound box B //////////////////////////////
  void setting_timeB()
  {
sethourB:             
    b_tens_hour = 0; 
    b_unit_hour = 0;
    
    lcd.setCursor(0, 0);
    lcd.print("Setting Time    "); 
    lcd.setCursor(0, 1);
    lcd.print("Box B           ");
     
    lcd.setCursor(0, 2);
    lcd.print("Time : ");
    lcd.print(_hour);
    lcd.print(":");
    lcd.print(_minute);
    lcd.print(":");
    lcd.print(_second);
    lcd.print("   ");
       
    lcd.setCursor(0, 3);
    lcd.print("Set  : ");
    if(EEPROM.read(12) < 10) lcd.print("0");
    lcd.print(EEPROM.read(12));  //readhour_a 
    lcd.print(":");
    if(EEPROM.read(13) < 10) lcd.print("0");
    lcd.print(EEPROM.read(13));  //readminute_a
    lcd.print("   ");

    box2 = 2;
    while(box2 == 2)  { 
      now_datetime();
      lcd.setCursor(0, 2);
      lcd.print("Time : ");
      lcd.print(_hour);
      lcd.print(":");
      lcd.print(_minute);
      lcd.print(":");
      lcd.print(_second);
      lcd.print("   ");
       
      lcd.setCursor(0, 3);
      lcd.print("Set  : ");
      lcd.blink();
      delay(100);
       
      char key = keypad.getKey();
      switch (key)  {
        case '0' : lcd.print("0");  b_tens_hour = 0;  break;
        case '1' : lcd.print("1");  b_tens_hour = 1;  break;
        case '2' : lcd.print("2");  b_tens_hour = 2;  break;
        case '3' : lcd.print("3");  b_tens_hour = 3;  break;
        case '4' : lcd.print("4");  b_tens_hour = 4;  break;
        case '5' : lcd.print("5");  b_tens_hour = 5;  break;
        case '6' : lcd.print("6");  b_tens_hour = 6;  break;
        case '7' : lcd.print("7");  b_tens_hour = 7;  break;
        case '8' : lcd.print("8");  b_tens_hour = 8;  break;
        case '9' : lcd.print("9");  b_tens_hour = 9;  break;
        case '#' : menu = 0;        box2 = 0;         break;  // ออกจากการตั้งเวลา
        case '*' : box2 = 3;                          break;  // ตกลง / ยืนยัน    
       }
     }  // end 
     
    while(box2 == 3)  {
      now_datetime();
      lcd.setCursor(0, 2);
      lcd.print("Time : ");
      lcd.print(_hour);
      lcd.print(":");
      lcd.print(_minute);
      lcd.print(":");
      lcd.print(_second);
      lcd.print("   ");
       
      lcd.setCursor(0, 3);
      lcd.print("Set  : ");
      lcd.print(b_tens_hour); 
      lcd.blink();
      delay(100);
       
      char key = keypad.getKey();
      switch (key)  {
        case '0' : lcd.print("0"); b_unit_hour = 0; break;
        case '1' : lcd.print("1"); b_unit_hour = 1; break;
        case '2' : lcd.print("2"); b_unit_hour = 2; break;
        case '3' : lcd.print("3"); b_unit_hour = 3; break;
        case '4' : lcd.print("4"); b_unit_hour = 4; break;
        case '5' : lcd.print("5"); b_unit_hour = 5; break;
        case '6' : lcd.print("6"); b_unit_hour = 6; break;
        case '7' : lcd.print("7"); b_unit_hour = 7; break;
        case '8' : lcd.print("8"); b_unit_hour = 8; break;
        case '9' : lcd.print("9"); b_unit_hour = 9; break;
        case '#' : menu = 0;       box2 = 0;        break;  // ออกจากการตั้งเวลา
         
        case '*' : 
          time_hour_box2 = b_tens_hour*10 + b_unit_hour; //asterisk = 0;   
          if(time_hour_box2 >= 24)  {
            goto sethourB;
          }
          else  {
            box2 = 4;
          }
          break;
      }  
    }  //end
    
setminuteB:  
    b_tens_minute = 0;
    b_unit_minute = 0;
    box2 = 4;
    while(box2 == 4)  {
      now_datetime();
      lcd.setCursor(0, 2);
      lcd.print("Time : ");
      lcd.print(_hour);
      lcd.print(":");
      lcd.print(_minute);
      lcd.print(":");
      lcd.print(_second);
      lcd.print("   ");
      
      lcd.setCursor(0, 3);
      lcd.print("Set  : ");
      if(time_hour_box2 <= 10)  lcd.print("0");
      lcd.print(time_hour_box2);   
      lcd.print(":");
      lcd.blink();
      delay(100);
       
      char key = keypad.getKey();
      switch (key)  {
        case '0' : lcd.print("0"); b_tens_minute = 0; break;
        case '1' : lcd.print("1"); b_tens_minute = 1; break;
        case '2' : lcd.print("2"); b_tens_minute = 2; break;
        case '3' : lcd.print("3"); b_tens_minute = 3; break;
        case '4' : lcd.print("4"); b_tens_minute = 4; break;
        case '5' : lcd.print("5"); b_tens_minute = 5; break;
        case '6' : lcd.print("6"); b_tens_minute = 6; break;
        case '7' : lcd.print("7"); b_tens_minute = 7; break;
        case '8' : lcd.print("8"); b_tens_minute = 8; break;
        case '9' : lcd.print("9"); b_tens_minute = 9; break;
        case '#' : menu = 0;       box2 = 0;          break;  // ออกจากการตั้งเวลา
        case '*' : box2 = 5;                          break;  // ตกลง / ยืนยัน       
      }
    }  // end
     
    while(box2 == 5)  {
      now_datetime();
      lcd.setCursor(0, 2);
      lcd.print("Time : ");
      lcd.print(_hour);
      lcd.print(":");
      lcd.print(_minute);
      lcd.print(":");
      lcd.print(_second);
      lcd.print("   ");
       
      lcd.setCursor(0, 3);
      lcd.print("Set  : ");
      if(time_hour_box2 < 9) lcd.print("0");
      lcd.print(time_hour_box2);   
      lcd.print(":");
      lcd.print(b_tens_minute);
      lcd.blink();
      delay(100);
       
      char key = keypad.getKey();
      switch (key)  {
        case '0' : lcd.print("0"); b_unit_minute = 0; break;
        case '1' : lcd.print("1"); b_unit_minute = 1; break;
        case '2' : lcd.print("2"); b_unit_minute = 2; break;
        case '3' : lcd.print("3"); b_unit_minute = 3; break;
        case '4' : lcd.print("4"); b_unit_minute = 4; break;
        case '5' : lcd.print("5"); b_unit_minute = 5; break;
        case '6' : lcd.print("6"); b_unit_minute = 6; break;
        case '7' : lcd.print("7"); b_unit_minute = 7; break;
        case '8' : lcd.print("8"); b_unit_minute = 8; break;
        case '9' : lcd.print("9"); b_unit_minute = 9; break;
        case '#' : menu = 0;       box2 = 0;          break;  // ออกจากการตั้งเวลา
         
        case '*' :
          time_minute_box2 = b_tens_minute*10 + b_unit_minute;
          if(time_minute_box2 > 59)  {
            goto setminuteB;
          }
          else  {
            lcd.clear();         
            lcd.home();
            lcd.print("Setting Time    "); 
            lcd.setCursor(0, 1);
            lcd.print("Box B           ");
            lcd.setCursor(0, 2);
            lcd.print("Time = ");
            if(time_hour_box2 <= 10)  lcd.print("0");
            lcd.print(time_hour_box2);
            lcd.print(":");
            if(time_minute_box2 <= 10)  lcd.print("0");
            lcd.print(time_minute_box2);
            lcd.setCursor(0, 3);
            lcd.print("    Success !   ");
           
            EEPROM.write(12, time_hour_box2);
            EEPROM.write(13, time_minute_box2);
           
            delay(3000);
            box2 = 0;
          }
          break;  // ตกลง / ยืนยัน       
      }
     }  // end  
  }  // end set time box B
  
//////////////////////////////  Setting time cound box C //////////////////////////////
  void setting_timeC()
  {
sethourC:             
    c_tens_hour = 0; 
    c_unit_hour = 0;
    
    lcd.setCursor(0, 0);
    lcd.print("Setting Time    "); 
    lcd.setCursor(0, 1);
    lcd.print("Box C           ");
    
    lcd.setCursor(0, 2);
    lcd.print("Time : ");
    lcd.print(_hour);
    lcd.print(":");
    lcd.print(_minute);
    lcd.print(":");
    lcd.print(_second);
    lcd.print("   ");
       
    lcd.setCursor(0, 3);
    lcd.print("Set  : ");
    if(EEPROM.read(14) < 10) lcd.print("0");
    lcd.print(EEPROM.read(14));  //readhour_a 
    lcd.print(":");
    if(EEPROM.read(15) < 10) lcd.print("0");
    lcd.print(EEPROM.read(15));  //readminute_a
    lcd.print("   ");

    box3 = 2;
    while(box3 == 2)  { 
      now_datetime();
      lcd.setCursor(0, 2);
      lcd.print("Time : ");
      lcd.print(_hour);
      lcd.print(":");
      lcd.print(_minute);
      lcd.print(":");
      lcd.print(_second);
      lcd.print("   ");
       
      lcd.setCursor(0, 3);
      lcd.print("Set  : ");
      lcd.blink();
      delay(100);
       
      char key = keypad.getKey();
      switch (key)  {
        case '0' : lcd.print("0");  c_tens_hour = 0;  break;
        case '1' : lcd.print("1");  c_tens_hour = 1;  break;
        case '2' : lcd.print("2");  c_tens_hour = 2;  break;
        case '3' : lcd.print("3");  c_tens_hour = 3;  break;
        case '4' : lcd.print("4");  c_tens_hour = 4;  break;
        case '5' : lcd.print("5");  c_tens_hour = 5;  break;
        case '6' : lcd.print("6");  c_tens_hour = 6;  break;
        case '7' : lcd.print("7");  c_tens_hour = 7;  break;
        case '8' : lcd.print("8");  c_tens_hour = 8;  break;
        case '9' : lcd.print("9");  c_tens_hour = 9;  break;
        case '#' : menu = 0;        box3 = 0;         break;  // ออกจากการตั้งเวลา
        case '*' : box3 = 3;                          break;  // ตกลง / ยืนยัน    
       }
     }  // end 
     
    while(box3 == 3)  {
      now_datetime();
      lcd.setCursor(0, 2);
      lcd.print("Time : ");
      lcd.print(_hour);
      lcd.print(":");
      lcd.print(_minute);
      lcd.print(":");
      lcd.print(_second);
      lcd.print("   ");
       
      lcd.setCursor(0, 3);
      lcd.print("Set  : ");
      lcd.print(c_tens_hour); 
      lcd.blink();
      delay(100);
       
      char key = keypad.getKey();
      switch (key)  {
        case '0' : lcd.print("0"); c_unit_hour = 0; break;
        case '1' : lcd.print("1"); c_unit_hour = 1; break;
        case '2' : lcd.print("2"); c_unit_hour = 2; break;
        case '3' : lcd.print("3"); c_unit_hour = 3; break;
        case '4' : lcd.print("4"); c_unit_hour = 4; break;
        case '5' : lcd.print("5"); c_unit_hour = 5; break;
        case '6' : lcd.print("6"); c_unit_hour = 6; break;
        case '7' : lcd.print("7"); c_unit_hour = 7; break;
        case '8' : lcd.print("8"); c_unit_hour = 8; break;
        case '9' : lcd.print("9"); c_unit_hour = 9; break;
        case '#' : menu = 0;       box3 = 0;        break;  // ออกจากการตั้งเวลา
         
        case '*' : 
          time_hour_box3 = c_tens_hour*10 + c_unit_hour; //asterisk = 0;   
          if(time_hour_box3 >= 24)  {
            goto sethourC;
          }
          else  {
            box3 = 4;
          }
          break;
      }  
    }  //end
    
setminuteC:  
    c_tens_minute = 0;
    c_unit_minute = 0;
    box3 = 4;
    while(box3 == 4)  {
      now_datetime();
      lcd.setCursor(0, 2);
      lcd.print("Time : ");
      lcd.print(_hour);
      lcd.print(":");
      lcd.print(_minute);
      lcd.print(":");
      lcd.print(_second);
      lcd.print("   ");
      
      lcd.setCursor(0, 3);
      lcd.print("Set  : ");
      if(time_hour_box3 <= 10)  lcd.print("0");
      lcd.print(time_hour_box3);   
      lcd.print(":");
      lcd.blink();
      delay(100);
       
      char key = keypad.getKey();
      switch (key)  {
        case '0' : lcd.print("0"); c_tens_minute = 0; break;
        case '1' : lcd.print("1"); c_tens_minute = 1; break;
        case '2' : lcd.print("2"); c_tens_minute = 2; break;
        case '3' : lcd.print("3"); c_tens_minute = 3; break;
        case '4' : lcd.print("4"); c_tens_minute = 4; break;
        case '5' : lcd.print("5"); c_tens_minute = 5; break;
        case '6' : lcd.print("6"); c_tens_minute = 6; break;
        case '7' : lcd.print("7"); c_tens_minute = 7; break;
        case '8' : lcd.print("8"); c_tens_minute = 8; break;
        case '9' : lcd.print("9"); c_tens_minute = 9; break;
        case '#' : menu = 0;       box3 = 0;          break;  // ออกจากการตั้งเวลา
        case '*' : box3 = 5;                          break;  // ตกลง / ยืนยัน       
      }
    }  // end
     
    while(box3 == 5)  {
      now_datetime();
      lcd.setCursor(0, 2);
      lcd.print("Time : ");
      lcd.print(_hour);
      lcd.print(":");
      lcd.print(_minute);
      lcd.print(":");
      lcd.print(_second);
      lcd.print("   ");
       
      lcd.setCursor(0, 3);
      lcd.print("Set  : ");
      if(time_hour_box3 < 9) lcd.print("0");
      lcd.print(time_hour_box3);   
      lcd.print(":");
      lcd.print(c_tens_minute);
      lcd.blink();
      delay(100);
       
      char key = keypad.getKey();
      switch (key)  {
        case '0' : lcd.print("0"); c_unit_minute = 0; break;
        case '1' : lcd.print("1"); c_unit_minute = 1; break;
        case '2' : lcd.print("2"); c_unit_minute = 2; break;
        case '3' : lcd.print("3"); c_unit_minute = 3; break;
        case '4' : lcd.print("4"); c_unit_minute = 4; break;
        case '5' : lcd.print("5"); c_unit_minute = 5; break;
        case '6' : lcd.print("6"); c_unit_minute = 6; break;
        case '7' : lcd.print("7"); c_unit_minute = 7; break;
        case '8' : lcd.print("8"); c_unit_minute = 8; break;
        case '9' : lcd.print("9"); c_unit_minute = 9; break;
        case '#' : menu = 0;       box3 = 0;          break;  // ออกจากการตั้งเวลา
         
        case '*' :
          time_minute_box3 = c_tens_minute*10 + c_unit_minute;
          if(time_minute_box3 > 59)  {
            goto setminuteC;
          }
          else  {
            lcd.clear();         
            lcd.home();
            lcd.print("Setting Time    "); 
            lcd.setCursor(0, 1);
            lcd.print("Box C           ");
            lcd.setCursor(0, 2);
            lcd.print("Time = ");
            if(time_hour_box3 <= 10)  lcd.print("0");
            lcd.print(time_hour_box3);
            lcd.print(":");
            if(time_minute_box3 <= 10)  lcd.print("0");
            lcd.print(time_minute_box3);
            lcd.setCursor(0, 3);
            lcd.print("    Success !   ");
           
            EEPROM.write(14, time_hour_box3);
            EEPROM.write(15, time_minute_box3);
           
            delay(3000);
            box3 = 0;
          }
          break;  // ตกลง / ยืนยัน       
      }
     }  // end  
  }  // end set time box D
  
  
//////////////////////////////  Setting time cound box D //////////////////////////////  
  void setting_timeD()
  {
sethourD:             
    d_tens_hour = 0; 
    d_unit_hour = 0;
    
    lcd.setCursor(0, 0);
    lcd.print("Setting Time    "); 
    lcd.setCursor(0, 1);
    lcd.print("Box D           ");
    
    lcd.setCursor(0, 2);
    lcd.print("Time : ");
    lcd.print(_hour);
    lcd.print(":");
    lcd.print(_minute);
    lcd.print(":");
    lcd.print(_second);
    lcd.print("   ");
       
    lcd.setCursor(0, 3);
    lcd.print("Set  : ");
    if(EEPROM.read(16) < 10) lcd.print("0");
    lcd.print(EEPROM.read(16));  //readhour_a 
    lcd.print(":");
    if(EEPROM.read(17) < 10) lcd.print("0");
    lcd.print(EEPROM.read(17));  //readminute_a
    lcd.print("   ");

    box4 = 2;
    while(box4 == 2)  { 
      now_datetime();
      lcd.setCursor(0, 2);
      lcd.print("Time : ");
      lcd.print(_hour);
      lcd.print(":");
      lcd.print(_minute);
      lcd.print(":");
      lcd.print(_second);
      lcd.print("   ");
       
      lcd.setCursor(0, 3);
      lcd.print("Set  : ");
      lcd.blink();
      delay(100);
       
      char key = keypad.getKey();
      switch (key)  {
        case '0' : lcd.print("0");  d_tens_hour = 0;  break;
        case '1' : lcd.print("1");  d_tens_hour = 1;  break;
        case '2' : lcd.print("2");  d_tens_hour = 2;  break;
        case '3' : lcd.print("3");  d_tens_hour = 3;  break;
        case '4' : lcd.print("4");  d_tens_hour = 4;  break;
        case '5' : lcd.print("5");  d_tens_hour = 5;  break;
        case '6' : lcd.print("6");  d_tens_hour = 6;  break;
        case '7' : lcd.print("7");  d_tens_hour = 7;  break;
        case '8' : lcd.print("8");  d_tens_hour = 8;  break;
        case '9' : lcd.print("9");  d_tens_hour = 9;  break;
        case '#' : menu = 0;        box4 = 0;         break;  // ออกจากการตั้งเวลา
        case '*' : box4 = 3;                          break;  // ตกลง / ยืนยัน    
       }
     }  // end 
     
    while(box4 == 3)  {
      now_datetime();
      lcd.setCursor(0, 2);
      lcd.print("Time : ");
      lcd.print(_hour);
      lcd.print(":");
      lcd.print(_minute);
      lcd.print(":");
      lcd.print(_second);
      lcd.print("   ");
       
      lcd.setCursor(0, 3);
      lcd.print("Set  : ");
      lcd.print(d_tens_hour); 
      lcd.blink();
      delay(100);
       
      char key = keypad.getKey();
      switch (key)  {
        case '0' : lcd.print("0"); d_unit_hour = 0; break;
        case '1' : lcd.print("1"); d_unit_hour = 1; break;
        case '2' : lcd.print("2"); d_unit_hour = 2; break;
        case '3' : lcd.print("3"); d_unit_hour = 3; break;
        case '4' : lcd.print("4"); d_unit_hour = 4; break;
        case '5' : lcd.print("5"); d_unit_hour = 5; break;
        case '6' : lcd.print("6"); d_unit_hour = 6; break;
        case '7' : lcd.print("7"); d_unit_hour = 7; break;
        case '8' : lcd.print("8"); d_unit_hour = 8; break;
        case '9' : lcd.print("9"); d_unit_hour = 9; break;
        case '#' : menu = 0;       box4 = 0;        break;  // ออกจากการตั้งเวลา
         
        case '*' : 
          time_hour_box4 = d_tens_hour*10 + d_unit_hour; //asterisk = 0;   
          if(time_hour_box4 >= 24)  {
            goto sethourD;
          }
          else  {
            box4 = 4;
          }
          break;
      }  
    }  //end
    
setminuteD:  
    d_tens_minute = 0;
    d_unit_minute = 0;
    box4 = 4;
    while(box4 == 4)  {
      now_datetime();
      lcd.setCursor(0, 2);
      lcd.print("Time : ");
      lcd.print(_hour);
      lcd.print(":");
      lcd.print(_minute);
      lcd.print(":");
      lcd.print(_second);
      lcd.print("   ");
      
      lcd.setCursor(0, 3);
      lcd.print("Set  : ");
      if(time_hour_box4 <= 10)  lcd.print("0");
      lcd.print(time_hour_box4);   
      lcd.print(":");
      lcd.blink();
      delay(100);
       
      char key = keypad.getKey();
      switch (key)  {
        case '0' : lcd.print("0"); d_tens_minute = 0; break;
        case '1' : lcd.print("1"); d_tens_minute = 1; break;
        case '2' : lcd.print("2"); d_tens_minute = 2; break;
        case '3' : lcd.print("3"); d_tens_minute = 3; break;
        case '4' : lcd.print("4"); d_tens_minute = 4; break;
        case '5' : lcd.print("5"); d_tens_minute = 5; break;
        case '6' : lcd.print("6"); d_tens_minute = 6; break;
        case '7' : lcd.print("7"); d_tens_minute = 7; break;
        case '8' : lcd.print("8"); d_tens_minute = 8; break;
        case '9' : lcd.print("9"); d_tens_minute = 9; break;
        case '#' : menu = 0;       box4 = 0;          break;  // ออกจากการตั้งเวลา
        case '*' : box4 = 5;                          break;  // ตกลง / ยืนยัน       
      }
    }  // end
     
    while(box4 == 5)  {
      now_datetime();
      lcd.setCursor(0, 2);
      lcd.print("Time : ");
      lcd.print(_hour);
      lcd.print(":");
      lcd.print(_minute);
      lcd.print(":");
      lcd.print(_second);
      lcd.print("   ");
       
      lcd.setCursor(0, 3);
      lcd.print("Set  : ");
      if(time_hour_box4 < 9) lcd.print("0");
      lcd.print(time_hour_box4);   
      lcd.print(":");
      lcd.print(d_tens_minute);
      lcd.blink();
      delay(100);
       
      char key = keypad.getKey();
      switch (key)  {
        case '0' : lcd.print("0"); d_unit_minute = 0; break;
        case '1' : lcd.print("1"); d_unit_minute = 1; break;
        case '2' : lcd.print("2"); d_unit_minute = 2; break;
        case '3' : lcd.print("3"); d_unit_minute = 3; break;
        case '4' : lcd.print("4"); d_unit_minute = 4; break;
        case '5' : lcd.print("5"); d_unit_minute = 5; break;
        case '6' : lcd.print("6"); d_unit_minute = 6; break;
        case '7' : lcd.print("7"); d_unit_minute = 7; break;
        case '8' : lcd.print("8"); d_unit_minute = 8; break;
        case '9' : lcd.print("9"); d_unit_minute = 9; break;
        case '#' : menu = 0;       box4 = 0;          break;  // ออกจากการตั้งเวลา
         
        case '*' :
          time_minute_box4 = d_tens_minute*10 + d_unit_minute;
          if(time_minute_box4 > 59)  {
            goto setminuteD;
          }
          else  {
            lcd.clear();         
            lcd.home();
            lcd.print("Setting Time    "); 
            lcd.setCursor(0, 1);
            lcd.print("Box D           ");
            lcd.setCursor(0, 2);
            lcd.print("Time = ");
            if(time_hour_box4 <= 10)  lcd.print("0");
            lcd.print(time_hour_box4);
            lcd.print(":");
            if(time_minute_box4 <= 10)  lcd.print("0");
            lcd.print(time_minute_box4);
            lcd.setCursor(0, 3);
            lcd.print("    Success !   ");
           
            EEPROM.write(16, time_hour_box4);
            EEPROM.write(17, time_minute_box4);
           
            delay(3000);
            box4 = 0;
          }
          break;  // ตกลง / ยืนยัน       
      }
     }  // end  
  }  // end set time box D
