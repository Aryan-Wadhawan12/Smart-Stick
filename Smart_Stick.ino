int dist = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  dist = 0.01723 * readUltrasonicDistance(5, 6);
  if (dist <= 40) {
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
  } else {
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
