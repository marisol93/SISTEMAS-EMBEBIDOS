/*
 * LABORATORIO 6
 * 
 */
#include "datos.h"
 float test[5]={5.7,3,4.2,1.2,2};//datos sensores
 int fil=0;
 int col=0;
 float distancia;
 float distancia_menor=20000;
 float etiqueta;
 float vector[90];
 float dato;
 int k=10;
float vecino[10];
 
void setup() {
  Serial.begin(9600);
  for(;fil<90;fil++){
    for(col=0;col<4;col++){
      //distancia
      distancia=distancia +pow(matriz[fil][col]-test[col],2);
    }
    distancia=sqrt(distancia);
    vector[fil]=distancia;
    //Serial.println(vector[fil]);
    //Serial.println(distancia);
    /*
    if(distancia<distancia_menor){
      distancia_menor-distancia;
      etiqueta=matriz[fil][4];
    }
    */
  }
  //--------------------ORDENAR VECTOR---------------
  for(int i=0;i<90;i++){
    for(int j=0;j<(90);j++){
      if(vector[j]>vector[j+1]){
        dato=vector[j];
        vector[j]=vector[j+1];
       vector[j+1]=dato;
      }
    }
  }
  for(int l=0;l<90;l++){
    Serial.println(vector[l]);
  }
  //---------------------------BUSCANDO VECINOS------------
  for(int a=0;a<k;a++){
    vecino[a]=vector[a];
    Serial.print(" VECINOS");
    Serial.println(vecino[a]);
  }
   
  //Serial.println(String("datos son de etiqueta: ")+String(etiqueta));
  if(etiqueta==test[4]){
    Serial.println("Acierto");
    
  }
  else{
    Serial.println("Error");
  }
  // put your setup code here, to run once

}

void loop() {
  

}
