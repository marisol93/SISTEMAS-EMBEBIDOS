/*
 * Nombre: Irma Túquerres
 * Curso:
 */
#include <MsTimer2.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd{13,12,11,10,9,8};

int hora=0;
int minutos=0;
int a=0;
int b=0;
int c=0;
int d=0;
int e=0;

String dato;
int dato1;
int hh;
int mm;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  MsTimer2::set(1000,reloj);
  MsTimer2::start();
  attachInterrupt(0,on,FALLING);
  Serial.println("Ingrese la hora de alarma");

}

void loop() {
  ///--------------ALARMA-------
  if(d==2){
  if(Serial.available()>0 && b==0){
     dato=Serial.readString();
     hh=dato.toInt();
     if(hh<=23 && hh>=0){
      Serial.println("Ingrese el minuto");
      b=1;//para desactivar esta funcion una vez que termine 
     }
  }
  
  if(Serial.available()>0 && c==0){
     dato=Serial.readString();
     mm=dato.toInt();
     if(mm<=59 && mm>0){
      Serial.println(" ");
      Serial.println(mm);
      Serial.println(hh);
      c=1;
     }
     if(hh<=23 && mm<=59 && e==0){
     
      Serial.println(" ALARMA CONFIGURADA");
      Serial.println(hora);
      if(hh==hora && mm==minutos){
        MsTimer2::stop();
        Serial.println(" LEVANTARSE");
        
    }
    e=1;
   }
  }
  
 }

}
void reloj(){
  minutos++;
  if(minutos==60){
    minutos=0;
    hora++;
  }
  if(hora==24){
    hora=0;
  }
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hrs");
  lcd.setCursor(0,1);
  lcd.print(hora);
  
  lcd.setCursor(4,1);
  lcd.print(":");
  
  lcd.setCursor(7,0);
  lcd.print("Min");
  lcd.setCursor(7,1);
  lcd.print(minutos);
}

void on(){
  d++;
  switch (d){
    case 1:
      Serial.println("ENCENDIDO");
    break; 
    case 2:
      Serial.println(" ");
      Serial.println("ALARMA");
    break; 
    default:
    d=0;
  }
}
