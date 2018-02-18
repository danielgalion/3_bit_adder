#define C_IN 6
#define Y_0 15
#define Y_1 14
#define Y_2 13
#define X_0 9
#define X_1 8
#define X_2 7
#define V_0 19
#define V_1 18
#define V_2 17
#define V_3 16

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int result[4] = {0, 0, 0, 0};
int x[3] = {0, 0, 0};
int y[3] = {0, 0, 0};
int c_in;
  
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  
  pinMode(C_IN, INPUT_PULLUP);
  pinMode(X_0, INPUT_PULLUP);
  pinMode(Y_0, INPUT_PULLUP);
  pinMode(X_1, INPUT_PULLUP);
  pinMode(Y_1, INPUT_PULLUP);
  pinMode(X_2, INPUT_PULLUP);
  pinMode(Y_2, INPUT_PULLUP);
  
  pinMode(V_0, INPUT_PULLUP);
  pinMode(V_1, INPUT_PULLUP);
  pinMode(V_2, INPUT_PULLUP);
  pinMode(V_3, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  c_in = digitalRead(C_IN);
  
  x[0] = digitalRead(X_0);
  x[1] = digitalRead(X_1);
  x[2] = digitalRead(X_2);

  y[0] = digitalRead(Y_0);
  y[1] = digitalRead(Y_1);
  y[2] = digitalRead(Y_2);
  
  result[0] = digitalRead(V_0);
  result[1] = digitalRead(V_1);
  result[2] = digitalRead(V_2);
  result[3] = digitalRead(V_3);

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
  
  for (int i = 3; i >= 0; i--)
  {
    lcd.print(result[i]);
  }
  
  delay(20);
  lcd.clear();
}
