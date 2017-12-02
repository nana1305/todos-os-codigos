
#include <Ultrasonic.h>
#include <Keypad.h>


bool typing = false;//salvar estado da senha
String senhaDigitada;
String senha = "4321";
int buzzer = 11;
long ultimoEstadoPorta;
bool alarmeAtivado;
int sensorPorta = 9;


const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {5, 4, 3, A0}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );








void setup() {
  Serial.begin(9600);

  pinMode(A0, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensorPorta, INPUT);

}

void loop() {
  int distanciaPorta = 0;
  
ultimoEstadoPorta = digitalRead(sensorPorta);

  /* if (Serial.available() > 0) {
     distanciaPorta = Serial.parseInt();
      Serial.print("ok");
    }*/
  char key = keypad.getKey();
  long now = millis();

  if ((now % 30000 == 0) && (sensorPorta)) {
    Serial.println("30 Segundos");
    Serial.println(now);
    tone(buzzer, 3000);
  }

  



  


  /*
    //alarmeAtivado = true;
    }
    else if (distanciaPorta > 10) {
    delay(1000);
    Serial.println(distanciaPorta);
    noTone;
    }*/
}
