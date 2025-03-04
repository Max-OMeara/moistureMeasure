// Moisture Sensor Arduino Code

#define ledPin 11
#define sensorPin A0

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}


int readSensor() {
  int sensorValue = analogRead(sensorPin);
  return sensorValue;
}

void loop() {
int currentSensorValue = readSensor();
  if (currentSensorValue < 1023) { // currentSensorValue < 102
    int outputValue = map(currentSensorValue, 0, 1023, 255, 0); // currentSensorValue < 102
    analogWrite(ledPin, outputValue);
  } else {
    analogWrite(ledPin, 0);
  }
  delay(1000);
}

