int LedRed = 8;
int LedYellow = 12;
int LedGreen = 13;
int Buzzer = 6;


void setup() {
  pinMode(LedRed, OUTPUT);
  pinMode(LedYellow, OUTPUT);
  pinMode(LedGreen, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600);
  
}

void acendeApagaLed (int ledAceso, int ledApagado1, int ledApagado2)
{digitalWrite(ledAceso, HIGH);
 digitalWrite(ledApagado1, LOW);
 digitalWrite(ledApagado2, LOW);}

void apagaTudo (int LedRed, int LedYellow, int LedGreen)
{digitalWrite(LedRed, LOW);
digitalWrite(LedYellow, LOW);
digitalWrite(LedGreen, LOW);}

void loop() {
  if (Serial.available() > 0)
  {char mensagem = Serial.read();
  Serial.print(mensagem);
  
  switch (mensagem) {
    case 'R':
      acendeApagaLed(LedRed, LedYellow, LedGreen);
      break;
    case 'Y':
      acendeApagaLed(LedYellow, LedRed, LedGreen);
      break;
    case 'G':
      acendeApagaLed(LedGreen, LedYellow, LedRed);
      break; 
      
    
    default:
      apagaTudo(LedRed, LedYellow, LedGreen);
      tone(Buzzer, 1000);
      delay(1000);
      noTone(Buzzer);
      delay(1000);
      
      
      // if nothing else matches, do the default
      // default is optional
    break;
  }
  }
}
