# OSSP
OpenSource Software Project
<!--Line-->
#### 과목: 오픈소스SW프로젝트
>### 목표<dr>
>*  기존에 존재하는 오픈소스SW중 관심 가는 소스를 선택한 후, 오픈소스SW에서 습득한 지식을 기반으로 글로벌 OSS 협업 도구 사용 역량 강화.<dr>
>*  올바른 OSS 라이선스 적용으로 개입 프로젝트 결과물 완성 및 공개.
>*  세계 다양한 개발자들과 협업 기반 구축.


### 📃 선택한 오픈소스<dr>
https://github.com/weekbook/Smart-Multitab 

***

# 내 옆의 멀티탭🔌

### 📃 주제<dr>

<img src="https://user-images.githubusercontent.com/86939460/212869890-d6f1ca52-5aeb-4ed6-9e7c-f38408fb122b.png" width="600" height="350"/>
<dr>
<dr>
<dr>

Bluetooth를 이용한 원격제어 멀티탭 만들기
<dr>
<dr>
<dr>

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
 (도면툴에서 HM-10모듈과 SRD-05VDC-SL-C모듈을 도저히 찾을 수 없어서 HM-10모듈은 HC-05모듈로, SRD-05VDC-SL-C모듈은 최대한 비슷한 모듈의 이미지로 삽입했습니다.<dr>
  핀번호와 점퍼선을 꽂은 위치는 같으니 참고해주세요.)
![image](https://user-images.githubusercontent.com/86939460/212859443-fd06e643-2169-42ec-bbab-4bded3b866ef.png)



###  2. 실제 제작 이미지
1) 멀티탭의 전선 피복 벗기기
<img src="https://user-images.githubusercontent.com/86939460/212539035-d4700ae6-2318-48fa-8a47-5fa261be9769.jpg" width="400" height="500"/>
<img src="https://user-images.githubusercontent.com/86939460/212539045-788943b0-cea7-40a9-9a3c-401b3bb124d2.jpg" width="400" height="500"/>
<img src="https://user-images.githubusercontent.com/86939460/212539053-3aa2d153-f484-448f-88b0-ff5e7e7761c8.jpg" width="400" height="500"/>
<img src="https://user-images.githubusercontent.com/86939460/212539059-3a309697-dc41-4481-88a5-beddf8d94f66.jpg" width="400" height="500"/>

2) 아두이노와 릴레이모듈, 블루투스모듈 연결<dr>

![image](https://user-images.githubusercontent.com/86939460/212861193-c67b9e91-824e-4c39-8b9a-f5a72ef4b7ae.png)


3) 릴레이모듈과 멀티텝 연결
(릴레이모듈의 나사를 먼저 풀어준 후 돌돌말았던 전선을 꽂고 나사를 다시 조여준다.)

<img src="https://user-images.githubusercontent.com/86939460/212869207-0b319512-b178-4c4d-9acf-a99a438f728e.png" width="600" height="450"/>
<img src="https://user-images.githubusercontent.com/86939460/212868466-0e9f2fc5-f7d6-4081-8adc-6a5fd3a12acb.png" width="600" height="450"/>
<dr>
설명을 위해 전선 하나는 꽂지 않았지만 마저 옆에 꽂아줍니다.


## 코드수정 및 추가
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
![image](https://user-images.githubusercontent.com/86939460/212541794-f6f5f389-6750-4f7d-a148-d1825bdb8011.png)
![image](https://user-images.githubusercontent.com/86939460/212541803-740e5c1c-f5b5-4eb9-b484-15af215c4871.png)
![image](https://user-images.githubusercontent.com/86939460/212875743-84594e50-e1ae-49b9-87b3-a24844aa389b.png)

### 2. 앱인벤터 블록코딩 이미지 첨부
*  현재 시간 코드<dr>

![image](https://user-images.githubusercontent.com/86939460/212872228-355f2848-da9d-4832-aeeb-f10d471980e5.png)

*  전원 ON/OFF 기능 코드<dr>

![image](https://user-images.githubusercontent.com/86939460/212871725-22374839-30ba-4c9a-b34a-f55288869247.png)

*  설정한 예약시간을 목록에 저장<dr>

![image](https://user-images.githubusercontent.com/86939460/212880925-292723f6-eeb2-46d5-8710-d718f00deae3.png)

*  앱 종료 후 다시 켰을 때 예약시간을 다시 불러오는 코드<dr>

![image](https://user-images.githubusercontent.com/86939460/212881173-ce9f5657-e41d-4389-a512-4206c20235ee.png)

*  예약시간을 삭제할 때 뜨는 선택대화창 코드<dr>

![image](https://user-images.githubusercontent.com/86939460/212881897-8eba8dab-5565-4dca-a6ad-6e0c2882cad5.png)

*  예약시간 삭제 코드<dr>

![image](https://user-images.githubusercontent.com/86939460/212882008-8a42b061-cc28-45b0-a858-940412b2c58b.png)

*  현재 시간과 예약 시간을 비교한 후 같으면 전원제어<dr>

![image](https://user-images.githubusercontent.com/86939460/212882346-4ecaaaf2-7154-43a7-849a-8d7376a3d27e.png)

*  블루투스 연결 코드<dr>

![image](https://user-images.githubusercontent.com/86939460/212871409-d5f65c45-4837-468b-af36-cd2e6e030aff.png)


### ✔ 기존 프로젝트와의 차별점<dr>
<img src="https://user-images.githubusercontent.com/86939460/212670637-e80e8d04-ba19-45da-a677-90f4a28183af.png" width="600" height="350"/>

## 기능성
> 기존 오픈소스
>*  멀티탭의 전원 ON/OFF 기능
>*  HC-06 블루투스 모듈 사용

> 본 프로젝트
>*  시간 예약 기능을 추가하여 원하는 시간에 전원을 ON/OFF 제어 가능
>*  HM-10 블루투스 모듈로 변경


