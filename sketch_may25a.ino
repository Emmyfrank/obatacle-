// Define motor pins
const int motorA1 = 2;
const int motorA2 = 3;
const int motorB1 = 4;
const int motorB2 = 5;
const int enableA = 9;
const int enableB = 10;

// Define ultrasonic sensor pins
const int trigPin = 7;
const int echoPin = 6;
const int redLEDPin = 11;

// Variable for duration and distance
long duration;
int distance;

void setup() {
  // Initialize motor pins as outputs
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(redLEDPin, OUTPUT);

  // Initialize ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initialize serial communication at 9600 bps
  Serial.begin(9600);
}

void loop() {
  // Check for obstacle
  checkObstacle();

  // If an obstacle is detected, turn the robot
  if (distance > 0 && distance < 30) { // distance threshold
    blinkRedLED(3);
    turnRight();
  } else {
    // Move forward by default
    moveForward();
  }
}

void moveForward() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(enableA, 255);
  analogWrite(enableB, 255);
}

void turnRight() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  analogWrite(enableA, 255);
  analogWrite(enableB, 255);
  delay(500); // Turn for 0.5 seconds
}

void checkObstacle() {
  // Clear the trigPin by setting it LOW:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin HIGH for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, returns the sound wave travel time in microseconds:
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance:
  distance = duration * 0.034 / 2;
}

void blinkRedLED(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(redLEDPin, HIGH);
    delay(5); // LED on for 0.1 seconds
    digitalWrite(redLEDPin, LOW);
    delay(5); // LED off for 0.1 seconds
  }
}

