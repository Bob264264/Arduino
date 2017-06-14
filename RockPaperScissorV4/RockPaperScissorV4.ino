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
    if(g(R1)==g(R2) && g(P1)==g(P2) && g(S1)==g(S2) && (g(R1) || g(P1) || g(S1)) && (g(R2) || g(P2) || g(S2))){
      tie();
    }
    else if(!( !(g(R1)&&g(S2)) && !(g(P1)&&g(R2)) && !(g(S1)&&g(P2)) )){
      win1();
    }
    else if(!( !(g(R2)&&g(S1)) && !(g(P2)&&g(R1)) && !(g(S2)&&g(P1)) )){
      win2();
    }
  
  }
  if (!(g(R1)>0.5||g(P1)>0.5||g(S1)>0.5||g(R2)>0.5||g(P2)>0.5||g(S2)>0.5)){
    run = true;
  }
}



