// Código Arduino 
#include "TimerMEF.h"
Timer t = Timer(0);

#define pinMD 9   ////////// PIN PWM
#define pinMI 8   ////////// PIN PWM
#define pinS1 30
#define pinS2 33

int V = 0;      ////////// Variable INT
bool S1 = 0;
bool S2 = 0;
bool MD = 0;
bool MI = 0;

int CB = 0;

int controlador_8 = 8;

void controlar(){
	/////////////////////////////// MEF para controlador_2
	switch (controlador_8) {
		case 3:
			MD=0;MI=0;
			if (t.get()>=1){controlador_8=5;CB=3;}
			break;
		case 5:
			MD=0;MI=1;
			if (S2){controlador_8=7;CB=CB-1;}
			break;
		case 7:
			MD=0;MI=1;
			if (!S2*(CB==0)){controlador_8=11;t.set(0);}
			if (!S2*(CB>0)){controlador_8=5;}
			break;
		case 8:
			MD=0;MI=0;
			if (S1){controlador_8=3;t.set(0);}
			break;
		case 11:
			MD=0;MI=1;
			if (t.get()>=0.6){controlador_8=8;}
			break;
	}
}

void setup(){
	// Definir cuales pines son salidas y cuales son entradas
  Serial.begin(9600);
	pinMode(pinMD, OUTPUT);
  pinMode(pinMI, OUTPUT);
  pinMode(pinS1, INPUT);
  pinMode(pinS2, INPUT);
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
  mostrarEstado(V);
	medir();
	controlar();
	actuar();
}

void medir(){
	S1 = digitalRead(pinS1);
  S2 = digitalRead(pinS2);
}

void actuar(){
  digitalWrite(pinMI, MI);
  digitalWrite(pinMD, MD);
}