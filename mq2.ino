
void setup() {
  Serial.begin(9600);
  pinMode(D1, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(16, OUTPUT);
  
}

void loop() {

  digitalWrite(16, LOW);
  float sensor_volt;
  float RS_gas;
  float ration;
  int sensorValue = analogRead(A0);
/*
  for(int x = 0 ; x < 100 ; x++){
    sensorValue = sensorValue + analogRead(A0);
  }
  sensorValue = sensorValue/100;
*/
  //sensor_volt = (float)sensorValue/1024*5.0;
  sensor_volt = (float)sensorValue/1024*5.0;
  RS_gas = (5.0 - sensor_volt)/sensor_volt;
/* --- Resistance of sensor(RS): RS = (Vc/Vrl-1)*Rl --- */
  ration = RS_gas/10.0;
  
  if(sensorValue > 0){
    for(int z = 0 ; z < 2 ; z++){
      digitalWrite(D6, HIGH);
      delay(50);
      digitalWrite(D6, LOW);
      delay(50);
    }
    Serial.print("analogRead = ");
    Serial.println(sensorValue);

    Serial.print("sensor_volt =");
    Serial.println(sensor_volt);
  
    Serial.print("RS_ration = ");
    Serial.println(RS_gas);
  
    Serial.print("Rs/RO = ");
    Serial.println(ration);
    Serial.print("\n");
  }

  if(sensorValue > 0 && ration < 5.0){
    Serial.print("!!! BEWARE !!!\nRation Over standartd\n");
    Serial.print("\n\n\n");
    digitalWrite(D1, HIGH);
    delay(1000);
    digitalWrite(D1, LOW);
  }
  
  delay(1000);
  
}
