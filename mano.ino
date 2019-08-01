#include <Servo.h>

Servo servo_d1;
Servo servo_d2;
Servo servo_d3;
Servo servo_d4;
Servo servo_d5;

const int flexpin = 0; 

const int boton_d1 = 8;
const int boton_d2 = 9;
const int boton_d3 = 10;
const int boton_d4 = 11;
const int boton_d5 = 12;

int estado_boton_d1 = 0;
int estado_boton_d2 = 0;
int estado_boton_d3 = 0;
int estado_boton_d4 = 0;
int estado_boton_d5 = 0;
 
int pos = 0;

void setup() {

 Serial.begin(9600);
  
 servo_d1.attach(2);
 servo_d2.attach(3);
 servo_d3.attach(4);
 servo_d4.attach(5);
 servo_d5.attach(6);

pinMode(boton_d1, INPUT);
pinMode(boton_d2, INPUT);
pinMode(boton_d3, INPUT);
pinMode(boton_d4, INPUT);
pinMode(boton_d5, INPUT);

}



void loop() {
  
  int flexposition;
  int servoposition;

  flexposition = analogRead(flexpin);

  servoposition = map(flexposition, 775, 900, 0, 180);
  servoposition = constrain(servoposition, 0, 180);
    servo_d5.write(servoposition);
 estado_boton_d1 = digitalRead(boton_d1);
 estado_boton_d2 = digitalRead(boton_d2);
 estado_boton_d3 = digitalRead(boton_d3);
 estado_boton_d4 = digitalRead(boton_d4);

 
 Serial.print("sensor: ");
  Serial.print(flexposition);
  Serial.print("  servo: ");
  Serial.println(servoposition);

 if (estado_boton_d1 == HIGH) {
     servo_d1.write(0);
  } else {
    servo_d1.write(180);
  }
 if (estado_boton_d2 == HIGH) {
     servo_d2.write(180);
  } else {
    servo_d2.write(0);
  }
 if (estado_boton_d3 == HIGH) {
     servo_d3.write(180);
  } else {
    servo_d3.write(0);
  }
 if (estado_boton_d4 == HIGH) {
     servo_d4.write(180);
  } else {
    servo_d4.write(0);
  }
}
