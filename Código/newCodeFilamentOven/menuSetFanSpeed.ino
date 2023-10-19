void menuSetFanSpeed(){
  int newPos = 0;
  int pos3 = 0;
  int posEncoder = 0;

  encoder.setPosition(0);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Velocidade do Fan");
  lcd.setCursor(0,1);
  lcd.print("Selecione: ");
  lcd.setCursor(0,3);
  lcd.print("OK para confirmar");
  delay(200);

  while(digitalRead(BUTTON_CLK)){
    encoder.tick();
    newPos = encoder.getPosition();
    if(pos3 != newPos)
    {
      if(newPos > 100)
      {
        encoder.setPosition(0);
        newPos = 0;
      }
      if (newPos < 0)
      {
        encoder.setPosition(100);
        newPos = 100;
      }
      Serial.print("Posicao:");
      Serial.println(newPos);
      pos3 = newPos;
    }
    if(pos3 < 10)
    {
      lcd.setCursor(11,1);
      lcd.print("   "); //REMOVES BUG OF UNNECESSARY ZERO
      lcd.setCursor(10,1);
      lcd.print(pos3);
    } else if(pos3<100){
      lcd.setCursor(10,1);
      lcd.print(pos3);
      lcd.setCursor(12,1);
      lcd.print("  ");
    } else{
      lcd.setCursor(10,1);
      lcd.print(pos3);
    }  
  }

  lcd.clear();
  fanSpeed = (float)pos3;
}