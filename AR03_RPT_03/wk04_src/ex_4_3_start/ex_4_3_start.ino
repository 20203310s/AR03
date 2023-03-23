/*
 예제 4.2
 LED 밝기 조절
*/

const int RedLed    =  3;	  //를 3번핀에 연결
const int GreenLed  =  5;	  //LED B를 5번핀에 연결
const int BlueLed   =  6;	  //LED B를 5번핀에 연결

void setup()
{
  ledOutput(255, 0, 0);
  delay(1000);
  ledOutput(0, 255, 0);
  delay(1000);
  ledOutput(0, 0, 255);
  delay(1000);
}

void loop()
{
  for(int i=0;i<=255;++i){
    ledOutput(255,i,0);
    delay(10);
  }






} 

void ledOutput(int Red, int Green, int Blue){

  
}

