#define C_IN 6
#define X_0 9
#define Y_0 15
#define X_1 8
#define Y_1 14
#define X_2 7
#define Y_2 13

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int state[4] = {0, 0, 0, 0};
int x[3] = {0, 0, 0};
int y[3] = {0, 0, 0};
int c_in;
  
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);

  pinMode(16, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);

  pinMode(C_IN, INPUT_PULLUP);
  pinMode(X_0, INPUT_PULLUP);
  pinMode(Y_0, INPUT_PULLUP);
  pinMode(X_1, INPUT_PULLUP);
  pinMode(Y_1, INPUT_PULLUP);
  pinMode(X_2, INPUT_PULLUP);
  pinMode(Y_2, INPUT_PULLUP);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //lcd.print("Hello world!");
  c_in = digitalRead(C_IN);
  
  x[0] = digitalRead(X_0);
  x[1] = digitalRead(X_1);
  x[2] = digitalRead(X_2);

  y[0] = digitalRead(Y_0);
  y[1] = digitalRead(Y_1);
  y[2] = digitalRead(Y_2);
  
  for (int i = 0; i < 4; i++)
  {
    state[i] = digitalRead(i + 16);  
  }

  lcd.print(c_in);

  lcd.print(" + ");

  for (int i = 2; i >= 0; i--)
  {
    lcd.print(x[i]);  
  }

  lcd.print(" + ");

  for (int i = 2; i >= 0; i--)
  {
    lcd.print(y[i]);  
  }

  lcd.print(" =");
  lcd.setCursor(12, 1); //column, row
  
  for (int i = 0; i < 4; i++)
  {
    lcd.print(state[i]);  
  }
  
  delay(20);
  lcd.clear();
}
