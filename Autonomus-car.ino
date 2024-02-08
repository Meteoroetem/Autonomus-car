// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //

#define echoPin 11 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 12//attach pin D3 Arduino to pin Trig of HC-SR04
#define motor1pin1 2
#define motor1pin2 3
#define motor2pin1 4
#define motor2pin2 5


// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
bool turnRight = false;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1,  OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  DriveForward();
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  if(distance <= 10){
    DriveBackward();
    //DriveBackwarAndRight();
    delay(500);
    //random(-1, 1) > 0 ? TurnLeft() : TurnRight();
    TurnRight();
    // turnRight = !turnRight;
    delay(200);
    DriveForward();
    delay(300);
  }
  else{
    //DriveForward();
  }
  #pragma region Debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  #pragma endregion
}

void DriveForward(){
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}
void DriveBackward(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}
void DriveBackwarAndRight(){
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}
void TurnLeft(){
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}
void TurnRight(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}