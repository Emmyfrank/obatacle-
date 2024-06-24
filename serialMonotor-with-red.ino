
const int motorA1 = 2;
const int motorA2 = 3;
const int motorB1 = 4;
const int motorB2 = 5;
const int enableA = 9;
const int enableB = 10;
const int redLEDPin = 11;

// Variable to store incoming serial data
char incomingCommand;

void setup() {
  // Initialize motor pins as outputs
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(redLEDPin, OUTPUT);

  // Initialize serial communication at 9600 bps
  Serial.begin(9600);
  Serial.println("Robot Control Initialized");
}

void loop() {
  // Check if data is available on the serial port
  if (Serial.available() > 0) {
    // Read the incoming byte
    incomingCommand = Serial.read();
    
    // Print the command for debugging
    Serial.print("Received command: ");
    Serial.println(incomingCommand);
    
    // Handle the command only if it is a valid character
    if (incomingCommand == 'F' || incomingCommand == 'B' || incomingCommand == 'L' || incomingCommand == 'R' || incomingCommand == 'S' || incomingCommand == 'O' || incomingCommand == 'X') {
      switch (incomingCommand) {
        case 'F': // Move forward
          Serial.println("Command: Move Forward");
          moveForward();
          break;
        case 'B': // Move backward
          Serial.println("Command: Move Backward");
          moveBackward();
          break;
        case 'L': // Turn left
          Serial.println("Command: Turn Left");
          turnLeft();
          break;
        case 'R': // Turn right
          Serial.println("Command: Turn Right");
          turnRight();
          break;
        case 'S': // Stop
          Serial.println("Command: Stop");
          stopMotors();
          break;
        case 'O': // Turn on red LED
          Serial.println("Command: Turn On Red LED");
          turnOnRedLED();
          break;
        case 'X': // Turn off red LED
          Serial.println("Command: Turn Off Red LED");
          turnOffRedLED();
          break;
        default:
          // Do nothing for invalid commands
          break;
      }
    }
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

void moveBackward() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
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
  stopMotors();
}

void turnLeft() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(enableA, 255);
  analogWrite(enableB, 255);
  delay(500); // Turn for 0.5 seconds
  stopMotors();
}

void stopMotors() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}

void turnOnRedLED() {
  digitalWrite(redLEDPin, HIGH);
}

void turnOffRedLED() {
  digitalWrite(redLEDPin, LOW);
}

void blinkRedLED(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(redLEDPin, HIGH);
    delay(5); // LED on for 0.1 seconds
    digitalWrite(redLEDPin, LOW);
    delay(5); // LED off for 0.1 seconds
  }
}
