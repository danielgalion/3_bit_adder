#define C_IN 2
#define X 3
#define Y 4
#define C_OUT 13
#define C_IN_BUTTON 10
#define X_BUTTON 11
#define Y_BUTTON 12

void setup() {
  // put your setup code here, to run once:
  pinMode(C_IN, OUTPUT);
  pinMode(X, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(C_OUT, INPUT);
  pinMode(C_IN_BUTTON, INPUT_PULLUP);
  pinMode(X_BUTTON, INPUT_PULLUP);
  pinMode(Y_BUTTON, INPUT_PULLUP);
  digitalWrite(C_IN, LOW);
  digitalWrite(X, LOW);
  digitalWrite(Y, LOW);
  Serial.begin(9600);
}

int number = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(C_IN_BUTTON) == LOW) {
    number = 0;
    delay(20);
  } else if (digitalRead(X_BUTTON) == LOW) {
    number = 1;
    delay(20);
  } else if (digitalRead(Y_BUTTON) == LOW) {
    number = 2;
    delay(20);
  } else {
    number = 3;
    delay(20);
  }

  switch (number) {
    case 0:
      Serial.println("C_IN");
      break;
    case 1:
      Serial.println("X");
      break;
    case 2:
      Serial.println("Y");
      break;
    case 3:
      Serial.println("0");
      break;
    }
}
