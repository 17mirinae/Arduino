#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  // Print a message to the LCD.
  delay(1000);
}

void loop() {
  lcd.setCursor(0, 0);

  lcd.print("My Name Is NameNameName PhoneNumbers");
  lcd.setCursor(0, 1);

lcd.print("Is NameNameName PhoneNumbers   My Name ");
  for(int k = 0;k < 38;k++) {
    lcd.scrollDisplayRight();
    delay(500);
  }
}
