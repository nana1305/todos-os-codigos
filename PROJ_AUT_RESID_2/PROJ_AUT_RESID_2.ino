int LedLampada
int LedRed
int LedYellow
int LedGreen
int BotaoLampada
int BotaoPortao
int estadoBotaoL = LOW;
int estadoBotaoP = LOW;

#include <Servo.h>
Servo myservo;
int pos = 0;

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
}

void loop() {
estadoBotaoL = digitalRead(BotaoLampada);
if(estadoBotaoL == HIGH) 
{digitalWrite(LedLampada, HIGH)}

estadoBotaoP = digitalRead(BotaoPortao);




}
