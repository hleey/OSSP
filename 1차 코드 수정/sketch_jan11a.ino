#include <SoftwareSerial.h> //시리얼 통신 라이브러리 호출

int Relaypin1 = 8;

SoftwareSerial HM10(2, 3);  //시리얼 통신 객체선언


void setup() {
  pinMode(Relaypin1, OUTPUT); // RelayPin1(8번핀)을 OUTPUT으로 설정
  Serial.begin(9600);   // 시리얼모니터 
  HM10.begin(9600); // 블루투스 시리얼
}

void loop() {
  if(HM10.available()){
    int t = HM10.read();
    Serial.print(t);
    Serial.println();

    if(t==0){ //OFF
      digitalWrite(Relaypin1, LOW);   // 릴레이 차단
    }
    if(t==1){ //ON
      digitalWrite(Relaypin1, HIGH);  // 릴레이 공급
    } 
  }
}
