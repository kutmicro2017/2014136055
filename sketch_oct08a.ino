
#define UPPER_R 12
#define UPPER_Y 11
#define UPPER_G 10  // 상
#define LOWER_R 26
#define LOWER_Y 28
#define LOWER_G 30  // 하
#define LEFT_R 6
#define LEFT_Y 5
#define LEFT_G 4    // 좌
#define RIGHT_R 39
#define RIGHT_Y 41
#define RIGHT_G 43  // 우
#define SWITCH_A 2
#define SWITCH_B 3
const long interval = 50000; // 50초
volatile bool state = true;           // 스위치가 눌렸는지를 판단하는 변수
volatile bool state2 = true;          // 스위치가 눌렸는지를 판단하는 변수

void setup() {
  pinMode(UPPER_R, OUTPUT);
  pinMode(UPPER_G, OUTPUT);
  pinMode(UPPER_Y, OUTPUT);
  pinMode(LOWER_R, OUTPUT);
  pinMode(LOWER_G, OUTPUT);
  pinMode(LOWER_Y, OUTPUT);
  pinMode(LEFT_R, OUTPUT);
  pinMode(LEFT_G, OUTPUT);
  pinMode(LEFT_Y, OUTPUT);
  pinMode(RIGHT_R, OUTPUT);
  pinMode(RIGHT_G, OUTPUT);
  pinMode(RIGHT_Y, OUTPUT);
  pinMode(SWITCH_A, INPUT_PULLUP);   // 기본값이 HIGH
  pinMode(SWITCH_B, INPUT_PULLUP);   // 기본값이 HIGH
  attachInterrupt(0, tTof, FALLING); // 인터럽트0은 핀 2번, 따라서 스위치를 핀2에 연결, 스위치가 눌리면 실행, 인터럽트 핀의 값이 HIGH에서 LOW로 바뀔 때 함수 실행
  attachInterrupt(1, tTof, FALLING); // 인터럽트1은 핀 3번, 따라서 스위치를 핀3에 연결, 스위치가 눌리면 실행, 인터럽트 핀의 값이 HIGH에서 LOW로 바뀔 때 함수 실행
}                                    

void tTof() {
  if (digitalRead(LEFT_G) == HIGH) state = false;           // 스위치가 눌리면 state의 값을 바꿔줌
  if (digitalRead(LOWER_G) == HIGH) state2 = false;         // 스위치가 눌리면 state2의 값을 바꿔줌
}

void loop() 
{
  digitalWrite(UPPER_G, HIGH); digitalWrite(LOWER_G, HIGH);     // 상,하 초록불 켜기
  digitalWrite(LEFT_R, HIGH); digitalWrite(RIGHT_R, HIGH);      // 좌,우 빨간불 켜기
  
  unsigned long previousMillis2 = millis();
  while (millis() - previousMillis2 <= interval)                // 현재 시각과 이전 시각의 차이가 50초가 될 때까지 반복
  { 
    // 시간 지연 동안에 다른 동작을 해야하므로 delay함수는 사용 못함
    if (state2 == false)          // 스위치가 눌렸으면
    { 
      delay(3000);               // 3초간 대기
      digitalWrite(UPPER_G, LOW); digitalWrite(LOWER_G, LOW);      // 상,하 초록불 끄기

      // 노란불
      for (int delaytime = 0; delaytime < 10; delaytime++) 
      {
        digitalWrite(UPPER_Y, HIGH); digitalWrite(LOWER_Y, HIGH);   // 상,하 노란불 켜기
        delay(500);
        digitalWrite(UPPER_Y, LOW); digitalWrite(LOWER_Y, LOW);     // 상,하 노란불 끄기
        delay(500);
      }
      digitalWrite(UPPER_R, HIGH); digitalWrite(LOWER_R, HIGH);     // 상,하 빨간불 켜기(보행자 건넘)
      
      state2 = true; //동작이 끝났으니 변수를 원래 상태로 돌려줌
      delay(10000);
      digitalWrite(UPPER_R, LOW); digitalWrite(LOWER_R, LOW);       // 상,하 빨간불 끄기
      digitalWrite(UPPER_G, HIGH); digitalWrite(LOWER_G, HIGH);     // 상,하 초록불 켜기
      previousMillis2 = millis() - 33000;                           // 빨간 신호를 켜서 딜레이 된 만큼 지연 시간을 늘려줌(???)
    }
   }
  
  digitalWrite(UPPER_G, LOW); digitalWrite(LOWER_G, LOW);         // 상,하 초록불 끄기

  // 노란불
  for (int delaytime = 0; delaytime < 10; delaytime++) 
  {
    digitalWrite(UPPER_Y, HIGH); digitalWrite(LOWER_Y, HIGH);     // 상,하 노란불 켜기
    delay(500);
    digitalWrite(UPPER_Y, LOW); digitalWrite(LOWER_Y, LOW);       // 상,하 노란불 끄기
    delay(500);
  }
  digitalWrite(UPPER_R, HIGH); digitalWrite(LOWER_R, HIGH);       // 상,하 빨간불 켜기
  
  digitalWrite(LEFT_R, LOW); digitalWrite(RIGHT_R, LOW);          // 좌,우 빨간불 끄기
  digitalWrite(LEFT_G, HIGH); digitalWrite(RIGHT_G, HIGH);        // 좌,우 초록불 켜기

  unsigned long previousMillis = millis();
  while (millis() - previousMillis <= interval)                   // 현재 시각과 이전 시각의 차이가 50초가 될 때까지 반복
  { 
    // 시간 지연 동안에 다른 동작을 해야하므로 delay함수는 사용 못함
    if (state == false)          // 스위치가 눌렸으면
    { 
      delay(3000);               // 3초간 대기
      digitalWrite(LEFT_G, LOW); digitalWrite(RIGHT_G, LOW);      // 좌,우 초록불 끄기

      // 노란불
      for (int delaytime = 0; delaytime < 10; delaytime++) 
      {
        digitalWrite(LEFT_Y, HIGH); digitalWrite(RIGHT_Y, HIGH);   // 좌,우 노란불 켜기
        delay(500);
        digitalWrite(LEFT_Y, LOW); digitalWrite(RIGHT_Y, LOW);     // 좌,우 노란불 끄기
        delay(500);
      }
      digitalWrite(LEFT_R, HIGH); digitalWrite(RIGHT_R, HIGH);     // 좌,우 빨간불 켜기(보행자 건넘)
      
      state = true; //동작이 끝났으니 변수를 원래 상태로 돌려줌
      delay(10000);
      digitalWrite(LEFT_R, LOW); digitalWrite(RIGHT_R, LOW);       // 좌,우 빨간불 끄기
      digitalWrite(LEFT_G, HIGH); digitalWrite(RIGHT_G, HIGH);     // 좌,우 초록불 켜기
      previousMillis = millis() - 33000;                           // 빨간 신호를 켜서 딜레이 된 만큼 지연 시간을 늘려줌(???)
    }
   }
   
    digitalWrite(LEFT_G, LOW); digitalWrite(RIGHT_G, LOW);         // 좌,우 초록불 끄기

    // 노란불
    for (int delaytime = 0; delaytime < 10; delaytime++) 
    {
      digitalWrite(LEFT_Y, HIGH); digitalWrite(RIGHT_Y, HIGH);     // 좌,우 노란불 켜기
      delay(500);
      digitalWrite(LEFT_Y, LOW); digitalWrite(RIGHT_Y, LOW);       // 좌,우 노란불 끄기
      delay(500);
    }
    
    digitalWrite(UPPER_R, LOW); digitalWrite(LOWER_R, LOW);        // 상,하 빨간불 끄기
}
