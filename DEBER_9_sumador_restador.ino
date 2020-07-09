/*
 *---------------SUMADOR RESTADOR-------------
 *NOMBRE: Irma Túquerres
 *Deber 9
 */
#include<LiquidCrystal.h>//libreria lcd
LiquidCrystal lcd{13,12,11,10,9,8};
int suma;
int resta;
int num1;
int num2;
int a=0;
int b=0;
int c=0;

int d=0;
String dato;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  attachInterrupt(0,operacion,FALLING);//no hay delay dentro delas interrupciones
 Serial.println("Ingrese un numero en el rango de los positivos");
 
}

void loop() {
  if(a==1){
  if(Serial.available()>0 && b==0){
    dato=Serial.readString();
    num1=dato.toInt();
    if(num1>0 ){
      //Serial.println(num1);
      Serial.println("Ingrese un segundo numero en el rango de los positivos");
      b=1;
    }
  }
  if(Serial.available()>0 && c==0){
    dato=Serial.readString();
    num2=dato.toInt();
    if(num2>0 && num1>0){
      Serial.println(" ");
      //Serial.println(num1);
      //Serial.println(num2);
      Serial.println("-------SUMA--------");
      Serial.println(num1+num2);
      c=1;
    }
  }
  
  }
  if(a==2 && d==0){
    Serial.println("---------RESTA-----");
    Serial.println(num1-num2);
    d=1;
  }

}
void operacion(){
  a++;
  switch (a){
    case 1:
      //Operacion de suma
      Serial.println(" ");
    break;
    case 2:
      //Operacion de resta
      Serial.println(" ");
      
    break;
    case 3:
      Serial.println("APAGADO");
      a=0;
    break;
  }
  
}


