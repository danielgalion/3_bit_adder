#define C_IN 6      // C_IN - dopełnienie dla pozycji "0"
#define Y_0 15      
#define Y_1 14      // litera w nazwie oznacza liczbę
#define Y_2 13      // cyfra określa numer pozycji cyfry w liczbie
#define X_0 9       
#define X_1 8       // X i Y to składniki dodawania
#define X_2 7       
#define V_0 19      // V to wynik
#define V_1 18      
#define V_2 17      // piny od 14 do 19, to odpowiednio na płytce piny od A0 do A5
#define V_3 16      // są to piny analogowe, jednak można z nich korzystać jak z pinów cyfrowych
                    // właśnie w taki sposób
// biblioteka do obsługi ekranu lcd
#include <LiquidCrystal.h>

// parametry konstruktora określają numery pinów na płytce Arduino
// podłączonych do ekranu
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// indeksy tablic odpowiadają pozycjom cyfr wyświetlanych liczb
int result[4] = {0, 0, 0, 0};
int x[3] = {0, 0, 0};
int y[3] = {0, 0, 0};
int c_in;
  
void setup() {
  // put your setup code here, to run once:
  // ustawnienie obsługi ekranu o wymiarach 16x2 znaków:
  lcd.begin(16, 2);
  
  // ustawienie pinów na "wejścia"
  // stany pinów są określane przez przełączniki lub bramki logiczne
  // "wejścia" ustawione na PULLUP ze względu na to 
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

// kod wczytywania sygnałów i wyświetlania znaków jest w całości w loop()
// zatem wyświetlany rezultat "mruga" z dużą częstotliwością
// można to zauważyć, patrząc na ekran pod kątem
void loop() {
  // put your main code here, to run repeatedly:
  // wczytywanie sygnałów dostarczonych do pinów (wysoki / niski):
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

  // wyświetlanie składników dodawania:
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

  // wyświetlanie wyniku dodawania
  lcd.print(" =");
  // określenie pozycji kursora:
  lcd.setCursor(12, 1); //column, row
  
  for (int i = 3; i >= 0; i--)
  {
    lcd.print(result[i]);
  }
  
  // opóźnienie ustawione w celu zmeniejszenia częstotliwości
  // "mrugania" wyniku, dzięki czemu jest czytelniejszy
  delay(20);
  lcd.clear();
}
