/* 
 *  testing liquid crystal display on arduino.
 */

// Import the Liquid Crystal library
#include <LiquidCrystal.h>

//Initialise the LCD with the arduino. LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int trigPin = 9;
const int echoPin = 10;

long duration;
int distanceCm, distanceInch;

void setup() {

   // Switch on the LCD screen
  lcd.begin(16, 2);
  // Print these words to my LCD screen
  lcd.print("Testing Display");
  // Initializes the interface to the LCD screen, and specifies the dimensions
  // (width and height) of the display
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm= duration*0.034/2;
  distanceInch = duration*0.0133/2;
  lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Distance: "); // Prints string "Distance" on the LCD
  lcd.print(distanceCm); // Prints the distance value from the sensor
  lcd.print(" cm");
  delay(10);
  lcd.setCursor(0,1);
  lcd.print("Distance: ");
  lcd.print(distanceInch);
  lcd.print(" in");
  delay(10);
}
