#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo myservo;

const int buzzer = 7;
const int servoPin = 10;
const int relay = 6;
const int mq = A0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  myservo.attach(servoPin);
  pinMode(buzzer, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(mq, INPUT);
  
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.setBacklight(1);
  lcd.setCursor(0, 0);
  lcd.print("Gas Monitoring");

  myservo.write(0);
  delay(1000);
}

void loop() {
  int gasConcentration = analogRead(mq);
  Serial.print("Gas Concentration: ");
  Serial.println(gasConcentration);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gas Level: ");
  lcd.print(gasConcentration);

  if (gasConcentration > 250) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(relay, HIGH);

    lcd.setCursor(0, 1);
    lcd.print("Gas Leak Detected!");

    myservo.write(90);
    delay(1000);
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(relay, LOW);

    lcd.setCursor(0, 1);
    lcd.print("Gas Level Safe");

    myservo.write(0);
    delay(1000);
  }

  delay(500);
}
