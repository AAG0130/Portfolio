// Código Arduino 
#include "TimerMEF.h"
Timer t = Timer(0);

#define pinMD 9   ////////// PIN PWM
#define pinMI 8   ////////// PIN PWM
#define pinS9 30
#define pinS10 33
#define pinLV 25
#define pinStart 28
#define pinStop 29

int V = 0;      ////////// Variable INT
bool S9 = 0;
bool S10 = 0;
bool MD = 0;
bool MI = 0;
bool LV = 0;
bool stop = 0;
bool start = 0;

int CL = 0;

int controlador_8 = 8;

void controlar(){
	/////////////////////////////// MEF para controlador_2
	switch (controlador_8) {
		case 3:
			MD=0;MI=0;LV=1;
			if (t.get()>=1){controlador_8=5;CL=3;}
			break;
		case 5:
			MD=0;MI=1;LV=1;
			if (S10){controlador_8=7;CL=CL-1;}
			break;
		case 7:
			MD=0;MI=1;LV=1;
			if (!S10*(CL==0)){controlador_8=11;t.set(0);start=0;stop=1;}
			if (!S10*(CL>0)){controlador_8=5;}
			break;
		case 8:
			MD=0;MI=0;LV=0;
			if (S9){controlador_8=3;t.set(0);start=1;stop=0;}
			break;
		case 11:
			MD=0;MI=1;LV=0;
			if (t.get()>=0.6){controlador_8=8;}
			break;
	}
}

void setup(){
	// Definir cuales pines son salidas y cuales son entradas
  Serial.begin(9600);
	pinMode(pinMD, OUTPUT);
  pinMode(pinMI, OUTPUT);
  pinMode(pinS9, INPUT);
  pinMode(pinS10, INPUT);
  pinMode(pinStart, OUTPUT);
  pinMode(pinStop, OUTPUT);
  pinMode(pinLV, OUTPUT);
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
	S9 = digitalRead(pinS9);
  S10 = digitalRead(pinS10);
}

void actuar(){
  digitalWrite(pinMI, MI);
  digitalWrite(pinMD, MD);
  digitalWrite(pinLV, LV);
  digitalWrite(28,start);
  digitalWrite(29,stop);
}