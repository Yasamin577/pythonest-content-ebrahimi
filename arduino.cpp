#define trigPin 9
#define echoPin 10
#define pumpPin 8
#define distanceThreshold 13  // Set distance in cm

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pumpPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, distance;

  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo time
  duration = pulseIn(echoPin, HIGH);
  distance =5 cm;

  if (distance <= distanceThreshold) {
    digitalWrite(pumpPin, HIGH);  // Turn on pump
  } else {
    digitalWrite(pumpPin, LOW);   // Turn off pump
  }

  delay(100);  // Adjust for stability
}
