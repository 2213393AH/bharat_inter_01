// Smart Parking System using Ultrasonic Sensor

// Define ultrasonic sensor pins
const int trigPin = 2;  // Trig pin of the ultrasonic sensor
const int echoPin = 3;  // Echo pin of the ultrasonic sensor

// Define LED pins for indicating parking availability
const int vacantLedPin = 4;   // Green LED indicating vacant parking
const int occupiedLedPin = 5; // Red LED indicating occupied parking

// Define distance threshold for detecting a vehicle (in centimeters)
const int vacantThreshold = 50; // Adjust this value depending on your setup

void setup() {
  // Initialize serial communication for debugging (optional)
  Serial.begin(9600);

  // Define pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(vacantLedPin, OUTPUT);
  pinMode(occupiedLedPin, OUTPUT);

  // Initialize LED states
  digitalWrite(vacantLedPin, LOW);
  digitalWrite(occupiedLedPin, LOW);
}

void loop() {
  // Send a brief pulse to the trigger pin to start measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the pulse from the echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance based on the speed of sound in air (343 meters per second)
  int distance = duration * 0.0343 / 2;

  // Uncomment the following line for debugging (optional)
  // Serial.print("Distance: ");
  // Serial.println(distance);

  // Check if the parking space is vacant or occupied
  if (distance > vacantThreshold) {
    // Parking space is vacant
    digitalWrite(vacantLedPin, HIGH);
    digitalWrite(occupiedLedPin, LOW);
  } else {
    // Parking space is occupied
    digitalWrite(vacantLedPin, LOW);
    digitalWrite(occupiedLedPin, HIGH);
  }

  // Add a small delay between measurements to reduce noise
  delay(500);
}
