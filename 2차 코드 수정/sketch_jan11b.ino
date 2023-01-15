#include <SoftwareSerial.h> //시리얼 통신 라이브러리 호출

int Relaypin1 = 8; // 릴레이모듈 핀번호
SoftwareSerial HM10(2, 3);  //시리얼 통신 객체선언 (블루투스모듈 tx,rx의 핀번호)

void setup() {
  pinMode(Relaypin1, OUTPUT); // RelayPin1(8번핀)을 OUTPUT으로 설정
  Serial.begin(9600);   // 시리얼모니터 
  HM10.begin(9600); // 블루투스 시리얼
}

void loop() {
  if(HM10.available()){
    int t = HM10.read(); // 블루투스모듈로 부터 들어오는 시리얼값을 변수 t로 지정
    Serial.print(t); //
    Serial.println(); //

    if(t==0){ // 0값이 들어오는 경우 = OFF
      digitalWrite(Relaypin1, LOW);   // 릴레이 차단
    }
    if(t==1){ // 1값이 들어오는 경우 = ON
      digitalWrite(Relaypin1, HIGH);  // 릴레이 공급
    } 
    if(t==2){ // 예약시간과 현재시간이 같을 때 = 2
      if(digitalRead(Relaypin1)== HIGH){ // 현재 릴레이모듈 상태가 on일때
        digitalWrite(Relaypin1, LOW);  // off로 상태를 변경
    }
      else { // 현재 릴레이모듈 상태가 off일때
        digitalWrite(Relaypin1, HIGH); // on으로 상태를 변경
      }
    }
  }
}
