/* soil_moisture_sensor.ino
 * Desc: Record moisture level every 10 seconds
 * Auth: (get tutorial link) modified by Jennifer Chang
 * Date: 2019/10/04 
 */

int sensorPin = A0; 
int sensorValue;  
int limit = 150;

void setup() {
 Serial.begin(9600);
 pinMode(13, OUTPUT);
}

void loop() {
 String sensorValue = "Analog Value:";
 sensorValue = sensorValue + analogRead(sensorPin);
 Serial.println(sensorValue);   // "Analog Value: 0" == no conductance (too dry); "300 or above"==lots of conductance (wet)

 if (sensorValue < limit) {
   digitalWrite(13, HIGH);      // Turns on light for dry soil
 }
 else {
   digitalWrite(13, LOW);       // Turns off light for wet soil
 }

 delay(10000); // 1000 = 1 second, this is taking readings every 10 secs 
}
