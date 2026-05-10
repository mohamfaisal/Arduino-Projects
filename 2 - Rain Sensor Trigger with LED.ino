// Pin configuration
const int RAIN_SENSOR_PIN = A0;  // Connected to D0 on the sensor module
const int LED_PIN = 6;           // Matches the diagram (changed from 7 to 6)

void setup() {
  Serial.begin(9600);                
  pinMode(RAIN_SENSOR_PIN, INPUT);   
  pinMode(LED_PIN, OUTPUT);          
}

void loop() {
  // Read the sensor: HIGH means dry, LOW means water detected
  int rain_state = digitalRead(RAIN_SENSOR_PIN); 

  // The Logic: Water = LED OFF. Dry = LED ON.
  if (rain_state == LOW) { 
    // Water is connecting the metal lines!
    Serial.println("Rain detected! Turning LED OFF.");
    digitalWrite(LED_PIN, LOW);  // Turn LED OFF
  } 
  else {
    // The board is completely dry!
    Serial.println("It is dry! Turning LED ON.");
    digitalWrite(LED_PIN, HIGH); // Turn LED ON
  }
  
  delay(100); // Small pause to stabilize readings
}