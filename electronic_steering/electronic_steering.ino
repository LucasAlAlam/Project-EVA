/*
 * This code reading AD values and apply to a linear transfer function to know the angle of a potentiometer
*/
int sensorPin = 15, numRead, angle; 
float sensorValue = 0, addRead = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  for (numRead = 0; numRead < 5000; numRead++)
  {
    sensorValue = analogRead(sensorPin);
    addRead = addRead + sensorValue;
  }
  sensorValue = addRead / 5000;
  angle = 0.06557377 * sensorValue - 122.7868852;
  Serial.println(angle);
  delay(250);
  addRead = 0;
}
