#include "Servo.h"
Servo servo1;
int potPin = A0;
int servoPin = 2;
const int pinoLed = 10; //PINO DIGITAL UTILIZADO PELO LED
const int pinoLDR = A5; //PINO ANALÓGICO UTILIZADO PELO LDR
  
void setup(){
  servo1.attach(servoPin);
  Serial.begin(9600);  
  pinMode(pinoLed, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(pinoLDR, INPUT); //DEFINE O PINO COMO ENTRADA
}    
void loop(){
  //O VALOR 600 PODE SER AJUSTADO
  if(analogRead(pinoLDR) > 400){ //SE O VALOR LIDO FOR MAIOR QUE 600, FAZ
    digitalWrite(pinoLed, LOW); //APAGA O LED
    Serial.println(pinoLDR);
  }  
  else{ //SENÃO, FAZ
    Serial.println(pinoLDR);
    int inicio = 0;
    int fim = 20;
    int angle = analogRead(inicio);
    int angle1 = analogRead(fim);
    angle = map(angle,0,1023,0,180);
    servo1.write(angle1);
    delay(15);
    servo1.write(angle);
    digitalWrite(pinoLed, HIGH); //ACENDE O LED
  }  
}  
