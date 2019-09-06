/*
 * Tutorial: https://create.arduino.cc/projecthub/electropeak/complete-guide-to-use-soil-moisture-sensor-w-examples-756b1f
 */

#define SensorPin A0
float sensorValue = 0;

void setup(){
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop(){
  // put your main code here, to run repeatedly:
  for(int i = 0; i<= 100; i++){
    sensorValue = sensorValue + analogRead(SensorPin);
    delay(1);
  }
  sensorValue = sensorValue/100.0;
  Serial.println(sensorValue);
  delay(30);
}