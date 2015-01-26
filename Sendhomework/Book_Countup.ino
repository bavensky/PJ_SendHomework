void bookcount()
{
  read_ldr_A = analogRead(LDR_BOX_A);
  Serial.print(read_ldr_A);
  Serial.print("      ");
  Serial.println(sum_box_a);
  showdisplay(0,  7,  sum_box_a);
  
  if(read_ldr_A > 400)
  {
    sum_box_a = sum_box_a + 1;
    delay(200);
    if(sum_box_a >= 10)  {
      sum_box_a = 0;
    }
  }
}
