#define RAIN_SENSOR_PIN  A0   // Sensor output connected to Analog Pin A0
#define LED_PIN          7    // LED connected to Digital Pin 7

int rain_state      = LOW;    // Variable to store the current sensor reading
int prev_rain_state = LOW;    // Variable to store the previous sensor reading

void setup() {
  Serial.begin(9600);                // Initialize Serial Monitor for data logging
  pinMode(RAIN_SENSOR_PIN, INPUT);   // Configure the rain sensor pin as an input
  pinMode(LED_PIN, OUTPUT);          // Configure the LED pin as an output
}

void loop() {
  // Update the state history
  prev_rain_state = rain_state;             
  
  // Read the current state of the sensor (Digital logic: HIGH/LOW)
  rain_state = digitalRead(RAIN_SENSOR_PIN); 

  // Detect the transition from 'Dry' to 'Rain' (LOW to HIGH)
  if (prev_rain_state == LOW && rain_state == HIGH) { 
    Serial.println("Rain detected!");
    digitalWrite(LED_PIN, HIGH); // Activate the LED
  }
  // Detect the transition from 'Rain' to 'Dry' (HIGH to LOW)
  else if (prev_rain_state == HIGH && rain_state == LOW) { 
    Serial.println("Rain stopped!");
    digitalWrite(LED_PIN, LOW);  // Deactivate the LED
  }
}