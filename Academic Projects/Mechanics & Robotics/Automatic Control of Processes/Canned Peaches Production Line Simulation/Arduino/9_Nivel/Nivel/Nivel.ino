// Código Arduino 
#include "TimerMEF.h"
Timer t = Timer(0);

#define pinMD 9   ////////// PIN PWM
#define pinMI 8   ////////// PIN PWM
#define pinNmin 32
#define pinNmax 31
#define pinStopBanda 33
#define pinStart 23
#define pinStop 22

int V = 0;      ////////// Variable INT
bool Nmin = 0;
bool Nmax = 0;
bool MD = 0;
bool MI = 0;
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
			V=1;
			if (Nmax){controlador_2=10;}
			if (stop){controlador_2=2;}
			break;
		case 6:
			V=0;
			if (stop){controlador_2=2;}
			if (t.get()>=1){controlador_2=10;}
			break;
		case 10:
			V=0;
			if (!Nmin*!Nmax){controlador_2=3;}
			if (stop){controlador_2=2;}
			break;
	}
}

void setup(){
	// Definir cuales pines son salidas y cuales son entradas
  Serial.begin(9600);
	pinMode(pinMD, OUTPUT);
  pinMode(pinMI, OUTPUT);
  pinMode(pinNmin, INPUT);
  pinMode(pinNmax, INPUT);
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
	Nmin = digitalRead(pinNmin);
  Nmax = digitalRead(pinNmax);
  start = digitalRead(pinStart);
  stop = digitalRead(pinStop);
  auxStop = digitalRead(pinStopBanda);
}

void actuar(){
  if(V){
    analogWrite(pinMI,0);
    analogWrite(pinMD,255);
  }else{
    analogWrite(pinMI,255*!auxStop);
    analogWrite(pinMD,0);
  }
}