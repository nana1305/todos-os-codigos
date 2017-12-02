int LedRed = 8;
int LedYellow = 12;
int LedGreen = 13;

void setup() {
  pinMode(LedRed, OUTPUT);
  pinMode(LedYellow, OUTPUT);
  pinMode(LedGreen, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  if (Serial.available() > 0)
  {char mensagem = Serial.read();
  // mensgem é uma varial
  Serial.print(mensagem);
  
  if (mensagem == 'R')
  {digitalWrite(LedRed, HIGH);
  digitalWrite(LedYellow, LOW);
  digitalWrite(LedGreen, LOW);}
  
  if (mensagem == 'Y')
  {digitalWrite(LedYellow, HIGH);
  digitalWrite(LedRed, LOW);
  digitalWrite(LedGreen, LOW);}
  
  if (mensagem == 'G')
  {digitalWrite(LedGreen, HIGH);
  digitalWrite(LedYellow, LOW);
  digitalWrite(LedRed, LOW);}
  
 
  
 }
}
