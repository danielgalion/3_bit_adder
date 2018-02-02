#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int state[4] = {0, 0, 0, 0};
  
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);

  pinMode(16, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //lcd.print("Hello world!");

  for (int i = 0; i < 4; i++)
  {
    state[i] = digitalRead(i + 16);  
  }
  
  for (int i = 0; i < 4; i++)
  {
    lcd.print(state[i]);  
  }
  
  delay(20);
  lcd.clear();
}
