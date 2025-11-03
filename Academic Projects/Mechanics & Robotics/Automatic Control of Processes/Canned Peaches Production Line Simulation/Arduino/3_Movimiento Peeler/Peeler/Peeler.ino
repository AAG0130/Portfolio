// Inicialización de variables -----------------------------

#include "TimerMEF.h"
Timer t = Timer(0);

#define pinMD 9   ////////// PIN PWM
#define pinMI 8   ////////// PIN PWM
#define pinS6 30
#define pinS7 32
#define pinS8 33
#define pinStart 28
#define pinStop 29

int Banda = 0;      ////////// Variable INT
bool S6 = 0;
bool S7 = 0;
bool S8 = 0;
bool stop = 0;
bool start = 0;

int CP = 0;

// ARDUINO // Controlar()
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int controlador_8 = 8;

void controlar(){
	/////////////////////////////// MEF para controlador_2
	switch (controlador_8) {
		case 3:
			Banda=0;
			if (t.get()>=10){controlador_8=5;CP=3;}
			break;
		case 5:
			Banda=100;
			if (S7){controlador_8=35;}
			break;
		case 7:
			Banda=1;
			if (!S8*(CP==0)){controlador_8=11;t.set(0);stop=1;start=0;}
			if (!S8*(CP>0)){controlador_8=5;}
			break;
		case 8:
			Banda=0;
			if (S6){controlador_8=3;t.set(0);start=1;stop=0;}
			break;
		case 11:
			Banda=1;
			if (t.get()>=0.6){controlador_8=8;}
			break;
    case 35:
			Banda=1;
			if (S8){controlador_8=7;CP=CP-1;}
			break;
	}
}

void setup(){
	// Definir cuales pines son salidas y cuales son entradas
  Serial.begin(9600);
	pinMode(pinMD, OUTPUT);
  pinMode(pinMI, OUTPUT);
  pinMode(pinS6, INPUT);
  pinMode(pinS7, INPUT);
  pinMode(pinS8, INPUT);
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
	S6 = digitalRead(pinS6);
  S7 = digitalRead(pinS7);
  S8 = digitalRead(pinS8);
}

void actuar(){
	switch(Banda){
    case 100:
      analogWrite(pinMI,255);
      analogWrite(pinMD,0);
      break;
    case 0:
      analogWrite(pinMI,0);
      analogWrite(pinMD,0);
      break;
    default:
      analogWrite(pinMI,150);
      analogWrite(pinMD,0);
      break;
  }
  digitalWrite(28,start);
  digitalWrite(29,stop);
}