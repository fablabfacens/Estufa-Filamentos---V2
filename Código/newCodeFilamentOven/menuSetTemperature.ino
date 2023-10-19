void menuSetTemperature(){
  int newPos = 0;
  int posEncoder;
  int pos1;

  encoder.setPosition(0);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperatura");
  lcd.setCursor(0,1);
  lcd.print("Selecione: ");
  lcd.setCursor(0,3);
  lcd.print("OK para confirmar");
  delay(200);

  while(digitalRead(BUTTON_CLK)){

    encoder.tick();
    newPos = encoder.getPosition();
    if(pos1 != newPos){
      if(newPos > 50){
        encoder.setPosition(0);
        newPos = 0;
      }
      if(newPos < 0){
        encoder.setPosition(50);
        newPos = 50;
      }

      Serial.print("Position: ");
      Serial.println(newPos);
      pos1 = newPos;
    }

    if(pos1 < 10){
      lcd.setCursor(11, 1);
      lcd.print("    ");
      lcd.setCursor(10, 1);
      lcd.print(pos1);
    } else{
      lcd.setCursor(10,1);
      lcd.print(pos1);
    }
  }

  lcd.clear();
  temperatureSet = pos1;
}