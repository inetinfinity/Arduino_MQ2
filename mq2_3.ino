void setup() {
  Serial.begin(9600);
  pinMode(D1, OUTPUT);
  pinMode(16, OUTPUT);
}

float sensor_volt;
float RS_gas;
float H2;
float LPG;
float CO;
float Smoke;
float Alcohol;

void loop() {
  digitalWrite(16, LOW);
  float sensorValue = analogRead(A0);
  sensor_volt = (float)sensorValue/3379.2;
  RS_gas = (3.3 - sensor_volt)/sensor_volt;
  H2 = RS_gas/1.0;
  LPG = RS_gas/0.8;
  CO = RS_gas/3.2;
  Smoke = RS_gas/1.9;
  Alcohol = RS_gas/1.6;
  
  Serial.print("H2 = ");
  Serial.println(10-(H2/10));
  Serial.print("LPG = ");
  Serial.println(10-(LPG/10));
  Serial.print("CO = ");
  Serial.println(10-(CO/10));
  Serial.print("Smoke = ");
  Serial.println(10-(Smoke/10));
  Serial.print("Alcohol = ");
  Serial.println(10-(Alcohol/10));
  Serial.println(sensorValue);
  Serial.println("\n");
  
  if (sensorValue > 300){
    digitalWrite(D1, HIGH);
    delay(2000);
    digitalWrite(D1, LOW);
  }
  else if (sensorValue > 250){
    for(int x = 0 ; x < 2 ; x++){
      digitalWrite(D1, HIGH);
      delay(100);
      digitalWrite(D1, LOW);
    }
  }
  else if (sensorValue > 200){
     digitalWrite(D1, HIGH);
     delay(200);
     digitalWrite(D1, LOW);
  }
  delay(1000);
}
