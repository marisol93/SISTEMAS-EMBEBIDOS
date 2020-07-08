/*
 * LABORATORIO 3:
 * NOMBRE: Irma Túquerres
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
int f=0;
int pot1;
int pot2;

int led1=7;
int led2=6;
int led3=5;
int led4=4;
int cont=0;
long randomn;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  MsTimer2::set(100,reloj);
  MsTimer2::stop();
  
  attachInterrupt(0,on,FALLING);
  attachInterrupt(1,on2,FALLING);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);

  
}

void loop() {

  if(e==1){
    MsTimer2::start();
    e=2;//para empezar el reloj 
    
  }
  if(e==3 && a==1 && f==0){
   randomn=random(4,7);
   digitalWrite(randomn,HIGH);
   cont++;
   delay(250);
   digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
   digitalWrite(led3,LOW);
   digitalWrite(led4,LOW);
   if (cont==40){
    f=1;
   }
  }
  if(a==2 && e==3){
    MsTimer2::stop();
    pot1=analogRead(0);
    pot2=analogRead(1);
    pot1=map(pot1,0,1023,0,59);
    pot2=map(pot2,0,1023,0,23);
    if(d==0){
    b=pot1;
    
    c=pot2;
    d=1;
    }
    
    if(b==pot1 &&c==pot2){
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(hora);
    lcd.print(":");
    lcd.print(minutos);
    delay(40);
    }
    if(b==pot1 && c!=pot2){
      lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(pot2);
    lcd.print(":");
    lcd.print(minutos);
    delay(40);
    }
    if(b!=pot1 && c==pot2){
      lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(hora);
    lcd.print(":");
    lcd.print(pot1);
    delay(40);
    }
    if(b!=pot1 && c!=pot1) {
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(pot2);
    lcd.print(":");
    lcd.print(pot1);
    delay(20);
    }
  // put your main code here, to run repeatedly:

}
if(a==3 && e==3){
  hora=pot2;
  minutos=pot1;
  MsTimer2::start();
  a=0;
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
  a++;
  switch (a){
    case 1:
      Serial.println(" MODO DE LUCES");
    break;
    case 2:
      Serial.println("MODO CONFIGURACION DE RELOJ");
    break;
    case 3:
      Serial.println("CONFIGURACION GUARDADA");
      
    break;
    
    default:
      a=0;
  }
}
void on2(){
  e++;
  switch (e){
    case 1:
      Serial.println("ENCENDIDO");
    break; 
    case 3:
      Serial.println("SELECCION DE MODO");
      MsTimer2::start();
    break;
    case 4:
      Serial.println("APAGADO");
      MsTimer2::stop();
      lcd.clear();
      
    break;
    default:
    e=0;
  }
}

