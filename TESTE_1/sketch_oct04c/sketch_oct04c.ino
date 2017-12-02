
 const int pinoled = 12;
  const int pinobotao = 11;
  const int pinoled2 = 13;
  int estadobotao = LOW;
  int estadoled = 12;
  

void setup() {
 pinMode(pinobotao, INPUT);
 pinMode(pinoled, OUTPUT);
 pinMode(pinoled2, OUTPUT);
}

void loop() {
  estadobotao = digitalRead(pinobotao);

  while(estadobotao == HIGH)
  {digitalWrite(pinoled2, LOW);
    digitalWrite(pinoled, HIGH);
  }

  do
  {digitalWrite(pinoled, LOW);
   digitalWrite(pinoled2, HIGH);}

}
