#include <LiquidCrystal.h>

// (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Water Sensor Connection
const int waterSensor = A0;


const int doneButton = 2;

// Water level thresholds
const int SMALL_LEVEL = 105;
const int MEDIUM_LEVEL = 120;
const int LARGE_LEVEL = 135;

// Prices
const float SMALL_PRICE = 1.00;
const float MEDIUM_PRICE = 1.50;
const float LARGE_PRICE = 2.00;

void setup() {

  lcd.begin(16, 2);

  pinMode(waterSensor, INPUT);

  pinMode(doneButton, INPUT_PULLUP);

  lcd.setCursor(0, 0);
  lcd.print("Fill Container");

  delay(2000);
  lcd.clear();
}

void loop() {

  // Read water level
  int waterLevel = analogRead(waterSensor);

  // Determine size and price
  String size;
  float price;

  if (waterLevel < SMALL_LEVEL) {

    size = "SMALL";
    price = SMALL_PRICE;

  }
  else if (waterLevel < MEDIUM_LEVEL) {

    size = "MEDIUM";
    price = MEDIUM_PRICE;

  }
  else {

    size = "LARGE";
    price = LARGE_PRICE;
  }

  // Display size
  lcd.setCursor(0, 0);
  lcd.print("Size: ");
  lcd.print(size);
  lcd.print("     ");

  // Display price
  lcd.setCursor(0, 1);
  lcd.print("Price: $");
  lcd.print(price, 2);
  lcd.print("     ");

  // Check DONE button
  if (digitalRead(doneButton) == LOW) {

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Thank You!");

    lcd.setCursor(0, 1);
    lcd.print(size);
    lcd.print(" $");
    lcd.print(price, 2);

    // Keep price displayed
    delay(5000);

    // Reset
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Fill Container");

    delay(1000);
  }

  delay(100);
}
