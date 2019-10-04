/*  
 * File:soil_moisture_sensor.ino
 * Desc: Record moisture level regularly
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

 // Calculate average Moisture Value
 int sense_Moisture=0;
 for(int i = 0; i < 10; i++){
   // 0 = no conductance (too dry); ~300 = lots of conductance (wet)
   sense_Moisture = sense_Moisture + analogRead(sensorPin);
   delay(1000); 
 }
 sense_Moisture = sense_Moisture/10.0;  

 // Send Moisture Value to serialport
 String sensorValue = "Analog Value:";
 sensorValue = sensorValue + sense_Moisture;
 Serial.println(sensorValue);   

 // Turn on or off the light based on dry/wet soil
 if (sense_Moisture < limit) {
   digitalWrite(13, HIGH);      // dry soil
 }
 else {
   digitalWrite(13, LOW);       // wet soil
 }

 delay(60000); // 1000 = 1 second, this is taking readings every 1 minute
}
