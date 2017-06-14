void setup(){
	Serial.begin(9600);
	int actuals[];
	int measured[];
}

void loop(){

	if (Serial.available() > 0){
		append(&actuals, Serial.parseInt());
		delay(100);
		int measurements[10];
		for (int i = 0; i < 10; i++){
			measurements[i] = analogRead(3);
		}
		append(&measured, average(measurements));

		Serial.print()

	}
}

void append(int *list, int next){
	int out[sizeof(list)+1];
	for (int i = 0; i < sizeof(list); i++){
		out[i] = list[i];
	}
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