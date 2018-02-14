#define C_IN 2
#define X_0 3
#define Y_0 4
#define X_1 5
#define Y_1 6
#define X_2 7
#define Y_2 8

void setup() {
  // put your setup code here, to run once:
  pinMode(C_IN, OUTPUT);
  pinMode(X_0, OUTPUT);
  pinMode(Y_0, OUTPUT);
  pinMode(X_1, OUTPUT);
  pinMode(Y_1, OUTPUT);
  pinMode(X_2, OUTPUT);
  pinMode(Y_2, OUTPUT);

  digitalWrite(C_IN, HIGH);
  digitalWrite(X_0, HIGH);
  digitalWrite(Y_0, HIGH);
  digitalWrite(X_1, HIGH);
  digitalWrite(Y_1, HIGH);
  digitalWrite(X_2, HIGH);
  digitalWrite(Y_2, HIGH);
}


void loop() {
  // put your main code here, to run repeatedly:

}
