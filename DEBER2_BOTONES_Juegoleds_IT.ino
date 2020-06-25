/*
 * Nombre: Irma Túquerres
 * Materia: Sistemas Embebidos
 * Tarea: Juego de led usando botones 
 
 INDICACIONES:
 * Realice un programa que al presionar un pulsador, active un juego de 6 luces led que solo se enciendan. Este juego se ejecutará 8 veces cada vez que se presione el pulsador. 
Con otro pulsador, active un juego de 6 luces led que encienda  y apague  en grupos de dos en dos de la forma:
1 y 6, 2 y 5 , 3 y 4
Este juego se ejecutará 10 veces cada vez que se presione este pulsador.

USO:
del ciclo for(i=0;i<8;i++){} para crear las reepticiones del juego de leds
 */
 const int Btn1=2;//declarar variables para asignar a los pines de los botones
 const int Btn2=3;
 const int led1=8;//asiganr nombres para identificar a los leds 
 const int led2=9;
 const int led3=10;
 const int led4=11;
 const int led5=12;
 const int led6=13;
 int i;//declarar las variables para contador de los ciclos 
 int j;
void setup() {
  pinMode(Btn1,INPUT);//asiganr al pin si sera de salida o entrada 
  pinMode(Btn2,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);

}

void loop() {
  if(digitalRead(Btn1)==HIGH){//if para validar que con 1 se active el juego de leds
    for(i=0;i<=7;i++){//ciclos for para las repeticiones de 8 veces 
    digitalWrite(led1,HIGH);
    delay(300);
    digitalWrite(led1,LOW);
    delay(300);
    digitalWrite(led2,HIGH);
    delay(300);
    digitalWrite(led2,LOW);
    delay(300);
    digitalWrite(led3,HIGH);
    delay(300);
    digitalWrite(led3,LOW);
    delay(300);
    digitalWrite(led4,HIGH);
    delay(300);
    digitalWrite(led4,LOW);
    delay(300);
    digitalWrite(led5,HIGH);
    delay(300);
    digitalWrite(led5,LOW);
    delay(300);
    digitalWrite(led6,HIGH);
    delay(300);
    digitalWrite(led6,LOW);
    delay(300);
    }
  }
  if(digitalRead(Btn2)==(HIGH)){//verificar si el boton dos esta en alto y activar el juego de leds
    for(j=0;j<=9;j++){//realiza las repetciones de 10 veces
      digitalWrite(led1,HIGH);
      digitalWrite(led6,HIGH);
      delay(300);
      digitalWrite(led1,LOW);
      digitalWrite(led6,LOW);
      delay(300);
      digitalWrite(led2,HIGH);
      digitalWrite(led5,HIGH);
      delay(300);
      digitalWrite(led2,LOW);
      digitalWrite(led5,LOW);
      delay(300);
      digitalWrite(led3,HIGH);
      digitalWrite(led4,HIGH);
      delay(300);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      delay(300);
    }
  }
  

}
