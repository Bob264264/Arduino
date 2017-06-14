int outPins[] = {11, 10, 9};
String colors[] = {"Red", "Orange", "Yellow", "Green", "Blue", "Purple", "White", "Off"};
int rgb[][3] = {{255, 0, 0}, {255, 127, 0}, {255, 255, 0}, {0, 255, 0}, {0, 0, 255}, {148, 0, 211}, {255, 255, 255}, {0, 0, 0}};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < sizeof(outPins); i++)
    pinMode(outPins[i], OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    int index = getColor(Serial.readString());
    Serial.println(colors[index] + "!");
    if (index != -1)
      emit(rgb[index]);
    else
      Serial.println("Invalid color");
  }
}

int getColor(String col) {
  for (int i = 0; i < sizeof(colors); i++)
    if (col.equalsIgnoreCase(colors[i]))
      return i;
  return -1;
}

void emit(int values[]) {
  for (int i = 0; i < 3; i++)
    analogWrite(outPins[i], values[i]);
}

