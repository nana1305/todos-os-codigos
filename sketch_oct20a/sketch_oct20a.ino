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


void setup() {
 Serial.begin(9600);
 pinMode(LedLampada, OUTPUT);
 pinMode(LedRed, OUTPUT);
 pinMode(LedYellow, OUTPUT);
 pinMode(BotaoLampada, INPUT);
 pinMode(BotaoPortao, INPUT);
 microServo.attach(6);
 microServo.write(30);
}

void loop() {
 estadoBotaoL = digitalRead(BotaoLampada);
 estadoBotaoP = digitalRead(BotaoPortao);


 if (estadoBotaoP == HIGH) {
   if (ultimoEstadoServoMotor == 30) {
     abreFechaPortao(true);
     ultimoEstadoServoMotor = 160;
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
     Serial.println("abre == true");
     for (int pos = 30; pos <= 160; pos++) {
       microServo.write(pos);
       delay(10);
     }
     portaoAberto = true;
   }
 } else {
   if (portaoAberto == true) {
     Serial.println("abre == false");
     for (int pos = 160; pos >= 30; pos--) {
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
