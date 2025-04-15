// Soil moisture sensor with motor control
const int sensorPowerPin = 7;     // Digital pin to power sensor
const int moistureSensorPin = A1; // Analog pin to read moisture level :P
const int motorPin = 8;           // Digital pin to control the motor
int moisture = 0;

void setup() {
  pinMode(sensorPowerPin, OUTPUT);
  pinMode(moistureSensorPin, INPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  
  // Make sure motor is off 
  digitalWrite(motorPin, LOW);
}

void loop() {

  digitalWrite(sensorPowerPin, HIGH);
  delay(100); // wait to help sensor
  
  // Read the moisture vairible
  moisture = analogRead(moistureSensorPin);
  
  // Turn off soil sensor
  digitalWrite(sensorPowerPin, LOW);
  
  // Control the motor based on moisture 
  // making HIGH turns motor ON and LOW turns it OFF
  if (moisture > 300) {
    digitalWrite(motorPin, HIGH); 
    Serial.print(moisture);
    Serial.println(" (Motor on)");
  } else {
    digitalWrite(motorPin, LOW); 
    Serial.print(moisture);
    Serial.println(" (Motor off)");
  }
  
  delay(1000); // Wait a second before next reading so it dont lag
}
