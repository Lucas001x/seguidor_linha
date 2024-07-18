#include "Adafruit_VL53L0X.h"
#include <ESP32Servo.h>

#define centro 1
#define esquerda 2
#define direita 3

static const int pinMotorDireitaF = 23;
static const int pinMotorEsquerdaF = 13;



Servo Roda_DireitaF;   // Frente de 90 -
Servo Roda_EsquerdaF;

int estadovaimeio = 1;


#define SERVO_GARRA 22 // Pino do ESP32 para o servo motor
#define SERVO_BASE 16 // Pino do ESP32 para o servo motor


// Servo garra; // Criação de um objeto Servo para controlar o motor
// Servo base; // Criação de um objeto Servo para controlar o motor
int estado = 1;
void setup() {
  Serial.begin(9600); // Inicialização da comunicação serial
  garra.attach(SERVO_GARRA); // Vincula o objeto Servo ao pino do motor
  base.attach(SERVO_BASE); // Vincula o objeto Servo ao pino do motor
  base.write(20);
  delay(1000);
  garra.write(20);
  delay(1000);
  Roda_DireitaF.attach(pinMotorDireitaF);
  Roda_EsquerdaF.attach(pinMotorEsquerdaF);
  
  

} 
// -----------------------------------------------------------------------Loop --------------------------------------------------------------------------------------------------------------------------------------    
void loop(){
  if (estado == 1){
    vaimeio();
    estado = 0;
  } 
  rodar();

//   if (centro <= /*6*/ true) {
//       pegarbola(); // Para o loop
//   } else if (direita > centro + 2 && esquerda > centro + 2) {
//       movefrente();
//   } else if (direita > esquerda + 2 && direita > centro + 2 ) {
//       rodadireita();
//   } else if (esquerda > direita +2 && esquerda > centro + 2) {
//       rodaesquerda();
//   } else {
//       roda();
//   }
 }
void vaimeio(){

  Roda_DireitaF.write(65);
  Roda_EsquerdaF.write(125);
 
  delay(3000);
  Roda_DireitaF.write(90);    //105
  Roda_EsquerdaF.write(90);  //125
}
void pegarbola(){

  base.write(20); //joga base para referencia
  delay(1000);
  garra.write(40); //abre garra 
  delay(1000);
  base.write(135); //desce base 
  delay(1000);
  garra.write(130); //fecha garra
  delay(1000);
  base.write(20); //sobe garra
  delay(1000);
}

void movefrente(){
  //move robo para frente
  for (direita > centro + 2 && esquerda > centro + 2) {
    Roda_DireitaF.write(65);
    Roda_EsquerdaF.write(125);
    delay(100);
  }
}

void rodadireita(){
  if(direita > esquerda + 2 && direita > centro + 2) {
    Roda_DireitaF.write(60);    //105
    Roda_EsquerdaF.write(60);
    delay(100);  //125
  }
  
}

void rodaesquerda(){
  if(esquerda > direita +2 && esquerda > centro + 2) {
    Roda_DireitaF.write(110);    //105
    Roda_EsquerdaF.write(120);
    delay(100);  //125
  }
}

void rodar(){
  Roda_DireitaF.write(110);    //105
  Roda_EsquerdaF.write(120);  //125
  delay(100);
  Roda_DireitaF.write(90);
  Roda_EsquerdaF.write(90); 
}


