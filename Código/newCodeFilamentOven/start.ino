void start(){
//TEMP
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  if(temperature != -1){
    if(temperature < 10){
      lcd.print("0");
      lcd.print(int(temperature));
    } else{
      lcd.print(int(temperature));
    }
  } else{
    lcd.print("--");
  }

  lcd.print(" / ");

  if(temperatureSet != -1){
    if(temperatureSet < 10){
      lcd.print("0");
      lcd.print(int(temperatureSet));
    } else{
      lcd.print(int(temperatureSet));
    }
  } else{
    lcd.print("--");
  }

//LIGHT
  lcd.setCursor(12, 0);
  lcd.print("Lamp:");
  if(state){
    lcd.print(" On");
  } else{
    lcd.print("Off");
  }
//HUMIDITY
  lcd.setCursor(0, 1);
  lcd.print("U.R: ");
  if(humidity != -1){
    if(humidity < 10){
      lcd.print(" 0");
      lcd.print(int(humidity));
    }else if(humidity >= 10 && humidity < 100){
      lcd.print(" ");
      lcd.print(int(humidity));
    } else{
      lcd.print(int(humidity));
    }
  } else{
    lcd.print("---");
  }

  lcd.print(" / ");

  if(humiditySet != -1){
    if(humiditySet < 10){
      lcd.print(" 0");
      lcd.print(int(humiditySet));
    } else if(humiditySet >= 10 && humiditySet < 100){
      lcd.print(" ");
      lcd.print(int(humiditySet));
    } else{
      lcd.print(int(humiditySet));
    }
  } else{
    lcd.print("---");
  }
  lcd.print("%");

//FAN
  lcd.setCursor(0,3);
  lcd.print("Fan: ");
  if(fanSpeed != -1){
    if(fanSpeed < 10){
      lcd.print("0");
      lcd.print(int(fanSpeed));
    } else if(fanSpeed >= 10 && fanSpeed < 100){
      lcd.print(" ");
      lcd.print(int(fanSpeed));
    } else{
      lcd.print(int(fanSpeed));
    }
  } else{
    lcd.print("---");
  }
  lcd.print("%");
}