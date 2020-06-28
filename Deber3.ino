/*
 * CAPITULO II: PUERTOS DIGITALES
 * Nombre: Irma Túquerres
 * Semestre: 7mo 
 * Tarea 3: Realizar un contador binario hasta 6 bits. Cuando se presione 
 * un pulsador, se debe observar el aumento de la variable en su número 
 * binario visto en leds. 
 */
 
 int vector[]={13,12,11,10,9,8};//declarar un vector con todas las posiciones del arduino a utilizar con los leds
 int btn=3;//declarar un boton que sirve para hacer el aumento de las variables
 int cont=0;//el encargado del coteo de los pulsos del boton
 
void setup() {
  int i=0;
  for(i=0;i<6;i++){
  pinMode(vector[i],OUTPUT);//declara vector como salida
  }
  pinMode(btn,INPUT);//declara boton como salida
}

void loop() {
   int i=0,j=0;

  if(digitalRead(btn)==LOW){//el estado enque se condicione el boton se deb a la coneccion en el proteus si en bajo o alto
    delay(300);
     cont++;
        for(j=0;j<6;j++){
          if(((cont>>j)&1)==1){
            digitalWrite(vector[j],HIGH);
        }
        else digitalWrite(vector[j],LOW);
      }
      delay(200);
    }
}
