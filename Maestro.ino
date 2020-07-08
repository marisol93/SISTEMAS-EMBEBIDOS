///////MASTER///////////////////
/*LABORATORIO 2
 * CAPITULO III: MODULOS DE COMUNICACION  I2C
 * CÓDIGO 12: envio y recepcion de datos por ex I2C
 * OBJETIVO: el usuario envia caracteres por comunicacion serial, master lo recibe
 * y envia por I2C hacia el esclavo y segun el dato enviado enciende un diferente led.
 * FUNCIONES: 
 *        wire.begin()
 *        Wire.beginTransmission(address)--->ID de esclavo
 *        
 */
 #include<Wire.h>//libreriai2c
 char dato;//variable de almacenamiento de datos
void setup() {
  Wire.begin();//inicia cx i2c
  Serial.begin(9600);//inicia cx serial
  // put your setup code here, to run once:

}

void loop() {
  if(Serial.available()>0){//verifica el puerto de cx
    dato=Serial.read();
    Wire.beginTransmission(4);
    Wire.write(dato);
    Wire.endTransmission();
  }
  // put your main code here, to run repeatedly:

}
