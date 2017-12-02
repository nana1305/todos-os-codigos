//Criação de variáveis
//int = integer / Números inteiros
//pinoLedVermelho = Nome da variável
//11 = valor da variável / Número do pino que queremos controlar
int pinoLedVermelho = 12;

//Setup = Função/trecho de código que é executado uma única vez ao gravar
//o código no arduino
void setup() {
  // Função que configura a porta como INPUT ou OUTPUT
  // Tomem muito cuidado com os nomes, pois a linguagem 
 pinMode(pinoLedVermelho, OUTPUT);

}

void loop() {
  // Este loop é uma estrutura de repetiçaõ que entra em atividade
  // No momento em que o código for gravado no arduino, logo após a
  //execução do setup
  digitalWrite(pinoLedVermelho, HIGH);
  delay(1000);
  digitalWrite(pinoLedVermelho, LOW);
  delay(1000);

}
