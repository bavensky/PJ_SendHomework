void input_password()
{
  char key = keypad.getKey();
  
    // กรณีที่ Lock อยู่  LED สีแดงจะติด  และหากอยู่ระหว่างการใส่รหัส LED สีแดงจะกระพริบ
    if(locked)
    {
      if(passinput)
      {
        unsigned long ledcurrentvar = millis();
        if(ledcurrentvar - ledflashvar > ledflashtime) 
        {
          ledflashvar = ledcurrentvar;
          digitalWrite(lockedled, !digitalRead(lockedled));
        }
      }
      // ถ้าไม่ได้อยู่ระหว่างการใส่รหัส
      else
      {
        digitalWrite(lockedled, 255);   // LED สีแดงจะติด
      }
      digitalWrite(unlockedled, 0);     // LED สีเขียวดับ
    }
  
    if (key != NO_KEY)
    {
      password.append(key);  // บันทึกค่ารหัสที่กดและเปรียบเทียบกับรหัสที่ถูกต้อง
      passinput = 1;         // อยู่ระหว่างการใส่รหัส
      
      // ถ้ากด '#' ให้เริ่มใส่รหัสใหม่
      if(key == '#')
      {  
        password.reset();     // เริ่มต้นใส่รหัสใหม่ตั้งแต่ตัวแรก
        passinput = 0;        // ไม่อยู่ระหว่างการกดรหัส  
        locked = 1;
      }
      
      if(password.evaluate())  //  ถ้าใส่ Password ถูกต้องให้ปลดล็อค 
      {       
        locked = !locked; 
        password.reset();             // เริ่มต้นใส่รหัสใหม่ตั้งแต่ตัวแรก
        passinput = 0;
      }
      
      //  ถ้าปลดล๊อคแล้วให้ไฟสีเขียวติด  สีแดงดับ  และสามารถควบคุมการเปิดปิดของ Relay ได้
      while(!locked) 
      {                  
        digitalWrite(lockedled, 0);
        digitalWrite(unlockedled, 255);
        lcd.clear();
        
        menu = 1;
        while(menu == 1)
        {
          lcd.setCursor(0, 0);
          lcd.print("Send_homework..!");
          lcd.setCursor(0, 1);
          lcd.print("Setting Time    ");
          lcd.setCursor(0, 2);
          lcd.print("Box select :    ");
          lcd.setCursor(0, 3);
          lcd.print("  A   B   C   D ");
          
          char key = keypad.getKey();
          if(key == 'A') {  box1 =0; box1++;  menu=0;  lcd.clear();  };
          if(key == 'B') {  box2 =0; box2++;  menu=0;  lcd.clear();  };
          if(key == 'C') {  box3 =0; box3++;  menu=0;  lcd.clear();  };
          if(key == 'D') {  box4 =0; box4++;  menu=0;  lcd.clear();  };
          if(key == '#')
          {  
            password.reset();     // เริ่มต้นใส่รหัสใหม่ตั้งแต่ตัวแรก
            passinput = 0;        // ไม่อยู่ระหว่างการกดรหัส  
            locked = 1;
            menu = 0;
          }
        }
        
        while(box1 == 1)
        {         
          setting_timeA();
        }
        while(box2 == 1)
        {         
          setting_timeB();
        }
        while(box3 == 1)
        {         
          setting_timeC();
        }
        while(box4 == 1)
        {         
          setting_timeD();
        }
        
      }
      
    }
}
