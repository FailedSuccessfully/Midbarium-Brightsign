const int fpb = 2;
const int spb = 6;
const int fpr = 10;
const int spr = 11;

bool p_turn = true;
int turns = 0;

void setup() {
  for (int i = 0; i < 4; i++){
    pinMode(fpb + i, INPUT_PULLUP);
    pinMode(spb + i, INPUT_PULLUP);
  }
  pinMode(fpr, OUTPUT);
  pinMode(spr, OUTPUT);
  digitalWrite(spr, HIGH);
  digitalWrite(fpr, HIGH);
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial);
}

void loop() {
  digitalWrite(fpr, LOW);
  while (p_turn){
    for (int i = fpb; i < fpb + 4; i++){
      if (digitalRead(i) == LOW){
        Serial.println(i - 1);
        p_turn = false;
        delay(6000);
        digitalWrite(fpr, HIGH);
        delay(1000);
      }
    }
    
  }
  digitalWrite(spr, LOW);
  while (!p_turn){
    for (int j = spb; j < spb + 4; j++){
      if (digitalRead(j) == LOW){
        Serial.println(j - 1);
        p_turn = true;
        delay(6000);
        digitalWrite(spr, HIGH);
        delay(1000);
      }
    }
    
  }
  turns++;
  if (turns >= 4){
    turns = 0;
    digitalWrite(fpr, LOW);
    digitalWrite(spr, LOW);

    delay(15000);
    digitalWrite(fpr, HIGH);
    digitalWrite(spr, HIGH);

    }
  }
  
