// Pin configuration
const int TRIG_PIN = 6; 
const int ECHO_PIN = 7; 
const int LED_PIN  = 3; 
const int BUZZER_PIN = 4; // New buzzer pin
const int DISTANCE_THRESHOLD = 50; // Threshold set to 50cm

// Variables for measurement
float duration_us, distance_cm;

void setup() {
  Serial.begin(9600);         
  pinMode(TRIG_PIN, OUTPUT);  
  pinMode(ECHO_PIN, INPUT);   
  pinMode(LED_PIN, OUTPUT);   
  pinMode(BUZZER_PIN, OUTPUT); // Initialize buzzer as output
}

void loop() {
  // 1. Trigger the sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2); 
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10); 
  digitalWrite(TRIG_PIN, LOW);

  // 2. Measure the time for the echo to return
  duration_us = pulseIn(ECHO_PIN, HIGH);

  // 3. Calculate distance in centimeters
  distance_cm = 0.017 * duration_us;

  // 4. Logic: Compare distance against threshold
  if(distance_cm < DISTANCE_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);    // Turn LED on
    digitalWrite(BUZZER_PIN, HIGH); // Turn Buzzer on
  } else {
    digitalWrite(LED_PIN, LOW);     // Turn LED off
    digitalWrite(BUZZER_PIN, LOW);  // Turn Buzzer off
  }

  // 5. Output results to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500); 
}