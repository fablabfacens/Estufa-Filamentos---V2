//libraries
#include <RotaryEncoder.h>
#include <dht.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

//defines
#define BUZZER 19 // Digital pin used by buzzer, to do a "bip"
#define PINDHT22 25 // Analog pin used by DHT11 humidity sensor
#define ONEWIREBUS 13 // Pin OneWire for temperature sensor
#define FAN 14
#define BUTTON_CLICK 15
#define BUTTON_CLK 4
#define BUTTON_DT 2
#define RELAY 5

void end();
void start();
void verifySensors();
void menu();
void menuSetTemperature();
void menuSetHumidity();
void menuSetFanSpeed();

float temperatureCalculator();
float humidityCalculator();


//variables
LiquidCrystal_I2C lcd(0x27, 20, 4); //columns and rows, modify if your display is not the same
OneWire oneWire(ONEWIREBUS);
DallasTemperature sensors(&oneWire);
//temperature
float temperature = -1, temperatureSet = -1;
dht DHT;
//humidity sensor
float humidity = -1, humiditySet = -1;
//relay state
bool state = false;
//fan
float fanSpeed = -1, power = -1;
//encoder
static int pos = 0;
//encoder init
RotaryEncoder encoder(BUTTON_DT, BUTTON_CLK);

void setup(){
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  pinMode(FAN, OUTPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(BUTTON_CLICK, INPUT_PULLUP);//CLICK OF ENCODER BUTTON
  sensors.begin(); //init the tmp sensor
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Fab LAB Facens");
  lcd.setCursor(4,3);
  lcd.print("version 2.0");
  delay(2000);
  lcd.clear();
}

void loop(){
  if(!digitalRead(BUTTON_CLICK)){
    menu();
  }

  temperature = temperatureCalculator();
  humidity = humidityCalculator();

  start();
  end();

  verifySensors();
}

float temperatureCalculator(){
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(0);
}

float humidityCalculator(){
  DHT.read22(PINDHT22);
  return DHT.humidity;
}
