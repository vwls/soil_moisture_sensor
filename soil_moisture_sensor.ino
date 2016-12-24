/*
  TE215 Soil Moisture Sensor
  Fletcher Bach | Dec. 2016
  
  Connect the Soil Moisture Sensor to anolog input pin 0
  Connect sensor's power to digital pin 7 on the Arduino
*/

//const long intervalDuration = 1800000; // wait half an hour = 1800000
const int probePowerPin = 7;

void setup() {

  // Serial Begin so we can see the data from the sensor in our serial monitor.
  Serial.begin(9600);
  pinMode(probePowerPin, OUTPUT);

}

void loop() {
  poll(0, 1000);
}

void poll(int whichPin, long intervalDuration){
   // Power-up the probe
  digitalWrite(probePowerPin, HIGH);
  delay(1000);
  
  int sensorValue = analogRead(whichPin); 
  Serial.println(sensorValue); 
  
   // Power-down the probe
  digitalWrite(probePowerPin, LOW);
  delay(intervalDuration);
}

