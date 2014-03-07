////// Includes
#include <LiquidCrystal.h>

////// Declaratives
int pinContrast = 6; // Pin to manage LCDs contrast to LCD pin 3
int pinBright   = 9; // Pin to manage LCDs backlight to LCD pin 15

int pinRS       = 12;// Pin to LCDs RS (4)
int pinEN       = 11;// Pin to LCDs RS (6)
int pinD4       = 5; // Pin to LCDs D4 (11)
int pinD5       = 4; // Pin to LCDs D5 (12)
int pinD6       = 3; // Pin to LCDs D6 (13)
int pinD7       = 2; // Pin to LCDs D7 (14)

int pinTrig=7;
int pinEcho=8;

int pinBuzzer=10;

long duracion;
double distancia;

////// LCD init
LiquidCrystal lcd(pinRS, pinEN, pinD4, pinD5, pinD6, pinD7);

void setup(){  
  pinMode(pinTrig,OUTPUT);
  pinMode(pinEcho,INPUT);
  
  pinMode(pinBuzzer,OUTPUT);
  
  digitalWrite(pinTrig,LOW);
  digitalWrite(pinBuzzer,LOW);
  
  lcd.begin(16,4);
  
  analogWrite(pinContrast,15);
  analogWrite(pinBright, 128);
  
}

void loop(){
  delayMicroseconds(2);
  digitalWrite(pinTrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig,LOW);
  
  duracion=pulseIn(pinEcho,HIGH);
  
  distancia=(duracion/2)/29;
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distancia:");
  lcd.setCursor(0,1);
  lcd.print(distancia);
  lcd.print(" cms");


  
  if(distancia<15){
    digitalWrite(pinBuzzer,HIGH); 
  }else{
    digitalWrite(pinBuzzer,LOW);
  }
  
  delay(500);
  
}
