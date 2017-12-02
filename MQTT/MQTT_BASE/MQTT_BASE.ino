const int LedLampada = 9;
const int LedRed = 8;
const int LedYellow = 7;
const int LedGreen = 5;
const int BotaoLampada = 4;
const int BotaoPortao = 3;
int estadoBotaoL = LOW;
int estadoBotaoP = LOW;
int ultimoEstadoServoMotor = 30;
int ultimoEstadoBotao = LOW;

#include <Servo.h>
Servo microServo;
int pos = 0;
bool portaoAberto = false;
bool lampadaAcesa = false;

#include <SPI.h>
#include <UIPEthernet.h>
#include <utility/logging.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
byte mac[] = {0xDE, 0xED, 0xBA, 0xFE, 0xF1, 0x68};

// Callback function header
void callback(char *topic, byte *payload, unsigned int length);

EthernetClient ethClient;

// Dados do MQTT Cloud
PubSubClient client("m11.cloudmqtt.com", 16098, callback, ethClient);

// Funcçao que irá receber o retorno do servidor.
void callback(char *topic, byte *payload, unsigned int length)
{
  char c = payload[0];
  Serial.println(c);
  Serial.println(topic);
  

if (strcmp(topic, "Portao") == 0) {
    Serial.println(5);
    digitalWrite(LedYellow, HIGH);
    delay(500);
    digitalWrite(LedYellow, LOW);
    delay(500);
    digitalWrite(LedYellow, HIGH);
    delay(500);
    digitalWrite(LedYellow, LOW);
    
    if (c = 1) {
      Serial.println(7);
      if (ultimoEstadoServoMotor == 30) {
        abreFechaPortao(true);
        ultimoEstadoServoMotor = 120;
        delay (1000);
        
      }
    
  
      else {
        abreFechaPortao(false);
        ultimoEstadoServoMotor = 30;
        delay (1000);
      }
    }
  }

  if (strcmp(topic, "Lampada") == 0) {
    Serial.println(5);
    digitalWrite(LedYellow, HIGH);
    delay(500);
    digitalWrite(LedYellow, LOW);
    delay(500);
    digitalWrite(LedYellow, HIGH);
    delay(500);
    digitalWrite(LedYellow, LOW);

    if (c = 1) {
      Serial.println(7);
      if (ultimoEstadoBotao == HIGH) {
        acendeApagaLampada(false);
      } else {
        acendeApagaLampada(true);
      }

      if (ultimoEstadoBotao == HIGH) {
        ultimoEstadoBotao = LOW;

      } else {
        ultimoEstadoBotao = HIGH;
      }
      delay(1000);
    }
  }
}




void setup()
{
  Serial.begin(9600);
  Serial.println("Iniciando...");
  digitalWrite(LedYellow, HIGH);
  delay(1000);
  digitalWrite(LedYellow, LOW);
  delay(1000);
  digitalWrite(LedYellow, HIGH);
  delay(1000);
  digitalWrite(LedYellow, LOW);
  Ethernet.begin(mac);
  pinMode(LedLampada, OUTPUT);
  pinMode(LedRed, OUTPUT);
  pinMode(LedYellow, OUTPUT);
  pinMode(LedGreen, OUTPUT);
  pinMode(BotaoLampada, INPUT);
  pinMode(BotaoPortao, INPUT);
  microServo.attach(6);
  microServo.write(30);

  // Faz a conexão no cloud com nome do dispositivo, usuário e senha respectivamente
  if (client.connect("Arduino_Placa", "ARDUINO", "arduino"))
  {
    // Envia uma mensagem para o cloud no topic portao
    client.publish("Portao", 1);

    // Conecta no topic para receber mensagens
    client.subscribe("Portao");
    client.subscribe("Lampada");

    Serial.println("conectado");
    digitalWrite(LedGreen, HIGH);
  } else {
    Serial.println("erro ao conectar");
    digitalWrite(LedRed, HIGH);
  }

}

void loop()
{
  client.loop();

  estadoBotaoL = digitalRead(BotaoLampada);
  estadoBotaoP = digitalRead(BotaoPortao);


  if (estadoBotaoP == HIGH) {
    if (ultimoEstadoServoMotor == 30) {
      abreFechaPortao(true);
      ultimoEstadoServoMotor = 120;
      delay (1000);
    } else {
      abreFechaPortao(false);
      ultimoEstadoServoMotor = 30;
      delay (1000);
    }
    delay (1000);
    Serial.println("estadoBotaoP == HIGH");

  }
  estadoBotaoL = digitalRead (BotaoLampada);
  if (estadoBotaoL == HIGH) {
    if (ultimoEstadoBotao == HIGH) {
      acendeApagaLampada(false);
    } else {
      acendeApagaLampada(true);
    }

    if (ultimoEstadoBotao == HIGH) {
      ultimoEstadoBotao = LOW;

    } else {
      ultimoEstadoBotao = HIGH;
    }
    delay(1000);
  }
}

void abreFechaPortao(bool abre) {
  if (abre == true) {
    if (portaoAberto == false) {
      digitalWrite (LedLampada, HIGH);
      for (int pos = 30; pos <= 120; pos++) {
        microServo.write(pos);
        delay(10);
      }
      portaoAberto = true;
    }
  } else {
    if (portaoAberto == true) {
      for (int pos = 120; pos >= 30; pos--) {
        microServo.write(pos);
        delay(10);
      }
      portaoAberto = false;
    }
  }
}

void acendeApagaLampada(bool acende) {
  if (acende == true) {
    if (lampadaAcesa == false) {
      Serial.println("acende == true");
      digitalWrite(LedLampada, HIGH);
      lampadaAcesa = true;
    }
  }

  else {
    if (lampadaAcesa == true) {
      Serial.println("acende == false");
      digitalWrite(LedLampada, LOW);
      lampadaAcesa = false;
    }


  }
}
