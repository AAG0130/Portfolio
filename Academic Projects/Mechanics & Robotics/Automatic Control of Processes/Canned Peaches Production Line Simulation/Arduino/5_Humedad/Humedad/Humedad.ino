// Código Arduino 
#include "TimerMEF.h"
Timer t = Timer(0);

#define pinMD 9   ////////// PIN PWM
#define pinMI 8   ////////// PIN PWM
#define pinHmin 32
#define pinHmax 31
#define pinStopBanda 33
#define pinStart 23
#define pinStop 22

int V = 0;      ////////// Variable INT
bool Hmin = 0;
bool Hmax = 0;
bool start = 0;
bool stop = 0;
bool auxStop = 0;

int controlador_2 = 2;

void controlar(){
	/////////////////////////////// MEF para controlador_2
	switch (controlador_2) {
		case 2:
			V=0;
			if (start*!stop){controlador_2=6;t.set(0);}
			break;
		case 3:
			V=100;
			if (Hmax){controlador_2=10;}
			if (stop){controlador_2=2;}
			break;
		case 6:
			V=0;
			if (t.get()>=5){controlador_2=10;}
			if (stop){controlador_2=2;}
			break;
    case 10:
			V=80;
			if (!Hmin*!Hmax){controlador_2=3;}
			if (stop){controlador_2=2;}
			break;
	}
}

void setup(){
	// Definir cuales pines son salidas y cuales son entradas
  Serial.begin(9600);
	pinMode(pinMD, OUTPUT);
  pinMode(pinMI, OUTPUT);
  pinMode(pinHmin, INPUT);
  pinMode(pinHmax, INPUT);
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
	Hmin = digitalRead(pinHmin);
  Hmax = digitalRead(pinHmax);
  start = digitalRead(pinStart);
  stop = digitalRead(pinStop);
  auxStop = digitalRead(pinStopBanda);
}

void actuar(){
	switch(V){
    case 100:
      analogWrite(pinMI,0);
      analogWrite(pinMD,150);
      break;
    case 80:
      analogWrite(pinMI,150*!auxStop);
      analogWrite(pinMD,0);
      break;
    default:
      analogWrite(pinMI,255*!auxStop);
      analogWrite(pinMD,0);
      break;
  }
}