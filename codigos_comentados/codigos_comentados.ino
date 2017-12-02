#include <UIPEthernet.h>
#include <RestClient.h>

// Alterar o último valor para o id do seu kit
const byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xF1, 0x77 };
EthernetClient ethclient;

RestClient client = RestClient("192.168.3.186", 3000, ethclient);

//Sid, token, from são dados especificos do Twilio, são informações que eu vou pegar quando
// eu criar minha conta no Twilio

const char* sid = "AC9848c713c4f8d834a1a99b5ade904f60";
const char* token = "c4cede7f15c35be0622896d597833aba";

// É o número para o qual eu vou enviar a mensagem (pode ser o meu, o do proprietario da casa, etc)
const char* to = "5511984820042";

// From é o valor que eu vou pegar lá no Twilio, é um número internacional 
// que eu vou usar pra mandar mensagem

const char* from = "15744061737";

String response;

//Setup
void setup() {
  Serial.begin(9600);
  // Connect via DHCP
  if(Ethernet.begin(mac)) {
    Serial.println("Conectado via DHCP");
    Serial.print("IP recebido:"); Serial.println(Ethernet.localIP());
  }

  String parametros = "sid=";
  parametros.concat(sid);

  parametros.concat("&token=");
  parametros.concat(token);

  parametros.concat("&to=");
  parametros.concat(to);

  parametros.concat("&from=");
  parametros.concat(from);

  parametros.concat("&body=Mensagem Legal");

  Serial.println(parametros);

  /*  Isto (+=) está fazendo a mesma coisa que o .concat, só que o .concat é uma função
   *   que concatena as informações e por isso ocupa mais espaço na memória
   *   (concatenar = juntar as coisas)
   *   
  String parametros = "sid=";
  parametros += String(sid);

  parametros += String("&token=");
  parametros += String(token);

  parametros += String("&to=");
  parametros += String(to);

  parametros += String("&from=");
  parametros += String(from);

  parametros += "&body=Mensagem Legal";
  */

  int statusCode = client.post("/sms", parametros.c_str(), &response);
  if(statusCode != 500){
    // Ação para contornar o sms
    // Ligar para a policia
    // Avisar o vizinho do lado
    // Tocar buzzer irritante
  }
  Serial.print("Status da resposta: ");
  Serial.println(statusCode);
  Serial.print("Resposta do servidor: ");
  Serial.println(response);
  delay(1000);
}

void loop(){

}


void setup()
{
  Serial.begin(9600);
    //Serial.println(calculaPorcentagem(1023, 35));
}

void loop()
{
  //tipo void é quando a função não tem retorno
  int valor = 1023;
  double porcentagem = 35;
  
  float resultado = calculaPorcentagem(valor, porcentagem);
  
  Serial.println(porcentagem);
  
  if(resultado > 10){
    Serial.println("Porcentagem > 10");
  }
}

float calculaPorcentagem(int valor, double &porcentagem){
    // codigo envio sms
    porcentagem = 20;
  return (valor / 100) * porcentagem;
}
