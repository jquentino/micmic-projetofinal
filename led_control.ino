#include <SoftwareSerial.h>

SoftwareSerial serialbt(8, 9);
#define ledr 6
#define ledy 5

char valorbt;

void setup() {
  // put your setup code here, to run once:
  serialbt.begin(9600);
  pinMode(ledr, OUTPUT);
  pinMode(ledy, OUTPUT);
  digitalWrite(ledr, LOW);
  digitalWrite(ledy, LOW);
  Serial.begin(9600);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  Serial.println(serialbt.available());
  
  if (serialbt.available())
  {
    valorbt = serialbt.read();
    Serial.println(valorbt);
  }
  if (valorbt=='R'){
    digitalWrite(ledr, HIGH); //Acende led vermelho
  }
  
  if (valorbt=='r'){
    digitalWrite(ledr, LOW); //Apaga led vermelho
  }

  if (valorbt=='Y'){
    digitalWrite(ledy, HIGH); //Acende led amarelo
  }

  if (valorbt=='y'){
    digitalWrite(ledy, LOW); //Apaga led amarelo
  }

  if (valorbt=='A'){
    digitalWrite(ledr, HIGH); //Acende todos os leds
    digitalWrite(ledy, HIGH);
  }

  if (valorbt=='a'){
    digitalWrite(ledr, LOW); //Apaga todos os leds
    digitalWrite(ledy, LOW);
  }
}
