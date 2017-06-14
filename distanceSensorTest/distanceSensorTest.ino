int actuals[30];
int measured[30];
int count = 0;

void setup(){
  Serial.begin(9600);
}


void loop(){
  
  if (Serial.available() > 0){
    actuals[count] = Serial.parseInt();
    Serial.print("Actuals: ");
    printArray(actuals);
    delay(100);
    int measurements[10];
    for (int i = 0; i < 10; i++){
      measurements[i] = analogRead(0);
    }
    measured[count] = average(measurements);
    Serial.print("Measured: ");
    printArray(measured);

    regression();
    count++;
  }
}

void regression(){
  int x = 0;
  int y = 0;
  int x2 = 0;
  int y2 = 0;
  int xy = 0;
  for (int i = 0; i < count + 1; i++){
    x += actuals[i];
    y += measured[i];
    x2 += actuals[i] * actuals[i];
    y2 += measured[i] * measured[i];
    xy += actuals[i] * measured[i];
   }
   Serial.println(x);
   Serial.println(x2);
   Serial.println(y);
   Serial.println(y2);
   Serial.println(xy);
   double a = (double)(y * x2 - x * xy)/(double)((count + 1) * x2 - x * x);
   double b = (double)((count + 1) * xy - x * y)/(double)((count + 1) * x2 - x * x);
   Serial.print("Out = ");
   Serial.print(b);
   Serial.print("x + ");
   Serial.println(a);
}

void printArray(int list[]){
  for (int i = 0; i < count + 1; i++){
    Serial.print(list[i]);
    Serial.print(" ");
  }
  Serial.println();
}

void append(int list[], int next){
  int out[sizeof(list)+1];
  Serial.print("out1: ");
  printArray(out);
  for (int i = 0; i < sizeof(list); i++){
    out[i] = list[i];
  }
  Serial.print("out2: ");
  printArray(out);
  out[sizeof(list)] = next;
  list = out;
}

int average(int list[]){
  int sum = 0;
  for (int i = 0; i < sizeof(list); i++){
    sum += list[i];
  }
  return sum/sizeof(list);
}
