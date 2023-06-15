#include <Wire.h>
// I2C LCD 라리브러리 설정
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  

//  temperature & lux
#define TMP36_INPUT 0
#define CDS_INPUT 1
const int buzzerPin = 9; // 버저 핀
const int ledPin1 = 13; // LED 핀
const int ledPin2 = 3;
int a=20;
int b =24;
int tempo = 200;
void setup() {
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("temp:");
  lcd.setCursor(0,1);
  lcd.print("lux: ");

}
void loop() {
  // Temperature from TMP36
  int temp_value = analogRead(TMP36_INPUT);
  
  float voltage = temp_value * 5.0 * 1000;  // in mV
  voltage /= 1023.0;
  

  float tempC = (voltage - 500) / 10 ;
  

   // Lux from CdS (LDR)
  int cds_value = analogRead(CDS_INPUT);
  int lux = int(luminosity(cds_value));
  //Serial.print("ARnn,");
  Serial.print(tempC);
  //Serial.println(" degrees C");
  Serial.print(",");
  Serial.println(lux);
  lcd.setCursor(12,0);
  lcd.print(tempC);
  lcd.setCursor(14,1);
  lcd.print(lux);

  if(a<lux){ 
    digitalWrite(ledPin1,LOW);
    
  }else{
    digitalWrite(ledPin1,HIGH);
    
  }
  if(lux<a){ 
    
    frequency(392);
  }else{
    
    noTone(buzzerPin);
  }
  if(b<tempC){ 
    digitalWrite(ledPin2,LOW);
    
  }else{
    digitalWrite(ledPin2,HIGH);
  
  }
  if(b<tempC){ 
    
    frequency(392);
  }else{
    
    noTone(buzzerPin);
  }
    

  delay(1000);
}

//Voltage to Lux
double luminosity (int RawADC0){
  double Vout=RawADC0*5.0/1023.0;  // 5/1023 (Vin = 5 V)
  double lux=(2500/Vout-500)/10.0;  
  // lux = 500 / Rldr, Vout = Ildr*Rldr = (5/(10 + Rldr))*Rldr
  return lux;
}
void frequency(int freq)
{
  // 주파수 값을 받아 부저를 울리는 함수

  tone(buzzerPin, freq, tempo);
}


