int outPins[] = {9, 10, 11};

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < sizeof(outPins); i++)
    pinMode(outPins[i], OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < sizeof(outPins); i++)
    analogWrite(outPins[i], random(0, 255));
  delay(150);
}
