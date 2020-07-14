/*--------------------UTN-------------------
 * LABORATORIO 4:
 * NOMBRE: Irma Túquerres
 */
#include<EEPROM.h>
#include<MsTimer2.h>
#include<LiquidCrystal.h>
#include<avr/wdt.h>
LiquidCrystal lcd (13,12,11,10,9,A0);
int hora;
int minutos;
int cont=0;
String dato;
int camb=0;
int bloqueo=0;
int reinicio=0;
int contador=0;
int cont2=21;
int sensores=0;

int led1=7;
int led2=6;
int led3=5;
long numero;

void setup() {
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(4,INPUT);
  pinMode(8,INPUT);
  pinMode(3,INPUT);
  
  Serial.begin(9600);
  lcd.begin(16,2);
  MsTimer2::set(1000,reloj);
  MsTimer2::start();
  /*
  EEPROM.write(0,0);//limpiar las posiciones
  EEPROM.write(1,0);//de reloj
  EEPROM.write(2,1);//limpiar/guardar poscion de contraseña
  EEPROM.write(3,2);//
  EEPROM.write(4,3);//
  EEPROM.write(5,4);//posicon de contraseña
  */
  
  hora=EEPROM.read(0);//guarda estado de hora anterior
  minutos=EEPROM.read(1);//
  Serial.println("CONTRASEÑA ACTUAL");
  Serial.print(EEPROM.read(2));
  Serial.print(EEPROM.read(3));
  Serial.print(EEPROM.read(4));
  Serial.println(EEPROM.read(5));

  attachInterrupt(0,cambio,FALLING);
  Serial.println("Ingrese contraseña para activar alarmas");
  

}

void loop() {
  //-----------------------VALIDAR CONTRASEÑA--------------------------
  if (Serial.available()>0 && bloqueo==0){
    
    dato=Serial.readString();
    if(dato.substring(0,1).toInt()==EEPROM.read(2)&&
    dato.substring(1,2).toInt()==EEPROM.read(3)&&
    dato.substring(2,3).toInt()==EEPROM.read(4)&&
    dato.substring(3,4).toInt()==EEPROM.read(5)){//obteniedno posicion y comparando con EEPROM
      Serial.println("CONTRASEÑA CORRECTA");
      contador=1;
      bloqueo=1;
    }
    else{
      Serial.println("CONTRASEÑA INCORRECTA");
    }
  }
  //-------------------------CAMBIAR CONTRASEÑA-----------------------
  if (Serial.available()>0&&camb==1){
    dato=Serial.readString();
    Serial.println(dato.substring(0,1).toInt());
    Serial.println(dato.substring(1,2).toInt());
    Serial.println(dato.substring(2,3).toInt());
    Serial.println(dato.substring(3,4).toInt());
    if(dato.length()==4){
      Serial.println("CONTRASEÑA CAMBIADA");
      EEPROM.update(2,dato.substring(0,1).toInt());
      EEPROM.update(3,dato.substring(1,2).toInt());
      EEPROM.update(4,dato.substring(2,3).toInt());
      EEPROM.update(5,dato.substring(3,4).toInt());
      
      wdt_disable();
      wdt_enable(WDTO_30MS);//habilita reinicio
    }
    else{
      Serial.println("TAMAÑO  DE CONTRASEÑA INCORRECTA");
    }
  }
  //-----------------SENSORES---------------------
  if(digitalRead(4)==HIGH && digitalRead(8)==HIGH && digitalRead(3)&& sensores==1){
    MsTimer2::stop();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("INTRUSO");
    lcd.setCursor(0,1);
    lcd.print("LLAMANDO 911");
    sensores=0;
    
  }
 

}
void reloj(){
  minutos++;
  cont++;
  if(minutos==60){
    minutos=0;
    hora=hora+1;
  }
  if(hora==24){
    hora=0;
  }
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print(hora);
  lcd.setCursor(4,0);
  lcd.print(":");
  lcd.setCursor(5,0);
  lcd.print(minutos);
  lcd.setCursor(7,0);
  lcd.print(":00");

  if(cont==55){
    EEPROM.write(0,hora);
    EEPROM.write(1,minutos);
    cont=0;
  }
  //-----------------------CONTADOR 20SEGUNDOS-------------------
  
  if(contador==1){
    cont2--;
    lcd.setCursor(0,1);
    lcd.print(cont2);
    
  }
  if(cont2==0){
    contador=0;
    lcd.setCursor(0,1);
    lcd.print("SISTEMA ON");
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    numero=random(5,7);
    digitalWrite(numero,HIGH);
    sensores=1; 
  }
  
}
void cambio(){
  Serial.println("Ingrese una nueva contraseña");
  camb=1;
  bloqueo=1;
}

