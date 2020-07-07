/*
 * Nombre: Irma Túquerres
 * DEBER 8:Realice un programa donde se ingrese por comunicación serial la velocidad máxima y mínima de un motor en DC (no servo) . Donde su velocidad es controlada por un conversor análogo digital.  
 * Estos valores deben observarse en una LCD.
 */
 
#include<LiquidCrystal.h>//libreria lcd
 LiquidCrystal lcd{13,12,11,10,9,8};
 int conversor;
 int motor=6;
 int minimo;
 int maximo;
 String dato;
 int cmin=0;
 int cmax=1;
 int comparar=0;
 int potenciometro=0;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  //pinMode(motor,OUTPUT);
  Serial.println("Ingrese el valor minimo mayor que 0 y menor que 180");
}

void loop() {
  //-----------------minimo-------------------------
  if (Serial.available()>0 && cmin==0){
    dato=Serial.readString();
    minimo=dato.toInt();
    if(minimo<=180 && minimo>0){
      Serial.println(" ");
      Serial.println("numero Correcto");
      //Serial.println(minimo);
      cmin=1;
      cmax=0;
      Serial.println("ingrese valor maximo entre 0 y 180");
    }
    else{
      Serial.println(" ");
      Serial.println("Numero incorrecto");
    }
  }
  // ----------------MAXIMO--------------------------
if (Serial.available()>0 && cmax==0){
    dato=Serial.readString();
    maximo=dato.toInt();
    if(maximo<=180 && maximo>0){
      Serial.println(" ");
      Serial.println("numero Correcto");
      //Serial.println(maximo);
      //Serial.println(minimo);
      cmax=1;
      comparar=1;
    }
    else{
      Serial.println(" ");
      Serial.println("Numero incorrecto");
    }
  }
  //---------------------------COMPARAR--------------
  if(comparar==1){
    if(maximo>minimo){
      Serial.print("MAXIMO: ");
      Serial.println(maximo);
      Serial.print("MINIMO: ");
      Serial.println(minimo);
      comparar=0;
      potenciometro=1;
    }
    else{
      Serial.println("EL MINIMO NO PUEDE SER IGUAL O MAYOR QUE MAXIMO");
      cmin=0;
      Serial.println("Ingrese el valor minimo mayor que 0 y menor que 180");
      comparar=0;
    }
  }
  //-------------------potenciometro------------
  if(potenciometro==1){
    conversor=analogRead(0);
    conversor=map(conversor,0,1023,minimo,maximo);
    Serial.println(conversor);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("VELOCIDAD: ");
    lcd.print(conversor);
    analogWrite(motor,conversor);
    delay(400);
  }
}
