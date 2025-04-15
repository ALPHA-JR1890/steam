// C++ code
//
int moisture = 0;

int Motor = 0;

void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(A0, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  moisture = analogRead(A1);
  digitalWrite(A0, LOW);
  digitalWrite(A2, LOW);
  if (moisture > 300) {
    Serial.print(moisture);
    Serial.println(" (Motor on)");
    digitalWrite(A2, LOW);
  } else {
    digitalWrite(A2, HIGH);
    Serial.print(moisture);
    Serial.println(" (Motor off)");
  }
  delay(1000); // Wait for 1000 milliseconds
  //problem was this code would confuse the arduino as the Analog pins were use more for input
}
