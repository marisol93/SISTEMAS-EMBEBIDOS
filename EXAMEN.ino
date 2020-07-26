/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 * Nombre: Irma Túquerres
 * Semestre: 7mo 
 * Evaluación Final
 */
#include "datos.h"

float promedio1a;
float promedio2a;
float promedio3a;

float promedio1b;
float promedio2b;
float promedio3b;

float promedio1c;
float promedio2c;
float promedio3c;

float promedio1d;
float promedio2d;
float promedio3d;


int cont1=0;
int cont2=0;
int cont3=0;
int cont4=0;

float distancia;
float vector[157];
int fil=0;
int col=0;

float maximo1=1;
float maximo2=1;
float maximo3=1;
float maximo4=1;

float peque[157];
float nuevo[48][4];
int contador=0;
int n=0;
float test[4]={8368,31308,8492,2};
int etiqueta;
float distanciaN=0;
float distmenor=10000;

int r=0;
int s=0;

void setup() {
  Serial.begin(9600);
  //----------------------CALLCULAR PROMEDIO DE COLUMNA X ETIQUETAS---------------
    for(int j=0;j<157;j++){
      if(matriz[j][3]==1){
        promedio1a=promedio1a+matriz[j][0];
        promedio2a=promedio2a+matriz[j][1];
        promedio3a=promedio3a+matriz[j][2];
        
      }
      if(matriz[j][3]==2){
        promedio1b=promedio1b+matriz[j][0];
        promedio2b=promedio2b+matriz[j][1];
        promedio3b=promedio3b+matriz[j][2];
        
      }
      if(matriz[j][3]==3){
        promedio1c=promedio1c+matriz[j][0];
        promedio2c=promedio2c+matriz[j][1];
        promedio3c=promedio3c+matriz[j][2];
        
      }
      if(matriz[j][3]==4){
        promedio1d=promedio1d+matriz[j][0];
        promedio2d=promedio2d+matriz[j][1];
        promedio3d=promedio3d+matriz[j][2];
        
      }
    }
    promedio1a=promedio1a/40;
    promedio2a=promedio2a/40;
    promedio3a=promedio3a/40;
    
    promedio1b=promedio1b/39;
    promedio2b=promedio2b/39;
    promedio3b=promedio3b/39;
    
    promedio1c=promedio1c/39;
    promedio2c=promedio2c/39;
    promedio3c=promedio3c/39;

    promedio1d=promedio1d/39;
    promedio2d=promedio2d/39;
    promedio3d=promedio3d/39;
    //-----------------IMPRIME PROMEDIOS-----------------
    Serial.print(promedio1a);
    Serial.print(",");
    Serial.print(promedio2a);
     Serial.print(",");
    Serial.println(promedio3a);
    
    Serial.print(promedio1b);
    Serial.print(",");
    Serial.print(promedio2b);
     Serial.print(",");
    Serial.println(promedio3b);

    Serial.print(promedio1c);
    Serial.print(",");
    Serial.print(promedio2c);
     Serial.print(",");
    Serial.println(promedio3c);

    Serial.print(promedio1d);
    Serial.print(",");
    Serial.print(promedio2d);
     Serial.print(",");
    Serial.println(promedio3d);
//---------------------CALCULAR LA DISTANCIA-----------------Realice la distancia entre el promedio encontrado y el resto de los datos de cada etiqueta.
for(;fil<157;fil++){
   
    if(matriz[fil][3]==1){
      distancia=pow(matriz[fil][0]-promedio1a,2)+pow(matriz[fil][1]-promedio2a,2)+pow(matriz[fil][2]-promedio3a,2);
    distancia=sqrt(distancia);
    vector[fil]=distancia;
  }
  if(matriz[fil][3]==2){
      distancia=pow(matriz[fil][0]-promedio1b,2)+pow(matriz[fil][1]-promedio2b,2)+pow(matriz[fil][2]-promedio3b,2);
    distancia=sqrt(distancia);
    vector[fil]=distancia;
  }
  if(matriz[fil][3]==3){
      distancia=pow(matriz[fil][0]-promedio1c,2)+pow(matriz[fil][1]-promedio2c,2)+pow(matriz[fil][2]-promedio3c,2);
    distancia=sqrt(distancia);
    vector[fil]=distancia;
  }
  if(matriz[fil][3]==4){
      distancia=pow(matriz[fil][0]-promedio1d,2)+pow(matriz[fil][1]-promedio2d,2)+pow(matriz[fil][2]-promedio3d,2);
    distancia=sqrt(distancia);
    vector[fil]=distancia;
  }
  Serial.println(vector[fil]);
}
//------------- CALCULAR MAXIMO1---------------
for(int l=0;l<157;l++){
  if(matriz[l][3]==1){
    if(vector[l]>maximo1){
      //aux=vector[l];
      maximo1=vector[l];  
    }
  }
  if(matriz[l][3]==2){
    if(vector[l]>maximo2){
      maximo2=vector[l];
    }
    }
    if(matriz[l][3]==3){
    if(vector[l]>maximo3){
      maximo3=vector[l];
    }
    }
    if(matriz[l][3]==4){
    if(vector[l]>maximo4){
      maximo4=vector[l];
    }
    }
  }

Serial.print("MAIXMO 1 : ");
Serial.println(maximo1);

Serial.print("MAIXMO 2 : ");
Serial.println(maximo2);

Serial.print("MAIXMO 3 : ");
Serial.println(maximo3);

Serial.print("MAIXMO 4 : ");
Serial.println(maximo4);

//-----------------------------------DIVIDIR POSICIÓN PARA MÁXIMO-----------------
for(int p=0;p<157;p++){
  if(matriz[p][3]==1){//solamente vamos atomar las etiquetas uno
    peque[p]=vector[p]/maximo1;
    
  }
  if(matriz[p][3]==2){//solamente vamos atomar las etiquetas uno
    peque[p]=vector[p]/maximo2;
    
  }
  if(matriz[p][3]==3){//solamente vamos atomar las etiquetas uno
    peque[p]=vector[p]/maximo3;
    
  }
  if(matriz[p][3]==4){//solamente vamos atomar las etiquetas uno
    peque[p]=vector[p]/maximo4;
    
  }
  Serial.println(peque[p]);
}
//----------------GUARDAR DATOS ENTRE 0.4 Y 0.65--------------
Serial.println("NUEVA BASE DE DATOS");
for(int m=0;m<157;m++){
  if (peque[m]>0.4 && peque[m]<0.65){
   for(int n=0;n<4;n++){
      nuevo[contador][n]=matriz[m][n];
      
 Serial.print(nuevo[contador][n]);
 Serial.print("  ");
 }
 contador++;
 Serial.println("");
  }
 }
 Serial.println("");
 Serial.print(" DISTANCIA DE LA NUEVA BASE DE DATOS");
  for(;r<48;r++){
    for(s=0;s<3;s++){
      distanciaN=distanciaN +pow(nuevo[r][s]-test[s],2);//DISTANCIA HACIA DATO INGRESADO
    }
    distanciaN=sqrt(distanciaN);
    Serial.println(distanciaN);
    if(distanciaN<distmenor){//ANALIZANDO DATO INGRESADO
      distmenor=distanciaN;
      etiqueta=nuevo[r][3];//encontrando la que etiqueta a la que pertenece el dato ingresado
    }
  }
  Serial.print("EL DATO INGRESADO PERTENECE A ETIQUETA: ");
  Serial.println(etiqueta);
}

void loop() {
  

}
