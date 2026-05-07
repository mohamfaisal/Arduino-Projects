#include <Servo.h> // Includes the library needed for servo motor control

Servo myServo;  // Creates a servo object to control a physical servo

void setup() {
  // Starts serial communication at 9600 bps for debugging via Serial Monitor
  Serial.begin(9600);
  
  // Connects the servo signal wire to Digital Pin 9 (PWM enabled)
  myServo.attach(9);  
}

void loop() {
  // SENSE: Reads the voltage from the potentiometer on Analog Pin A0 (0 to 1023)
  int analogValue = analogRead(A0);

  // THINK: Scales the 10-bit analog input to a 0-180 degree rotational range
  // This translates the position of the knob to the position of the motor arm
  int angle = map(analogValue, 0, 1023, 0, 180);

  // ACT: Moves the servo to the newly calculated angle
  myServo.write(angle); 

  // Feedback: Displays the raw input and mapped output in the Serial Monitor
  Serial.print("Analog Input: ");
  Serial.print(analogValue);
  Serial.print(" | Servo Angle: ");
  Serial.println(angle);

  // Short delay to allow the motor to reach its position and prevent jitter
  delay(15); 
}