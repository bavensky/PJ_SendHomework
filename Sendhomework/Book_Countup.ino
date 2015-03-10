void bookcount()  {
  lcd.home();
  lcd.print(" Project_RMUTL  ");
  lcd.setCursor(0, 1);
  lcd.print("Send_homework..!");
  printDateTime();
  
//  Digit > | 7 || 6 | , | 5 || 4 | , | 3 || 2 | , | 1 || 0 |  //  
//  show Box A  
  showdisplay(0,  7,  sum_boxa_tens);
  showdisplay(0,  6,  sum_boxa_units);
//  show Box B  
  showdisplay(0,  5,  sum_boxb_tens);
  showdisplay(0,  4,  sum_boxb_units);
//  show Box C
  showdisplay(0,  3,  sum_boxc_tens);
  showdisplay(0,  2,  sum_boxc_units);
//  show Box D
  showdisplay(0,  1,  sum_boxd_tens);
  showdisplay(0,  0,  sum_boxd_units);

//  Function  read book  //
  read_irsensor();
  
/*****************  Read book boxA  ****************************/
  if(read_sensor_A1 > DETECT  &&  read_sensor_A2  <  DETECT)  {
    count_detect1 = 1;
  }
  while(count_detect1 == 1)  {
    lcd.home();
    lcd.print(" Project_RMUTL  ");
    lcd.setCursor(0, 1);
    lcd.print("Send_homework..!");
    printDateTime();

    read_irsensor();
    if(read_sensor_A1 < DETECT)  {
      delay(200);
      count_detect1 = 0;
    }
    if(read_sensor_A1 > DETECT && read_sensor_A2 > DETECT)  {
      delay(200);
      count_detect1 = 2;
    }
  }
  while(count_detect1 == 2)  {
    lcd.home();
    lcd.print(" Project_RMUTL  ");
    lcd.setCursor(0, 1);
    lcd.print("Send_homework..!");
    printDateTime();
     
    read_irsensor();
    if(read_sensor_A2 < DETECT)  {
      delay(200);
      count_detect1 = 0;
    }
    if(read_sensor_A1 < DETECT && read_sensor_A2 > DETECT)  {
      delay(200);
      count_detect1 = 3;
    }
  }
    
  while(count_detect1 == 3)  {
    lcd.home();
    lcd.print(" Project_RMUTL  ");
    lcd.setCursor(0, 1);
    lcd.print("Send_homework..!");
    printDateTime();
    
    read_irsensor();
    if(read_sensor_A1 < DETECT  &&  read_sensor_A2 < DETECT)  {
      delay(200);
      sum_boxa_units += 1;
      if(sum_boxa_units >= 10){
        sum_boxa_tens += 1;
        sum_boxa_units = 0;
      }
      count_detect1 = 0;
    }    
  }
  
/*****************  Read book boxB  ****************************/
  if(read_sensor_B1 > DETECT  &&  read_sensor_B2  <  DETECT)  {
    count_detect2 = 1;
  }
  while(count_detect2 == 1)  {
    lcd.home();
    lcd.print(" Project_RMUTL  ");
    lcd.setCursor(0, 1);
    lcd.print("Send_homework..!");
    printDateTime();
  
    read_irsensor();
    if(read_sensor_B1 < DETECT)  {
      delay(200);
      count_detect2 = 0;
    }
    
    if(read_sensor_B1 > DETECT && read_sensor_B2 > DETECT)  {
      delay(200);
      count_detect2 = 2;
    }
  }
  while(count_detect2 == 2)  {
    lcd.home();
    lcd.print(" Project_RMUTL  ");
    lcd.setCursor(0, 1);
    lcd.print("Send_homework..!");
    printDateTime();
      
    read_irsensor();
    if(read_sensor_B2 < DETECT)  {
      delay(200);
      count_detect2 = 0;
    }
    
    if(read_sensor_B1 < DETECT && read_sensor_B2 > DETECT)  {
      delay(200);
      count_detect2 = 3;
      }
    }
  while(count_detect2 == 3)  {
    lcd.home();
    lcd.print(" Project_RMUTL  ");
    lcd.setCursor(0, 1);
    lcd.print("Send_homework..!");
    printDateTime();
    
    read_irsensor();
    if(read_sensor_B1 < DETECT && read_sensor_B2 < DETECT)  {
      delay(200);
      sum_boxb_units += 1;
      if(sum_boxb_units >= 10){
        sum_boxb_tens += 1;
        sum_boxb_units = 0;
      }
      count_detect2 = 0;
    }    
  }
///*****************  Read book boxC  ****************************/
  if(read_sensor_C1 > DETECT  &&  read_sensor_C2  <  DETECT)  {
    count_detect3 = 1;
  }
  while(count_detect3 == 1)  {
    lcd.home();
    lcd.print(" Project_RMUTL  ");
    lcd.setCursor(0, 1);
    lcd.print("Send_homework..!");
    printDateTime();
  
    read_irsensor();
    if(read_sensor_C1 < DETECT)  {
      delay(200);
      count_detect3 = 0;
    }
    
    if(read_sensor_C1 > DETECT && read_sensor_C2 > DETECT)  {
      delay(200);
      count_detect3 = 2;
    }
  }
  while(count_detect3 == 2)  {
    lcd.home();
    lcd.print(" Project_RMUTL  ");
    lcd.setCursor(0, 1);
    lcd.print("Send_homework..!");
    printDateTime();
      
    read_irsensor();
    if(read_sensor_C2 < DETECT)  {
      delay(200);
      count_detect3 = 0;
    }
    
    if(read_sensor_C1 < DETECT && read_sensor_C2 > DETECT)  {
      delay(200);
      count_detect3 = 3;
      }
    }
  while(count_detect3 == 3)  {
    lcd.home();
    lcd.print(" Project_RMUTL  ");
    lcd.setCursor(0, 1);
    lcd.print("Send_homework..!");
    printDateTime();
    
    read_irsensor();
    if(read_sensor_C1 < DETECT && read_sensor_C2 < DETECT)  {
      delay(200);
      sum_boxc_units += 1;
      if(sum_boxc_units >= 10){
        sum_boxc_tens += 1;
        sum_boxc_units = 0;
      }
      count_detect3 = 0;
    }    
  }
///*****************  Read book boxD  ****************************/
  if(read_sensor_D1 > DETECT  &&  read_sensor_D2  <  DETECT)  {
    count_detect4 = 1;
  }
  while(count_detect4 == 1)  {
    lcd.home();
    lcd.print(" Project_RMUTL  ");
    lcd.setCursor(0, 1);
    lcd.print("Send_homework..!");
    printDateTime();
  
    read_irsensor();
    if(read_sensor_D1 < DETECT)  {
      delay(200);
      count_detect4 = 0;
    }
    
    if(read_sensor_D1 > DETECT && read_sensor_D2 > DETECT)  {
      count_detect4 = 2;
    }
  }
  while(count_detect4 == 2)  {
    lcd.home();
    lcd.print(" Project_RMUTL  ");
    lcd.setCursor(0, 1);
    lcd.print("Send_homework..!");
    printDateTime();
      
    read_irsensor();
    if(read_sensor_D2 < DETECT)  {
      count_detect4 = 0;
    }
    
    if(read_sensor_D1 < DETECT && read_sensor_D2 > DETECT)  {
      delay(200);
      count_detect4 = 3;
      }
    }
  while(count_detect4 == 3)  {
    lcd.home();
    lcd.print(" Project_RMUTL  ");
    lcd.setCursor(0, 1);
    lcd.print("Send_homework..!");
    printDateTime();
    
    read_irsensor();
    if(read_sensor_D1 < DETECT && read_sensor_D2 < DETECT)  {
      delay(200);
      sum_boxb_units += 1;
      if(sum_boxd_units >= 10){
        sum_boxd_units = 0;
        sum_boxd_tens += 1;
      }
      count_detect4 = 0;
    }    
  }
/*****************  End Read book  ****************************/  
}  //  End void

void read_irsensor()  {
  read_sensor_A1  =  analogRead(SENSOR_BOX_A1);
  read_sensor_A2  =  analogRead(SENSOR_BOX_A2);
  
  read_sensor_B1  =  analogRead(SENSOR_BOX_B1);
  read_sensor_B2  =  analogRead(SENSOR_BOX_B2);

  read_sensor_C1  =  analogRead(SENSOR_BOX_C1);
  read_sensor_C2  =  analogRead(SENSOR_BOX_C2);
  
  read_sensor_D1  =  analogRead(SENSOR_BOX_D1);
  read_sensor_D2  =  analogRead(SENSOR_BOX_D2);
}
