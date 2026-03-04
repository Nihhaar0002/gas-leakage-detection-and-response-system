#include <Wire.h>                // Required for I2C communication
#include <LiquidCrystal_I2C.h>    // LCD library for I2C

#include <Servo.h>

Servo myservo;

const int buzzer = 7;       // Buzzer pin
const int servoPin = 10;    // Servo pin
const int relay = 6;        // Relay pin
const int mq = A0;          // MQ sensor pin (gas sensor)

// LCD configuration
LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address 0x27, 16 columns and 2 rows

void setup() {
  myservo.attach(servoPin);  // Attach the servo motor to pin 10
  pinMode(buzzer, OUTPUT);   // Set buzzer as output
  pinMode(relay, OUTPUT);    // Set relay as output
  pinMode(mq, INPUT);        // Set MQ sensor pin as input
  
  Serial.begin(9600);        // Initialize serial communication

  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.setBacklight(1);       // Turn on the backlight
  lcd.setCursor(0, 0);       // Set cursor to the first row
  lcd.print("Gas Monitoring");

  myservo.write(0);          // Start with the valve closed
  delay(1000);
}

void loop() {
  int gasConcentration = analogRead(mq);  // Read gas concentration from MQ sensor
  Serial.print("Gas Concentration: ");
  Serial.println(gasConcentration);

  // Display gas concentration on LCD
  lcd.clear();                         // Clear the previous screen
  lcd.setCursor(0, 0);                 // Set cursor to first line
  lcd.print("Gas Level: ");
  lcd.print(gasConcentration);         // Display gas concentration value

  // Check if gas concentration is above the threshold
  if (gasConcentration > 250) {
    // Gas concentration is high
    digitalWrite(buzzer, HIGH);        // Activate buzzer
    digitalWrite(relay, HIGH);         // Turn off relay (close the valve)

    // Display warning message on the LCD
    lcd.setCursor(0, 1);               // Set cursor to the second line
    lcd.print("Gas Leak Detected!");

    // Rotate servo to 90 degrees (close the valve)
    myservo.write(90);                 
    delay(1000);                       // Wait for the servo to move
  } else {
    // Gas concentration is safe
    digitalWrite(buzzer, LOW);         // Deactivate buzzer
    digitalWrite(relay, LOW);          // Turn on relay (open the valve)

    // Display normal status on the LCD
    lcd.setCursor(0, 1);               // Set cursor to second line
    lcd.print("Gas Level Safe");

    // Rotate servo to 0 degrees (open the valve)
    myservo.write(0);                  
    delay(1000);                       // Wait for the servo to move
  }

  delay(500);  // Small delay before the next reading
}