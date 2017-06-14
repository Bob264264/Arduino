int ledPin = 13;
int R1 = 4;
int P1 = 3;
int S1 = 2;
int R2 = 7;
int P2 = 6;
int S2 = 5;
boolean run = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void win1(){
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  run = false;
}
void win2(){
  digitalWrite(ledPin, HIGH);
  delay(300);
  digitalWrite(ledPin, LOW);
  delay(300);
  digitalWrite(ledPin, HIGH);
  delay(300);
  digitalWrite(ledPin, LOW);
  run = false;
}
void tie(){
  digitalWrite(ledPin, HIGH);
  delay(300);
  digitalWrite(ledPin, LOW);
  delay(300);
  digitalWrite(ledPin, HIGH);
  delay(300);
  digitalWrite(ledPin, LOW);
  delay(300);
  digitalWrite(ledPin, HIGH);
  delay(300);
  digitalWrite(ledPin, LOW);
  run = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  while(run){
  if (digitalRead(R1) > 0.5 && digitalRead(R2) > 0.5){
    tie();
  }
  else if(digitalRead(R1) > 0.5 && digitalRead(P2) > 0.5){
    win2();
  }
  else if(digitalRead(R1) > 0.5 && digitalRead(S2) > 0.5){
    win1();
  }
  else if(digitalRead(P1) > 0.5 && digitalRead(R2) > 0.5){
    win1();
  }
  else if(digitalRead(P1) > 0.5 && digitalRead(P2) > 0.5){
    tie();
  }
  else if(digitalRead(P1) > 0.5 && digitalRead(S2) > 0.5){
    win2();
  }
  else if(digitalRead(S1) > 0.5 && digitalRead(R2) > 0.5){
    win2();
  }
  else if(digitalRead(S1) > 0.5 && digitalRead(P2) > 0.5){
    win1();
  }
  else if(digitalRead(S1) > 0.5 && digitalRead(S2) > 0.5){
    tie();
  }
  }
  if (!(digitalRead(R1)>0.5||digitalRead(P1)>0.5||digitalRead(S1)>0.5||digitalRead(R2)>0.5||digitalRead(P2)>0.5||digitalRead(S2)>0.5)){
    run = true;
  }
}



