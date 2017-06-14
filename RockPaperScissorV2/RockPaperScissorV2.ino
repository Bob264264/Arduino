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

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(W1, LOW);
  digitalWrite(W2, LOW);
  digitalWrite(Tie, LOW);
  while(run){
    if(g(R1)==g(R2) && g(P1)==g(P2) && g(S1)==g(S2) && (g(R1) || g(P1) || g(S1))){
      digitalWrite(Tie, HIGH);
      delay(1000);
      digitalWrite(Tie, LOW);
      run = false;
    }
    else if(!(!(g(R1) && g(S2))&&!(g(P1) && g(R2))&&!(g(S1) && g(P2)))){
      digitalWrite(W1, HIGH);
      delay(1000);
      digitalWrite(W1, LOW);
      run = false;
    }
    else{
      digitalWrite(W2, HIGH);
      delay(1000);
      digitalWrite(W2, LOW);
      run = false;
    }
  }
  if (!(digitalRead(R1)>0.5||digitalRead(P1)>0.5||digitalRead(S1)>0.5||digitalRead(R2)>0.5||digitalRead(P2)>0.5||digitalRead(S2)>0.5)){
    run = true;
  }
}
