#include <DIYables_LCD_I2C.h> // Library for the I2C Liquid Crystal Display
#include <ezButton.h>         // Library for simplified button handling and debouncing

// Initialize LCD: Address 0x27, 16 columns, 2 rows
DIYables_LCD_I2C lcd(0x27, 16, 2); 

// Initialize button on Digital Pin 13
ezButton button(13);  

// Variable to store the previous count to detect changes
unsigned long lastCount = 0;

void setup() {
  // Start Serial communication at 9600 baud for debugging
  Serial.begin(9600);
  
  // LCD Initialization
  lcd.init();               
  lcd.backlight();          // Turn on the LED backlight for visibility

  // Button Configuration
  button.setDebounceTime(50); // Ignore electrical noise/chatter for 50ms
  button.setCountMode(COUNT_FALLING); // Increment count when button is pressed (HIGH to LOW)
  
  // Initial Display
  lcd.setCursor(0, 0);
  lcd.print("System Ready");
  delay(1000);
  lcd.clear();
}

void loop() {
  // IMPORTANT: Must call loop() to allow Button to process the physical pin state
  button.loop(); 

  // Retrieve the current press count from the ezButton object
  unsigned long count = button.getCount();

  // Only update the display if the count has actually changed
  // This prevents the screen from flickering or refreshing unnecessarily
  if (lastCount != count) {
    // Log the new count to the Serial Monitor
    Serial.print("Button Pressed! Total Count: ");
    Serial.println(count); 

    // Update the LCD Display
    lcd.clear();         // Clear previous text
    lcd.setCursor(0, 0); // Position cursor at column 0, row 0
    lcd.print("Count: ");
    lcd.print(count);    // Display the numerical value

    // Update history variable so this block only triggers on the next press
    lastCount = count; 
  }
}