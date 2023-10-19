void end(){
  if(humidity <= humiditySet && humidity != -1 && humiditySet != -1){
    digitalWrite(RELAY, LOW);
    analogWrite(FAN, 0);
    state = false;

    digitalWrite(BUZZER, HIGH);
    delay(1500);
    digitalWrite(BUZZER, LOW);
    lcd.clear();

    while(digitalRead(BUTTON_CLK)){
      lcd.setCursor(1,1);
      lcd.print("Processo finalizado");
      lcd.setCursor(4,3);
      lcd.print("Pressione OK");
    }

    digitalWrite(BUZZER, HIGH);
    delay(250);
    digitalWrite(BUZZER, LOW);

    temperatureSet = -1;
    humiditySet = -1;
    fanSpeed = -1;
    delay(150);
    lcd.clear();
  }
}