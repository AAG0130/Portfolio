// Código Arduino 
#include "TimerMEF.h"
Timer t = Timer(0);

#define pinMD 9   ////////// PIN PWM
#define pinMI 8   ////////// PIN PWM
#define pinCmin 32
#define pinCmax 31
#define pinStopBanda 33
#define pinStart 23
#define pinStop 22

int V = 0;      ////////// Variable INT
bool Cmin = 0;
bool Cmax = 0;
bool MD = 0;
bool MI = 0;
bool start = 0;
bool stop = 0;
bool auxStop = 0;

int CC = 0;

int controlador_8 = 8;

void controlar(){
	/////////////////////////////// MEF para controlador_2
	switch (controlador_8) {
		case 3:
			MD=0;MI=0;
			if (t.get()>5){controlador_8=42;}
			break;
		case 8:
			MD=0;MI=0;
			if (start*!stop){controlador_8=3;t.set(0);}
			break;
		case 40:
			MD=1;MI=0;
			if (Cmax){controlador_8=46;}
			break;
		case 42:
			MD=0;MI=0;
			if (!Cmax*!Cmin){controlador_8=40;t.set(0);}
			break;
		case 44:
			MD=0;MI=1;
			if (!Cmin){controlador_8=48;}
			break;
		case 46:
			MD=0;MI=0;
			if (t.get()>4){controlador_8=44;}
			break;
		case 48:
			MD=0;MI=0;
			if (stop){controlador_8=51;}
			break;
    case 51:
			MD=0;MI=1;
			if (auxStop){controlador_8=8;}
			break;
	}
}

void setup(){
	// Definir cuales pines son salidas y cuales son entradas
  Serial.begin(9600);
	pinMode(pinMD, OUTPUT);
  pinMode(pinMI, OUTPUT);
  pinMode(pinCmin, INPUT);
  pinMode(pinCmax, INPUT);
  pinMode(pinStart, INPUT);
  pinMode(pinStop, INPUT);
  pinMode(pinStopBanda, INPUT);
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
	Cmin = digitalRead(pinCmin);
  Cmax = digitalRead(pinCmax);
  start = digitalRead(pinStart);
  stop = digitalRead(pinStop);
  auxStop = digitalRead(pinStopBanda);
}

void actuar(){
  digitalWrite(pinMI, MI);
  digitalWrite(pinMD, MD);
}