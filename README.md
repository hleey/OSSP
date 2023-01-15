# OSSP
OpenSource Software Project
<!--Line-->
#### 과목: 오픈소스SW프로젝트
>### 목표<dr>
>*  기존에 존재하는 오픈소스SW중 관심 가는 소스를 선택한 후, 오픈소스SW에서 습득한 지식을 기반으로 글로벌 OSS 협업 도구 사용 역량 강화.<dr>
>*  올바른 OSS 라이선스 적용으로 개입 프로젝트 결과물 완성 및 공개.
>*  세계 다양한 개발자들과 협업 기반 구축.



<결과물 im 또는 >

# 내 옆의 멀티탭🔌


### 📃 선택한 오픈소스<dr>
https://github.com/weekbook/Smart-Multitab 

Bluetooth를 이용한 원격제어 멀티탭 만들기

***

### 🛒 준비물<dr>
*  멀티탭(2구)
<img src="https://user-images.githubusercontent.com/86939460/211267125-27851007-e179-48e2-9726-4c69222403bb.jpg" width="400" height="500"/>

*  아두이노 케이블

<img src="https://user-images.githubusercontent.com/86939460/211267145-2b393bc3-81f0-4382-b36a-4e4fda03ecfd.jpg" width="400" height="500"/>

*  아두이노 우노
<img src="https://user-images.githubusercontent.com/86939460/211267152-7333bb5b-35b9-4510-aab2-18b415b2262e.jpg" width="400" height="500"/>

*  브레드보드
<img src="https://user-images.githubusercontent.com/86939460/211267184-df827da3-ad6b-43b0-8bd9-302fe43e3773.jpg" width="400" height="500"/>

*  스트리퍼(전선 피복기)
<img src="https://user-images.githubusercontent.com/86939460/211267195-4a079955-bf4f-4655-8f74-f06c30b724a9.jpg" width="400" height="500"/>

*  점퍼선
<img src="https://user-images.githubusercontent.com/86939460/211267205-c92c6996-f2f9-4656-9b1b-0787db1236ec.jpg" width="400" height="500"/>

*  릴레이 모듈(SRD-05VDC-SL-C)
<img src="https://user-images.githubusercontent.com/86939460/211267215-7f27e9f7-fec3-446d-b2ef-fbc0ec248379.jpg" width="400" height="500"/>

*  블루투스 모듈(HM-10)
<img src="https://user-images.githubusercontent.com/86939460/211267256-222f09f9-ac75-4950-b39f-824c6a4dd9b0.jpg" width="400" height="500"/>


***

### 📚 작업로그<dr>
##  하드웨어 구축
###  1. 도면 이미지<dr>
 (툴에 HM-10모듈과 SRD-05VDC-SL-C모듈을 도저히 찾을 수 없어서 HC-05, ???모듈로 삽입했지만 핀번호와 점퍼선을 꽂은 위치 자체는 같으니 참고해주세요.)
![image](https://user-images.githubusercontent.com/86939460/212538715-0c1bf4e6-b20d-407c-9c13-4c7e0b1dd77d.png)



###  2. 실제 제작 이미지
1) 멀티탭의 전선 피복 벗기기
<img src="https://user-images.githubusercontent.com/86939460/212539035-d4700ae6-2318-48fa-8a47-5fa261be9769.jpg" width="400" height="500"/>
<img src="https://user-images.githubusercontent.com/86939460/212539045-788943b0-cea7-40a9-9a3c-401b3bb124d2.jpg" width="400" height="500"/>
<img src="https://user-images.githubusercontent.com/86939460/212539053-3aa2d153-f484-448f-88b0-ff5e7e7761c8.jpg" width="400" height="500"/>
<img src="https://user-images.githubusercontent.com/86939460/212539059-3a309697-dc41-4481-88a5-beddf8d94f66.jpg" width="400" height="500"/>

2) 아두이노와 릴레이모듈, 블루투스모듈 연결

3) 릴레이모듈과 멀티텝 연결
(릴레이모듈의 나사를 먼저 풀어준 후 돌돌말았던 전선을 꽂고 나사를 다시 조여준다.)

## 코드
### 1. 코드 첨부<dr>

```
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
```

## 앱인벤터 제작
### 1. 앱인벤터 GUI
### 2. 앱인벤터 블록코딩 이미지 첨부
***

### ✔ 기존 프로젝트와의 차별점<dr>
<기능성>
<사용소자>
<코드, 블록코드 차이>
