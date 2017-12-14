#include <SoftwareSerial.h>
#define btn1  12 // (도)버튼
#define btn2  11 // (레)버튼
#define btn3  10 // (미)버튼
#define btn4  9 // (파)버튼
#define btn5  8 // (솔)버튼
#define btn6  7 // (라)버튼
#define btn7  6 // (시)버튼
#define btn8  5 // (높은도)버튼
#define btn9 2 // 소리 바꾸는 버튼
#define LED_do 48
#define LED_re 46
#define LED_mi 44
#define LED_pa 42
#define LED_sol 40
#define LED_la 38
#define LED_si 36
#define LED_doh 34
SoftwareSerial mySerial(2, 3); //SW시리얼핀 정의 D3이 MIDI신호 전송용,  D2는 미사용 
byte resetMIDI = 4; // VS1053 Reset용 핀
byte ledPin = 13; //MIDI 트래픽 표시용 LED
byte note = 0; // 음계
int patch = 0; //악기
boolean bs1 = false; // 버튼의 상태
boolean br1;  // 버튼1 상태 확인용 입력값 임시저장용
boolean bs2 = false; // 버튼의 상태
boolean br2;  // 버튼1 상태 확인용 입력값 임시저장용
boolean bs3 = false; // 버튼의 상태
boolean br3;  // 버튼1 상태 확인용 입력값 임시저장용
boolean bs4 = false; // 버튼의 상태
boolean br4;  // 버튼1 상태 확인용 입력값 임시저장용
boolean bs5 = false; // 버튼의 상태
boolean br5;  // 버튼1 상태 확인용 입력값 임시저장용
boolean bs6 = false; // 버튼의 상태
boolean br6;  // 버튼1 상태 확인용 입력값 임시저장용
boolean bs7 = false; // 버튼의 상태
boolean br7;  // 버튼1 상태 확인용 입력값 임시저장용
boolean bs8 = false; // 버튼의 상태
boolean br8;  // 버튼1 상태 확인용 입력값 임시저장용
boolean bs9 = false;
boolean br9;  // 버튼 상태 확인용 입력값 임시저장용

int bn1 = 60; //버튼1의  note(음계)  가령 "도"  0~127까지 지정가능
int bn2 = 62; //버튼2의  note(음계)  가령 "레"
int bn3 = 64; //버튼3의  note(음계)  가령 "미"
int bn4 = 65; //버튼4의  note(음계)  가령 "파"
int bn5 = 67; //버튼5의  note(음계)  가령 "솔"
int bn6 = 69; //버튼6의  note(음계)  가령 "라"
int bn7 = 71; //버튼7의  note(음계)  가령 "시"
int bn8 = 72; //버튼8의  note(음계)  가령 "도~"
int bn9;

void setup() {
  //미디컨트롤을 위한 소프트웨어 시리얼 준비
  Serial.begin(31250);

  mySerial.begin(31250);

 // VS1053 초기화하고 사용할 준비
  pinMode(resetMIDI, OUTPUT);
  digitalWrite(resetMIDI, LOW);
  delay(100);
  digitalWrite(resetMIDI, HIGH);
  delay(100);


   pinMode( btn1, INPUT); // 건반 '도' 입력용 핀모드로 전환
   digitalWrite( btn1, HIGH); // 내부 PuulUp 설정
   pinMode( LED_do, OUTPUT); // 건반 '도' LED 설정

   pinMode( btn2, INPUT);
   digitalWrite( btn2, HIGH);
   pinMode( LED_re, OUTPUT);

   pinMode( btn3, INPUT);
   digitalWrite( btn3, HIGH);
   pinMode( LED_mi, OUTPUT);

   pinMode( btn4, INPUT);
   digitalWrite( btn4, HIGH);
   pinMode( LED_pa, OUTPUT);

   pinMode( btn5, INPUT);
   digitalWrite( btn5, HIGH);
   pinMode( LED_sol, OUTPUT);

   pinMode( btn6, INPUT);
   digitalWrite( btn6, HIGH);
   pinMode( LED_la, OUTPUT);

   pinMode( btn7, INPUT);
   digitalWrite( btn7, HIGH);
   pinMode( LED_si, OUTPUT);

   pinMode( btn8, INPUT);
   digitalWrite( btn8, HIGH);
   pinMode( LED_doh, OUTPUT);

   pinMode(btn9, INPUT);
   digitalWrite( btn9, HIGH);
}

void loop() {
  br1 = digitalRead(btn1);
  br2 = digitalRead(btn2);
  br3 = digitalRead(btn3);
  br4 = digitalRead(btn4);
  br5 = digitalRead(btn5);
  br6 = digitalRead(btn6);
  br7 = digitalRead(btn7);
  br8 = digitalRead(btn8);
  br9 = digitalRead(btn9);
   if( !bs1 && !br1 ){ // 건반 '도' 치는 코딩
     noteOn(0, bn1,100);
     bs1 = true;
     digitalWrite(LED_do, HIGH);
   }else if(bs1 && br1){
     noteOff(0, bn1,0);   
     bs1 = false;
     digitalWrite(LED_do, LOW);
   }
   
   if( !bs2 && !br2 ){
     noteOn(0, bn2,100);
     bs2 = true;
     digitalWrite(LED_re, HIGH);
   }else if(bs2 && br2){
     noteOff(0, bn2,0);   
     bs2 = false;
     digitalWrite(LED_re, LOW);
   }

   if( !bs3 && !br3 ){
     noteOn(0, bn3,100);
     bs3 = true;
     digitalWrite(LED_mi, HIGH);
   }else if(bs3 && br3){
     noteOff(0, bn3,0);   
     bs3 = false;
     digitalWrite(LED_mi, LOW);
   }

   if( !bs4 && !br4 ){
     noteOn(0, bn4,100);
     bs4 = true;
     digitalWrite(LED_pa, HIGH);
   }else if(bs4 && br4){
     noteOff(0, bn4,0);   
     bs4 = false;
     digitalWrite(LED_pa, LOW);
   }

   if( !bs5 && !br5 ){
     noteOn(0, bn5,100);
     bs5 = true;
     digitalWrite(LED_sol, HIGH);
   }else if(bs5 && br5){
     noteOff(0, bn5,0);   
     bs5 = false;
     digitalWrite(LED_sol, LOW);
   }

   if( !bs6 && !br6 ){
     noteOn(0, bn6,100);
     bs6 = true;
     digitalWrite(LED_la, HIGH);
   }else if(bs6 && br6){
     noteOff(0, bn6,0);   
     bs6 = false;
     digitalWrite(LED_la, LOW);
   }

   if( !bs7 && !br7 ){
     noteOn(0, bn7,100);
     bs7 = true;
     digitalWrite(LED_si, HIGH);
   }else if(bs7 && br7){
     noteOff(0, bn7,0);   
     bs7 = false;
     digitalWrite(LED_si, LOW);
   }

    if( !bs8 && !br8 ){
     noteOn(0, bn8,100);
     bs8 = true;
     digitalWrite(LED_doh, HIGH);
   }else if(bs8 && br8){
     noteOff(0, bn8,0);   
     bs8 = false;
     digitalWrite(LED_doh, LOW);
   }

   if( !bs9 && !br9)
   { 
     patch++;
     if(patch > 10) patch = 0;
     talkMIDI(0xc0, patch, 0);     
     bs9 = true;
   }else if(bs9 && br9){
     bs9 = false;
   }
}

//노트 온 미디 메세지를 송출. 버튼이 눌린상태와 같음.
//채널 범위는 0-15
void noteOn(byte channel, byte note, byte attack_velocity) {
  talkMIDI( (0x90 | channel), note, attack_velocity);
}

//노트 오프 미디 메세지를 송출. 버튼이 눌리지 않은 상태와 같음.
void noteOff(byte channel, byte note, byte release_velocity) {
  talkMIDI( (0x80 | channel), note, release_velocity);
}


void talkMIDI(byte cmd, byte data1, byte data2) {
  digitalWrite(ledPin, HIGH);
  mySerial.write(cmd );
  mySerial.write(data1 );

  //모든 명령은 1바이트를 지니며, 모든 cmds는 0xBn보다 2 데이터 바이트를 덜 지님.  
  if( (cmd & 0xF0) <= 0xB0)
    mySerial.write(data2 );

  digitalWrite(ledPin, LOW);
}
