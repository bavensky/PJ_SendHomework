//////////////////////////////  Setting time cound box A //////////////////////////////  
  void setting_timeA()
  {
    lcd.setCursor(0, 0);
    lcd.print("Setting Time    "); 
    lcd.setCursor(0, 1);
    lcd.print("Box A           ");
    
sethourA:              // set hour
    a_tens_hour = 0; 
    a_unit_hour = 0;
    a_tens_hour = 0;
    a_tens_minute = 0;

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
       lcd.print("   ");
       
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
       lcd.print("   ");
       
       readkeypad();
       a_unit_hour = allkeypad;
       
       if(asterisk == 1)
       {
         time_hour_box1 = a_tens_hour + a_unit_hour;
         if(time_hour_box1 > 24)  
         {
           asterisk = 0;
           allkeypad = 0;
           goto sethourA;
         }
         else
         {
setminuteA:              // set minute  
           allkeypad = 0; 
           asterisk = 0;
           a_tens_minute = 0;
           a_unit_minute = 0;
           box1 = 4;
         }
       }
     }

     while(box1 == 4)
     {
       now_datetime();
       lcd.setCursor(0, 2);
       lcd.print("Tim : ");
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
       lcd.print("    ");
              
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
       a_unit_minute = allkeypad;
       if(asterisk == 1)
       {
         allkeypad = 0; 
         asterisk = 0;
         time_minute_box1 = a_tens_minute + a_unit_minute;
         
         if(time_minute_box1 > 59)  
         {
           asterisk = 0;
           allkeypad = 0;
           a_tens_minute = 0;
           a_unit_minute = 0;
           goto setminuteA;
         }
         else
         {
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
           
           EEPROM.write(10, time_hour_box1);
           EEPROM.write(11, time_minute_box1);
           
           delay(3000);
           box1 = 0;
         }   
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
