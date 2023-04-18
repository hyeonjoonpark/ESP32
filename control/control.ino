unsigned long t1 = 0;
unsigned long t2 = 0;
unsigned long t3 = 0;
unsigned long t4 = 0;

unsigned long t5 = 0;
int btn_cnt = 0;

bool old_btn = HIGH;
int motion_cnt = 0;
int old_motion = 0;

void setup() {
  Serial.begin(115200);
  pinMode(16, OUTPUT);
  pinMode(17, INPUT);
}

void loop() {
  bool now_motion = digitalRead(5);
  if(old_motion == LOW && now_motion == HIGH) {
    motion_cnt++;
  }

  old_motion = now_motion;
  
  if(digitalRead(16) == HIGH) {
    if(millis() - t4 > 3000) {
      digitalWrite(16, LOW);
    }
  }
  bool now_btn = digitalRead(17);
    if(old_btn == HIGH && now_btn == LOW) {
    //하강엣지
    t3 = millis();
  } else if(old_btn == LOW && now_btn == HIGH) {
    //상승엣지
    Serial.print("버튼 누른 시간 = ");
    Serial.println(millis() - t3);
    if(millis() - t3 > 50) {
      // 버튼이 눌려짐
      digitalWrite(16, HIGH);
      t4 = millis();
        btn_cnt++;
    }
  }
  old_btn = now_btn;
//  if(millis() - t1 >= 1000) {
//    t1 = millis();
//    bool state = digitalRead(16);
//    digitalWrite(16, !state);
//  }
  if(millis() - t2 >= 1000) {
    t2 = millis();
    Serial.print("BUTTON COUNTER = ");
    Serial.println(btn_cnt);
    Serial.print("MOTION COUNTER = ");
    Serial.println(motion_cnt);
  }

if(old_btn == HIGH && now_btn == LOW) {
    //하강엣지
    t3 = millis();
  } else if(old_btn == LOW && now_btn == HIGH) {
    //상승엣지
    Serial.print("버튼 누른 시간 = ");
    Serial.println(millis() - t3);
    if(millis() - t3 > 50) {
      // 버튼이 눌려짐
      digitalWrite(16, HIGH);
      t4 = millis();
        btn_cnt++;
    }
  }



  
}
