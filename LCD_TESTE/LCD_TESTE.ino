// Inclusão da biblioteca do sensor
// Essa biblioteca não vem por padrão com o arduino e 
// precisa ser instalada pelo gerenciador de bibliotecas
#include <Ultrasonic.h>
#include <LiquidCrystal.h>

// Inicializa o objeto do sensor ultrasônico
// Usando as portas 12 e 13 para trigger e echo
Ultrasonic ultrasonic(9, 10);

const int rs = 8, en = 7, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String msg;

void setup() {
  // Inicializa a porta Serial
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.print("Mensagem foi");

}

void loop() {

  if (Serial.available ()) {
    msg = Serial.readString ();
  // Lê o valor do sensor
 

  // Escreve o valor da distância no painel Serial
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(msg);
  delay (1000);
  for (int contador = 0; contador < 16;)
  lcd.scrollDisplayLeft();
  
}
}
