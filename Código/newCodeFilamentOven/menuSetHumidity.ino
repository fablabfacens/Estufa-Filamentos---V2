void menuSetHumidity(){
  int newPos = 0;
  int pos2 = 0;
  int posEncoder = 0;

  encoder.setPosition(0);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Umidade");
  lcd.setCursor(0,1);
  lcd.print("Selecione: ");
  lcd.setCursor(0,3);
  lcd.print("OK para confirmar");
  delay(200);

  while(digitalRead(BUTTON_CLK)){
    encoder.tick();
    newPos = encoder.getPosition();
    if(pos2 != newPos)
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
      pos2 = newPos;
    }
    if(pos2 < 10)
    {
      lcd.setCursor(11,1);
      lcd.print("   "); //REMOVES BUG OF UNNECESSARY ZERO
      lcd.setCursor(10,1);
      lcd.print(pos2);
    } else if(pos2<100){
      lcd.setCursor(10,1);
      lcd.print(pos2);
      lcd.setCursor(12,1);
      lcd.print("  ");
    } else{
      lcd.setCursor(10,1);
      lcd.print(pos2);
    }  
  }

  lcd.clear();
  humiditySet = pos2;
}