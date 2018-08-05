float sensorValue;

void setup() {
  Serial.begin(9600);
  pinMode(D5, INPUT);
  pinMode(D1, OUTPUT);
  pinMode(D6, OUTPUT);
}

void loop() {
  sensorValue = digitalRead(D5);
  Serial.print(sensorValue);
  Serial.print("\n");
  if (sensorValue == 1.0){
    digitalWrite(D6, LOW);
    digitalWrite(D1, HIGH);
  }
  else{
    digitalWrite(D1, LOW);
    digitalWrite(D6, HIGH);
  }
  delay(1000);
}
