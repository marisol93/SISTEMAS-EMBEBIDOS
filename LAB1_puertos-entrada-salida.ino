int decenas,unidades;
int entrada=10;
int salida=9;
int valor=0;
int dece =12;
int unid =11;
int tecla=0;
int on=0;
int on2=0;
int on3=0;
int A=7;//
int B=6;//pines del decodificador
int C=5;//
int D=4;//
void setup() {
  Serial.begin(9600);
  pinMode(13,INPUT);
  pinMode(dece,OUTPUT);
  pinMode(unid,OUTPUT);
  pinMode(entrada,INPUT);
  pinMode(salida,INPUT);
   pinMode(7,OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(4, OUTPUT);
  Serial.print("");
}

void loop() {
  
  if (digitalRead(13)==HIGH){
    Serial.println("ACTIVADO");
    on3=1;
    delay(200);
  }
  if(digitalRead(10)==HIGH &&digitalRead(9)==LOW&& on3==1&& valor<30 && valor>=0){//entrada 
    on=1;
    delay(200);
  }
  if (on==1){
    if(digitalRead(9)==HIGH&&digitalRead(10)==LOW && on3==1&& valor<30 && valor>=0){
      tecla++;
      valor++;
      on=0;
      on3=0;
      delay(200);
      Serial.println("N° total de pasajeros que han usado el servicio de bus:");
      Serial.println(tecla);
      if(valor==30){ //si el valor llega a 20 muestra q ya esta lleno
        Serial.println("Esta lleno");
      }
      
    }
  }
  
  if(digitalRead(9)==HIGH && digitalRead(10)==LOW && on3==1&& valor<=30 && valor>=0){//salida
    on2=1;
  }
  if (on2==1){
    if(digitalRead(10)==HIGH && digitalRead(9)==LOW &&on3==1&& valor<=30 && valor>=0){
      valor--;
      on2=0;
      on3=0;
      delay(200);
      if(valor==0){ //si el valor llega a 0 muestra q ya esta vacio
        Serial.println("Esta vacio");
       }  
    }
  }

 decenas=valor/10;
   unidades=(valor-decenas*10);

 digitalWrite (dece,1);//ACTIVA DECENAS
  digitalWrite (unid,0);//DESACTIVA UNIDADES
  numeros(decenas);
  delay(100);
  
  digitalWrite (dece,0);//DESACTIVA DECENAS
  digitalWrite (unid,1);//ACTIVA UNIDADES
  numeros(unidades);
  delay(100);
  

}
void numeros(int m) {
      if(m== 0){
      digitalWrite(7,0);
      digitalWrite(6,0);
      digitalWrite(5,0);
      digitalWrite(4,0);
      }
      if(m== 1){
      digitalWrite(7,1);
      digitalWrite(6,0);
      digitalWrite(5,0);
      digitalWrite(4,0);
      }
      if(m== 2){
      digitalWrite(7,0);
      digitalWrite(6,1);
      digitalWrite(5,0);
      digitalWrite(4,0);
      }
      if(m==3){
      digitalWrite(7,1);
      digitalWrite(6,2);
      digitalWrite(5,0);
      digitalWrite(4,0);
      }
      if(m== 4){
      digitalWrite(7,0);
      digitalWrite(6,0);
      digitalWrite(5,1);
      digitalWrite(4,0);
      }
      if(m== 5){
      digitalWrite(7,1);
      digitalWrite(6,0);
      digitalWrite(5,1);
      digitalWrite(4,0);
      }
      if(m==6){
      digitalWrite(7,0);
      digitalWrite(6,1);
      digitalWrite(5,1);
      digitalWrite(4,0);
      }
      if(m==7){
      digitalWrite(7,1);
      digitalWrite(6,1);
      digitalWrite(5,1);
      digitalWrite(4,0);
      }
      if(m==8){
      digitalWrite(7,0);
      digitalWrite(6,0);
      digitalWrite(5,0);
      digitalWrite(4,1);
      }
      if(m==9){
      digitalWrite(7,1);
      digitalWrite(6,0);
      digitalWrite(5,0);
      digitalWrite(4,1);
      }
  

}
