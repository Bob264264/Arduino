int ON = 12;
int OFF = 7;
int LED = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(ON, INPUT_PULLUP);
  pinMode(OFF, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (digitalRead(ON) == LOW){
    digitalWrite(LED, HIGH);
  }
  else if (digitalRead(OFF) == LOW){
    digitalWrite(LED, LOW);
  }
}
