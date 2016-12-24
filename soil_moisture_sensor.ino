/*
  TE215 Soil Moisture Sensor
  Fletcher Bach | Dec. 2016
  
  Connect the Soil Moisture Sensor to anolog input pin 0
*/

//const long intervalDuration = 1800000; // wait half an hour = 1800000

void setup() {

  // Serial Begin so we can see the data from the sensor in our serial monitor.
  Serial.begin(9600);

}

void loop() {
  poll(0, 7, 1000);
}

void poll(int whichPin, int probePin, const long intervalDuration){
   // Power-up the probe
  digitalWrite(probePin, HIGH);
  delay(1000);
  
  sensorValue = analogRead(whichPin); 
  Serial.println(sensorValue); 
  
   // Power-down the probe
  digitalWrite(probePin, LOW);
  delay(intervalDuration);
}

