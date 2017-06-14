int W1 = 12;
int W2 = 11;
int Tie = 10;
int R1 = 4;
int P1 = 3;
int S1 = 2;
int R2 = 7;
int P2 = 6;
int S2 = 5;
boolean run = true;
#define g digitalRead

void setup() {
  // put your setup code here, to run once:
  pinMode(W1, OUTPUT);
  pinMode(W2, OUTPUT);
  pinMode(Tie, OUTPUT);
}

void win1(){
  digitalWrite(W1, HIGH);
  delay(1000);
  digitalWrite(W1, LOW);
  run = false;
}
void win2(){
  digitalWrite(W2, HIGH);
  delay(1000);
  digitalWrite(W2, LOW);
  run = false;
}
void tie(){
  digitalWrite(Tie, HIGH);
  delay(1000);
  digitalWrite(Tie, LOW);
  run = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  while(run){
  if (g(R1) > 0.5 && g(R2) > 0.5){
    tie();
  }
  else if(g(R1) > 0.5 && g(P2) > 0.5){
    win2();
  }
  else if(g(R1) > 0.5 && g(S2) > 0.5){
    win1();
  }
  else if(g(P1) > 0.5 && g(R2) > 0.5){
    win1();
  }
  else if(g(P1) > 0.5 && g(P2) > 0.5){
    tie();
  }
  else if(g(P1) > 0.5 && g(S2) > 0.5){
    win2();
  }
  else if(g(S1) > 0.5 && g(R2) > 0.5){
    win2();
  }
  else if(g(S1) > 0.5 && g(P2) > 0.5){
    win1();
  }
  else if(g(S1) > 0.5 && g(S2) > 0.5){
    tie();
  }
  }
  if (!(g(R1)>0.5||g(P1)>0.5||g(S1)>0.5||g(R2)>0.5||g(P2)>0.5||g(S2)>0.5)){
    run = true;
  }
}



