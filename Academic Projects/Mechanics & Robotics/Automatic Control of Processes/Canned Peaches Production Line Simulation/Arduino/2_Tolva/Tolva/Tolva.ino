// Inicialización de variables -----------------------------

#include "TimerMEF.h"
Timer t = Timer(0);

#define pinMD 9   ////////// PIN PWM
#define pinMI 8   ////////// PIN PWM
#define pinS3 30
#define pinS4 32
#define pinS5 33
#define pinLV 25
#define pinStart 28
#define pinStop 29

int Banda = 0;      ////////// Variable INT
bool S3 = 0;
bool S4 = 0;
bool S5 = 0;
bool MD = 0;
bool MI = 0;
bool LV = 0;
bool stop = 0;
bool start = 0;

int CT = 0;
int CA = 0;

// ARDUINO // Controlar()
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int controlador_8 = 8;

void controlar(){
	/////////////////////////////// MEF para controlador_2
	switch (controlador_8) {
		case 3:
			MD=0;MI=1;LV=0;
			if (S5*!S4*(CA==0)){controlador_8=7;CT=CT-1;}
			if (S4*S5*(CA>0)){controlador_8=38;t.set(0);start=1;stop=0;CA=CA-1;}
			break;
		case 7:
			MD=0;MI=1;LV=0;
			if (!S5*(CT==0)){controlador_8=11;t.set(0);}
			if (!S5*(CT>0)){controlador_8=3;}
			break;
		case 8:
			MD=0;MI=0;LV=0;
			if (S3){controlador_8=3;CT=3;CA=1;}
			break;
		case 11:
			MD=0;MI=1;LV=0;
			if (t.get()>=0.6){controlador_8=8;}
			break;
		case 38:
			MD=0;MI=0;LV=1;
			if (t.get()>=3){controlador_8=3;start=0;stop=1;}
			break;
	}
}

void setup(){
	// Definir cuales pines son salidas y cuales son entradas
  Serial.begin(9600);
	pinMode(pinMD, OUTPUT);
  pinMode(pinMI, OUTPUT);
  pinMode(pinLV, OUTPUT);
  pinMode(pinS3, INPUT);
  pinMode(pinS4, INPUT);
  pinMode(pinS5, INPUT);
  pinMode(pinStart, OUTPUT);
  pinMode(pinStop, OUTPUT);
}

int estado_anterior = 0;
void mostrarEstado(int estado){
  if(estado_anterior != estado){
    Serial.print("Estado: ");
    Serial.println(estado);
    estado_anterior = estado;
  }
}

void loop(){
  mostrarEstado(Banda);
	medir();
	controlar();
	actuar();
}

void medir(){
	S3 = digitalRead(pinS3);
  S4 = digitalRead(pinS4);
  S5 = digitalRead(pinS5);
}

void actuar(){
  digitalWrite(pinMI, MI);
  digitalWrite(pinMD, MD);
  digitalWrite(pinLV, LV);
  digitalWrite(28,start);
  digitalWrite(29,stop);
}