#include <SPI.h>
#include <UIPEthernet.h>
#include <utility/logging.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
byte mac[] = {0xDE, 0xED, 0xBA, 0xFE, 0xF1, 0x55};

// Callback function header
void callback(char *topic, byte *payload, unsigned int length);

EthernetClient ethClient;

// Dados do MQTT Cloud
PubSubClient client("m11.cloudmqtt.com", 16098, callback, ethClient);

// Funcçao que irá receber o retorno do servidor.
void callback(char *topic, byte *payload, unsigned int length)
{
  char c = payload;
  Serial.println(c);
  Serial.println(topic);

  if(topic == "portao"){
    
    }

  byte *p = (byte *)malloc(length);
  memcpy(p, payload, length);
  free(p);
}

void setup()
{
  Serial.begin(9600);
  Serial.println("Iniciando...");
  Ethernet.begin(mac);

  // Faz a conexão no cloud com nome do dispositivo, usuário e senha respectivamente
  if (client.connect("Arduino_Placa", "ARDUINO", "arduino"))
  {
    // Envia uma mensagem para o cloud no topic portao
    client.publish("portao", 1);

    // Conecta no topic para receber mensagens
    client.subscribe("Portao");
    client.subscribe("Lampada");
    
    Serial.println("conectado Temperatura");
  }else{
    Serial.println("erro ao conectar");  
  }
  
}

void loop()
{
  client.loop();
}
