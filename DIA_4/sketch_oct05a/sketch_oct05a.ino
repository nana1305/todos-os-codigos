int Led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(Led, OUTPUT);
  
}

void loop() {
  if (Serial.available() > 0){
    char mensagem = Serial.read();
    Serial.print(mensagem);
    // == ele compara um valor com o outro
    if (mensagem == '1')
    {
    digitalWrite(Led, HIGH);}

    else 
    {digitalWrite(Led, LOW);}
  }
 
}
