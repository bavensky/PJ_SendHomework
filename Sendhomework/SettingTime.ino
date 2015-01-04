//////////////////////////////  Setting time cound box A //////////////////////////////  
  void setting_timeA()
  {
    lcd.setCursor(0, 0);
    lcd.print("Setting Time    "); 
    lcd.setCursor(0, 1);
    lcd.print("Box A           ");
    
sethourA:             
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
setminuteA:              
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
    lcd.setCursor(0, 0);
    lcd.print("Setting Time    "); 
    lcd.setCursor(0, 1);
    lcd.print("Box B           ");
    
sethourB:          
    b_tens_hour = 0; 
    b_unit_hour = 0;
    b_tens_hour = 0;
    b_tens_minute = 0;

     box2 = 2;
     while(box2 == 2)
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
       lcd.print(b_tens_hour); 
       lcd.print(":");
       lcd.print(b_tens_minute);
       lcd.print(b_unit_minute);
       lcd.print("   ");
       
       readkeypad();
       b_tens_hour = allkeypad * 10;
       if(asterisk == 1)
       {
         allkeypad = 0;
         asterisk = 0;
         box2 = 3;
       }
     } 
     
     while(box2 == 3)
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
       lcd.print(b_tens_hour / 10); 
       lcd.blink();
       delay(100);
       lcd.print(b_unit_hour);     
       lcd.print(":");
       lcd.print(b_tens_minute);
       lcd.print(b_unit_minute);
       lcd.print("   ");
       
       readkeypad();
       b_unit_hour = allkeypad;
       
       if(asterisk == 1)
       {
         time_hour_box2 = b_tens_hour + b_unit_hour;
         if(time_hour_box2 > 24)  
         {
           asterisk = 0;
           allkeypad = 0;
           goto sethourB;
         }
         else
         {
setminuteB:           
           allkeypad = 0; 
           asterisk = 0;
           b_tens_minute = 0;
           b_unit_minute = 0;
           box2 = 4;
         }
       }
     }

     while(box2 == 4)
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
       lcd.print(time_hour_box2);   
       lcd.print(":");
       lcd.blink();
       delay(100);
       lcd.print(b_tens_minute);
       lcd.print("    ");
              
       readkeypad();
       b_tens_minute = allkeypad * 10;
       if(asterisk == 1)
       {
         allkeypad = 0; 
         asterisk = 0;
         box2 = 5;
       }
     }
     
     while(box2 == 5)
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
       lcd.print(time_hour_box2);   
       lcd.print(":");
       lcd.print(b_tens_minute / 10);
       lcd.blink();
       delay(100);
       lcd.print(b_unit_minute);
       
       readkeypad();
       b_unit_minute = allkeypad;
       if(asterisk == 1)
       {
         allkeypad = 0; 
         asterisk = 0;
         time_minute_box2 = b_tens_minute + b_unit_minute;
         
         if(time_minute_box2 > 59)  
         {
           asterisk = 0;
           allkeypad = 0;
           b_tens_minute = 0;
           b_unit_minute = 0;
           goto setminuteB;
         }
         else
         {
           lcd.clear();         
           lcd.home();
           lcd.print("Setting Time    "); 
           lcd.setCursor(0, 1);
           lcd.print("Box B           ");
           lcd.setCursor(0, 2);
           lcd.print("Time = ");
           lcd.print(time_hour_box2);
           lcd.print(":");
           lcd.print(time_minute_box2);
           lcd.setCursor(0, 3);
           lcd.print("    Success !   ");
           
           EEPROM.write(12, time_hour_box2);
           EEPROM.write(13, time_minute_box2);
           
           delay(3000);
           box2 = 0;
         }   
       }   
     }  
  }
  
//////////////////////////////  Setting time cound box C //////////////////////////////  
  void setting_timeC()
  {
    lcd.setCursor(0, 0);
    lcd.print("Setting Time    "); 
    lcd.setCursor(0, 1);
    lcd.print("Box C           ");
    
sethourC:             
    c_tens_hour = 0; 
    c_unit_hour = 0;
    c_tens_hour = 0;
    c_tens_minute = 0;

     box3 = 2;
     while(box3 == 2)
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
       lcd.print(c_tens_hour); 
       lcd.print(":");
       lcd.print(c_tens_minute);
       lcd.print(c_unit_minute);
       lcd.print("   ");
       
       readkeypad();
       c_tens_hour = allkeypad * 10;
       if(asterisk == 1)
       {
         allkeypad = 0;
         asterisk = 0;
         box3 = 3;
       }
     } 
     
     while(box3 == 3)
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
       lcd.print(c_tens_hour / 10); 
       lcd.blink();
       delay(100);
       lcd.print(c_unit_hour);     
       lcd.print(":");
       lcd.print(c_tens_minute);
       lcd.print(c_unit_minute);
       lcd.print("   ");
       
       readkeypad();
       c_unit_hour = allkeypad;
       
       if(asterisk == 1)
       {
         time_hour_box3 = c_tens_hour + c_unit_hour;
         if(time_hour_box3 > 24)  
         {
           asterisk = 0;
           allkeypad = 0;
           goto sethourC;
         }
         else
         {
setminuteC:            
           allkeypad = 0; 
           asterisk = 0;
           c_tens_minute = 0;
           c_unit_minute = 0;
           box3 = 4;
         }
       }
     }

     while(box3 == 4)
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
       lcd.print(time_hour_box3);   
       lcd.print(":");
       lcd.blink();
       delay(100);
       lcd.print(c_tens_minute);
       lcd.print("    ");
              
       readkeypad();
       c_tens_minute = allkeypad * 10;
       if(asterisk == 1)
       {
         allkeypad = 0; 
         asterisk = 0;
         box3 = 5;
       }
     }
     
     while(box3 == 5)
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
       lcd.print(time_hour_box3);   
       lcd.print(":");
       lcd.print(c_tens_minute / 10);
       lcd.blink();
       delay(100);
       lcd.print(c_unit_minute);
       
       readkeypad();
       c_unit_minute = allkeypad;
       if(asterisk == 1)
       {
         allkeypad = 0; 
         asterisk = 0;
         time_minute_box3 = c_tens_minute + c_unit_minute;
         
         if(time_minute_box3 > 59)  
         {
           asterisk = 0;
           allkeypad = 0;
           c_tens_minute = 0;
           c_unit_minute = 0;
           goto setminuteC;
         }
         else
         {
           lcd.clear();         
           lcd.home();
           lcd.print("Setting Time    "); 
           lcd.setCursor(0, 1);
           lcd.print("Box C           ");
           lcd.setCursor(0, 2);
           lcd.print("Time = ");
           lcd.print(time_hour_box3);
           lcd.print(":");
           lcd.print(time_minute_box3);
           lcd.setCursor(0, 3);
           lcd.print("    Success !   ");
           
           EEPROM.write(14, time_hour_box3);
           EEPROM.write(15, time_minute_box3);
           
           delay(3000);
           box3 = 0;
         }   
       }   
     }  
  }

//////////////////////////////  Setting time cound box D //////////////////////////////  
  void setting_timeD()
  {
    lcd.setCursor(0, 0);
    lcd.print("Setting Time    "); 
    lcd.setCursor(0, 1);
    lcd.print("Box D           ");
    
sethourD:            
    d_tens_hour = 0; 
    d_unit_hour = 0;
    d_tens_hour = 0;
    d_tens_minute = 0;

     box4 = 2;
     while(box4 == 2)
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
       lcd.print(d_tens_hour); 
       lcd.print(":");
       lcd.print(d_tens_minute);
       lcd.print(d_unit_minute);
       lcd.print("   ");
       
       readkeypad();
       d_tens_hour = allkeypad * 10;
       if(asterisk == 1)
       {
         allkeypad = 0;
         asterisk = 0;
         box4 = 3;
       }
     } 
     
     while(box4 == 3)
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
       lcd.print(d_tens_hour / 10); 
       lcd.blink();
       delay(100);
       lcd.print(d_unit_hour);     
       lcd.print(":");
       lcd.print(d_tens_minute);
       lcd.print(d_unit_minute);
       lcd.print("   ");
       
       readkeypad();
       d_unit_hour = allkeypad;
       
       if(asterisk == 1)
       {
         time_hour_box4 = d_tens_hour + d_unit_hour;
         if(time_hour_box4 > 24)  
         {
           asterisk = 0;
           allkeypad = 0;
           goto sethourD;
         }
         else
         {
setminuteD:             
           allkeypad = 0; 
           asterisk = 0;
           d_tens_minute = 0;
           d_unit_minute = 0;
           box4 = 4;
         }
       }
     }

     while(box4 == 4)
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
       lcd.print(time_hour_box4);   
       lcd.print(":");
       lcd.blink();
       delay(100);
       lcd.print(d_tens_minute);
       lcd.print("    ");
              
       readkeypad();
       d_tens_minute = allkeypad * 10;
       if(asterisk == 1)
       {
         allkeypad = 0; 
         asterisk = 0;
         box4 = 5;
       }
     }
     
     while(box4 == 5)
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
       lcd.print(time_hour_box4);   
       lcd.print(":");
       lcd.print(d_tens_minute / 10);
       lcd.blink();
       delay(100);
       lcd.print(d_unit_minute);
       
       readkeypad();
       d_unit_minute = allkeypad;
       if(asterisk == 1)
       {
         allkeypad = 0; 
         asterisk = 0;
         time_minute_box4 = d_tens_minute + d_unit_minute;
         
         if(time_minute_box4 > 59)  
         {
           asterisk = 0;
           allkeypad = 0;
           d_tens_minute = 0;
           d_unit_minute = 0;
           goto setminuteD;
         }
         else
         {
           lcd.clear();         
           lcd.home();
           lcd.print("Setting Time    "); 
           lcd.setCursor(0, 1);
           lcd.print("Box D           ");
           lcd.setCursor(0, 2);
           lcd.print("Time = ");
           lcd.print(time_hour_box4);
           lcd.print(":");
           lcd.print(time_minute_box4);
           lcd.setCursor(0, 3);
           lcd.print("    Success !   ");
           
           EEPROM.write(16, time_hour_box4);
           EEPROM.write(17, time_minute_box4);
           
           delay(3000);
           box4 = 0;
         }   
       }   
     }  
  }
