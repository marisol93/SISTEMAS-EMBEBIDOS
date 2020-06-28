/*
 * CAPITULO II: PUERTOS DIGITALES
 * Nombre: Irma Túquerres
 * Semestre: 7mo 
 * Tarea 3: Realizar un contador binario hasta 6 bits. Cuando se presione 
 * un pulsador, se debe observar el aumento de la variable en su número 
 * binario visto en leds. 
 */
 
 int vector[]={13,12,11,10,9,8};
 int btn=3;
 int cont=0;
 
void setup() {
  int i=0;
  for(i=0;i<6;i++){
  pinMode(vector[i],OUTPUT);
  }
  pinMode(btn,INPUT);
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
