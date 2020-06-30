/*
*DEBER 4: conteo de numeros primos del 1 al 100 
*Nombre: Irma Túquerres
*Semestre: 7mo 
*
*/
int centenas,decenas,unidades;
int valor=0;
int cent=13;
int dece =12;
int unid =11;
int cont;
int  btn=3;
int A=7;//
int B=6;//pines del decodificador
int C=5;//
int D=4;
void setup() {
  Serial.begin(9600);
  pinMode(cent,OUTPUT);
  pinMode(dece,OUTPUT);
  pinMode(unid,OUTPUT);
  pinMode(btn,INPUT);
   pinMode(7,OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(4, OUTPUT);
  Serial.print("");// put your setup code here, to run once:

}

void loop() {
  int on3=0;
  int x;
  if(digitalRead(btn)==HIGH ){ //Si el dato ingresado es A entonces sumamos 1.. y lo mostramos no puede psarse de 20 ni de 0
   on3=1; 
  }
      for(cont=2;cont<100;cont++){
        boolean a=true;
        for(x=2;x<cont;x++){
          if(cont%x==0){
            valor++;
            delay(200);
          }
        }
        
       if(a==true){
        centenas=valor/100;
         decenas=(valor-centenas*100)/10;
         unidades=(valor-decenas*10);
         delay(200);
        }   
  digitalWrite(cent,1);//ACTIVA centenas
  digitalWrite (dece,0);//Desactiva Decenas
  digitalWrite (unid,0);//DESACTIVA Unidades
  numeros(centenas);
  delay(100);
  
  digitalWrite(cent,0);//DESACTIVA centenas
  digitalWrite (dece,1);//ACTIVA DECENAS
  digitalWrite (unid,0);//DESACTIVA UNIDADES
  numeros(decenas);
  delay(100);
  
  digitalWrite (cent,0);//Desactiva centenas
  digitalWrite (dece,0);//DESACTIVA DECENAS
  digitalWrite (unid,1);//ACTIVA UNIDADES
  numeros(unidades);
  delay(100);
} 
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
