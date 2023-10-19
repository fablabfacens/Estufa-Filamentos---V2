void menu(){
  
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Voltar");

  lcd.setCursor(1,1);
  lcd.print("Ajustar Temperatura");

  lcd.setCursor(1,2);
  lcd.print("Velocidade do Fan");

  lcd.setCursor(1,3);
  lcd.print("Ajustar U.R.");

  int menuSelect = -1;
  int posEncoder = 0;
  int newPos = 0;

  delay(200);

  while(digitalRead(BUTTON_CLK)){

    encoder.tick();
    newPos = encoder.getPosition();

    if(pos != newPos){
      
      if(newPos > 3){
        encoder.setPosition(0);
        newPos = 0;
      }
      if(newPos < 0){
        encoder.setPosition(3);
        newPos = 3;
      }

      Serial.print("Position: ");
      Serial.println(newPos);

      pos = newPos;

      Serial.print("Returned value: ");
      Serial.println(pos);

      posEncoder = pos;
    }

    if(posEncoder == 0){
        lcd.setCursor(0,0);
        lcd.print("<");
        lcd.setCursor(0,1);
        lcd.print(" ");
        lcd.setCursor(0,2);
        lcd.print(" ");
        lcd.setCursor(0,3);
        lcd.print(" ");
        menuSelect = 0;
    } else if(posEncoder == 1){
       lcd.setCursor(0,0);
       lcd.print(" ");
       lcd.setCursor(0,1);
       lcd.print(">");
       lcd.setCursor(0,2);
       lcd.print(" ");
       lcd.setCursor(0,3);
       lcd.print(" "); 
       menuSelect = 1;
    } else if(posEncoder == 2){
        lcd.setCursor(0,0);
        lcd.print(" ");
        lcd.setCursor(0,1);
        lcd.print(" ");
        lcd.setCursor(0,2);
        lcd.print(">");
        lcd.setCursor(0,3);
        lcd.print(" ");
        menuSelect = 2;
    } else if(posEncoder == 3){
        lcd.setCursor(0,0);
        lcd.print(" ");
        lcd.setCursor(0,1);
        lcd.print(" ");
        lcd.setCursor(0,2);
        lcd.print(" ");
        lcd.setCursor(0,3);
        lcd.print(">");
        menuSelect = 3;
    }
  }

  lcd.clear();
  Serial.print("Option selected: "); Serial.print(menuSelect);

  switch(menuSelect){
    case 0:
      break;
    case 1:
      menuSetTemperature();
      break;
    case 2:
      menuSetFanSpeed();
      break;
    case 3:
      menuSetHumidity();
      break;
    default:
      break;
  }

}