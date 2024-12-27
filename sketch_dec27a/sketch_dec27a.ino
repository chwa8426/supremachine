#include <SoftwareSerial.h>

int pir = 8;          // PIR 센서 핀
int led = 12;        // LED 핀
int buz = 13;        // 부저 핀
SoftwareSerial BTSerial(2, 3); // HC-05와의 소프트웨어 직렬 포트 설정

void setup() {
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buz, OUTPUT);
  
  Serial.begin(9600);    // 시리얼 모니터 통신
  BTSerial.begin(9600);  // HC-05 통신
}

void loop() {
  int value = digitalRead(pir);

  if (value == HIGH) {
    digitalWrite(led, HIGH); // LED 켜기
    digitalWrite(buz, HIGH); // 부저 울리기

    // 블루투스를 통해 메시지 전송
    String message = "사람이 접근했습니다!";
    BTSerial.println(message); // 블루투스를 통해 메시지 전송
    Serial.println(message);    // 시리얼 모니터에 출력

    delay(2000); // 2초 대기 (중복 메시지 방지)
  } else {
    digitalWrite(led, LOW); // LED 끄기
    digitalWrite(buz, LOW); // 부저 끄기
  }

  delay(500); // 감지 주기
}
