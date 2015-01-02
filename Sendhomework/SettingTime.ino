//////////////////////////////  Setting time cound box A //////////////////////////////  
  void setting_timeA()
  {
    lcd.setCursor(0, 0);
    lcd.print("Setting Time    "); 
    lcd.setCursor(0, 1);
    lcd.print("Box A           ");
    a_tens_hour = 0; 
    a_unit_hour = 0;
    a_tens_minute = 0;
    a_unit_minute = 0;

// set hour
    box1 = 2;
     while(box1 == 2)
     {
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
       lcd.print(a_tens_hour); 
       lcd.print(":");
       lcd.print(a_tens_minute);
       lcd.print(a_unit_minute);
       
       readkeypad();
       a_tens_hour = allkeypad * 10;
       if(asterisk == 1)
       {
         allkeypad = 0;
         asterisk = 0;
         box1 = 3;
       }
     } 
     
     while(box1 == 3)
     {
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
       lcd.print(a_tens_hour / 10); 
       lcd.blink();
       delay(100);
       lcd.print(a_unit_hour);     
       lcd.print(":");
       lcd.print(a_tens_minute);
       lcd.print(a_unit_minute);
       
       readkeypad();
       a_unit_hour = allkeypad * 1;
       if(asterisk == 1)
       {
         time_hour_box1 = a_tens_hour + a_unit_hour;
         allkeypad = 0; 
         asterisk = 0;
         box1 = 4;
       }
     }
// set minute
     while(box1 == 4)
     {
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
       lcd.print(time_hour_box1);   
       lcd.print(":");
       lcd.blink();
       delay(100);
       lcd.print(a_tens_minute);
              
       readkeypad();
       a_tens_minute = allkeypad * 10;
       if(asterisk == 1)
       {
         allkeypad = 0; 
         asterisk = 0;
         box1 = 5;
       }
     }
     while(box1 == 5)
     {
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
       lcd.print(time_hour_box1);   
       lcd.print(":");
       lcd.print(a_tens_minute / 10);
       lcd.blink();
       delay(100);
       lcd.print(a_unit_minute);
       
       readkeypad();
       a_unit_minute = allkeypad * 1;
       if(asterisk == 1)
       {
         allkeypad = 0; 
         asterisk = 0;
         time_minute_box1 = a_tens_minute + a_unit_minute;
        
         lcd.clear();         
         lcd.home();
         lcd.print("Setting Time    "); 
         lcd.setCursor(0, 1);
         lcd.print("Box A           ");
         lcd.setCursor(0, 2);
         lcd.print("Time = ");
         lcd.print(time_hour_box1);
         lcd.print(":");
         lcd.print(time_minute_box1);
         lcd.setCursor(0, 3);
         lcd.print("    Success !   ");
         delay(3000);
         box1 = 0;
       }   
     }  
  }
  

//////////////////////////////  Setting time cound box B //////////////////////////////
  void setting_timeB()
  { 
    now_datetime();
    lcd.setCursor(0, 0);
    lcd.print("Setting Time    ");
    
    lcd.setCursor(0, 1);
    lcd.print("Time : ");
    lcd.print(_hour);
    lcd.print(".");
    lcd.print(_minute);
    lcd.print(".");
    lcd.print(_second);
    lcd.print("  ");
  }


//////////////////////////////  Setting time cound box C //////////////////////////////  
  void setting_timeC()
  { 
    now_datetime();
    lcd.setCursor(0, 0);
    lcd.print("Setting Time    ");
    
    lcd.setCursor(0, 1);
    lcd.print("Time : ");
    lcd.print(_hour);
    lcd.print(".");
    lcd.print(_minute);
    lcd.print(".");
    lcd.print(_second);
    lcd.print("  ");
  }


//////////////////////////////  Setting time cound box D //////////////////////////////  
  void setting_timeD()
  { 
    now_datetime();
    lcd.setCursor(0, 0);
    lcd.print("Setting Time    ");
    
    lcd.setCursor(0, 1);
    lcd.print("Time : ");
    lcd.print(_hour);
    lcd.print(".");
    lcd.print(_minute);
    lcd.print(".");
    lcd.print(_second);
    lcd.print("  ");
  }
