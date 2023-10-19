void verifySensors(){
  //OUTPUT MAX VOLTAGE
  const float voltage = 3.3; //if you are using an Arduino, modify the value here!!

  if(fanSpeed != -1){
    power = float((fanSpeed/100)*voltage);
    analogWrite(FAN, ((power*1023)/voltage));
  } else{
    analogWrite(FAN, 0);
  }

  if(temperature >= temperatureSet && temperatureSet != -1 && temperature > -1){
    digitalWrite(RELAY, LOW);
    state = false;
  } else if(temperatureSet != -1 && temperature != -1 && temperature < temperatureSet){
    digitalWrite(RELAY, HIGH);
    state = true;
  }
}