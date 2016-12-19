/*
  TE215 Soil Moisture Sensor
  Fletcher Bach | Dec. 2016
  
  Connect the Soil Moisture Sensor to anolog input pin 0
*/

const int probe = 7;
const int moistureSensor = 0;
const int intervalDuration = 1800000 // wait half an hour = 1800000

void setup() {

  // Serial Begin so we can see the data from the sensor in our serial monitor.
  Serial.begin(9600);

}

void loop() {

  // Power-up the probe and pause for the driver
  digitalWrite(probe, HIGH);
  delay(1000);

  // read the input on analog pin 0:
  int sensorValue = analogRead(moistureSensor);

  // print out the value you read:
  Serial.println(sensorValue);

  // Power-down the probe
  digitalWrite(probe, LOW);
  delay(intervalDuration); 

}
