int sensorPin = A0; 
int sensorValue;  
int limit =150;

void setup() {
 Serial.begin(9600);
 pinMode(13, OUTPUT);
}

void loop() {
 String sensorValue = "Analog Value:";
 sensorValue = sensorValue + analogRead(sensorPin);
 // sensorValue = analogRead(sensorPin); 
 //Serial.println("Analog Value : ");// + sensorValue);
 //Serial.println(sensorValue);
 Serial.println(sensorValue);

 if (sensorValue<limit) {
   digitalWrite(13, HIGH); 
 }
 else {
   digitalWrite(13, LOW); 
 }

 
 delay(10000); // 1000 = 1 second 
}
