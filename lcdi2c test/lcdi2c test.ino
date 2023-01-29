#include <LiquidCrystal_I2C.h>
#include <wire.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}
void loop() {

  lcd.setCursor(3, 0);
  lcd.print("**********");
  lcd.setCursor(4, 1);
  lcd.print("Hey you");

  delay(2000);  
  lcd.clear();
  
  lcd.setCursor(2, 0);
  lcd.print("How you doin");
  lcd.setCursor(5, 1);
  lcd.print("(^-^)");


  
  delay(2000);
  lcd.clear();
}