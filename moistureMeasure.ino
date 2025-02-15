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
  if (currentSensorValue < 102) {
    int outputValue = map(currentSensorValue, 0, 102, 255, 0);
    analogWrite(ledPin, outputValue);
  } else {
    analogWrite(ledPin, 0);
  }
  delay(1000);
}

