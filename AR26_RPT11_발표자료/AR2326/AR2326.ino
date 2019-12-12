#include <Servo.h> 

Servo servo; 

const char trigPin = 7; // trig 7번핀으로 정의
const char echoPin = 6; // echo 6번핀으로 정의
int angle = 0;

void setup(){
  servo.attach(2);
  Serial.begin(9600); //시리얼 통신 속도 설정
  pinMode(trigPin, OUTPUT); // 송신부설정
  pinMode(echoPin, INPUT); // 수신부설정
}
void loop()
{
 long duration, distance;

 digitalWrite(trigPin, LOW);
 digitalWrite(echoPin, LOW);
 delayMicroseconds(2); // 2us 딜레이
 digitalWrite(trigPin, HIGH); // Trig 핀 High
 delayMicroseconds(10); // 10us 딜레이
 digitalWrite(trigPin, LOW); // Trig 핀 LOW

 duration = pulseIn(echoPin, HIGH); // duration에 pulseln 값 저장
 distance = ((float)(340 * duration) / 10000) / 2; // 거리측정 & cm으로 나타내기 위해 1000으로 나눠줌

 Serial.print("거리: ");
 Serial.print(distance); // 거리를 시리얼 모니터에 출력
 Serial.println("cm");

 if ( distance < 30){ 
  angle = 70;
  Serial.println("문이 열렸습니다.");
  delay(2000);
 }
 else{
  angle = 180;
  Serial.println("문이 닫혔습니다.");
  delay(2000);
 }
  servo.write(angle);
}
