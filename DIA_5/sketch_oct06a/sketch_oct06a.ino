int valorSensorTMP;
int portaSensorTMP = A0;
float temperatura = 0;
int Buzzer = 11;

void setup()
{Serial.begin(9600);
pinMode(Buzzer, OUTPUT);
}

void loop()
{
    valorSensorTMP = analogRead(portaSensorTMP);
    temperatura = valorSensorTMP * 0.1075268817204301;
    Serial.println(temperatura);
  
  if (temperatura > 25)
  {tone(Buzzer, 1000);}
  
  if (temperatura < 25)
  {noTone(Buzzer);}
  
}
