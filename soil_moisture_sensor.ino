/*
  TE215 Soil Moisture Sensor
  Fletcher Bach | Dec. 2016

  Connect the Soil Moisture Sensor to anolog input pin 0
  Connect sensor's power to digital pin 7 on the Arduino
*/

//const long intervalDuration = 1800000; // wait half an hour = 1800000

void setup() {
  // Serial Begin so we can see the data from the sensor in our serial monitor.
  Serial.begin(9600);
}

void loop() {
  poll(0, 7, 1000);
}

void poll(int whichPin, int powerPin, long intervalDuration) {
  // Power-up the probe
  pinMode(probePowerPin, OUTPUT);
  digitalWrite(probePowerPin, HIGH);
  delay(1000);

  // Read the sensor and print the value
  int sensorValue = analogRead(whichPin);
  Serial.println(sensorValue);

  // Power-down the probe
  digitalWrite(probePowerPin, LOW);
  delay(intervalDuration);
}

