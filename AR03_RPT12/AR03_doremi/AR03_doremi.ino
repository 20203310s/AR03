/*
 예제 9.1
 피에조 부저를 이용한 소리 출력  
*/

int buzzerPin = 9;
int songLength = 16;
const int inputPin1=2;
const int inputPin2=3;
const int inputPin3=4;

// 노래 데이터, 공백은 쉬는 구간을 나타낸다
// 음계: 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C'
char notes[] = "cee egg dff abb ";
// 음의 길이, 노래 데이터와 맞춰 음의 길이를 설정한다.
int beats[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

// 노래의 빠르기를 설정한다.
int tempo = 200;

void setup() 
{
  // 부저핀을 출력으로 설정한다
  pinMode(buzzerPin, OUTPUT);
  pinMode(inputPin1, INPUT_PULLUP);
  pinMode(inputPin2, INPUT_PULLUP);
  pinMode(inputPin3, INPUT_PULLUP);

  Serial.begin(9600);
}


void loop()
{
  int swInput1 = digitalRead(inputPin1);
  int swInput2 = digitalRead(inputPin2);
  int swInput3 = digitalRead(inputPin3);

  // 버튼이 눌렸을 때 해당 음을 출력한다.
  if (swInput1 == LOW)
  {
    frequency(262);
  }
  else if (swInput2 == LOW)
  {
    frequency(330);
  }
  else if (swInput3 == LOW)
  {
    frequency(392);
  }
  else
  {
    noTone(buzzerPin); // 버튼이 눌리지 않았을 때 부저를 멈춘다.
  }

  // 음이 바뀔 때 잠시 쉬어준다
  delay(tempo / 10);
}
void frequency(int freq)
{
  // 주파수 값을 받아 부저를 울리는 함수

  tone(buzzerPin, freq, tempo);
}

