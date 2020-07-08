/////////////////ESCLAVO////////////7
/*Nombre Irma Túquerres
 * CAPITULO III: MODULOS DE COMUNICACION  I2C
 * CÓDIGO 12: envio y recepcion de datos por ex I2C
 * OBJETIVO: codificar mensaje secreto 
 *        wire.begin()
 */
 #include<Wire.h>//libreria isc
 #include<LiquidCrystal.h>
 LiquidCrystal lcd {13,12,11,10,9,8};//RS,E, D4 D5 D6 D7
 char dato;//
 String letra;
 String dato2;
 String codigo;
 int a=0;
 String total="";
 int tam;//variables a usar
int i=0;
int j=0;
int cont=0;
String salida;
void setup() {
  lcd.begin(16,2);
  Wire.begin(4);
  Wire.onReceive(receiveEvent);// 
  Serial.begin(9600);
}

void loop() {
  total="";
  codigo="";
  tam=0;
}
void receiveEvent (int bytes){//un metodo
  if(Wire.available()>0){
    //limpiar();
    dato=Wire.read();
    dato2=dato2+String(dato);
    tam=dato2.length();
    Serial.println(dato);
    Serial.println(dato2);
    Serial.println(tam);
    for(int i=0;i<tam;i++){
      letra=dato2.substring(i,i+1);//separando caracteres
      codificacion();//llamar al metodo para comparar y guardar
      total=total+codigo;//y guarda en codigo lo que almacena
      delay(200);
    }
    lcd.setCursor(0,1);
    lcd.print(total);
    lcd.setCursor(0,0);
    lcd.print(dato2);
 }
   
 }
 void codificacion(){
  if(letra=="A"){
    codigo="0";
  }
  if(letra=="B"){
    codigo="1";
  }
  if(letra=="C"){
    codigo="2";
  }
  if(letra=="D"){
    codigo="3";
  }
  if(letra=="E"){
    codigo="4";
  }
  if(letra=="F"){
    codigo="5";
  }
  if(letra=="G"){
    codigo="6";
  }
  if(letra=="H"){
    codigo="7";
  }
  
  if(letra=="I"){
    codigo="8";
  }
 
  if(letra=="J"){
    codigo="!";
  }
  if(letra=="K"){
    codigo="]";
  }
  if(letra=="L"){
    codigo=",";
  }
  if(letra=="M"){
    codigo=":";
  }
  if(letra=="N"){
    codigo=".";
  }
  if(letra=="O"){
    codigo="{";
  }
  if(letra=="P"){
    codigo="}";
  }
  if(letra=="Q"){
    codigo="-";
  }
  if(letra=="R"){
    codigo="*";
  }
  if(letra=="S"){
    codigo=")";
  }
  if(letra=="T"){
    codigo="(";
  }
  if(letra=="U"){
    codigo="&";
  }
  if(letra=="V"){
    codigo="/";
  }
  if(letra=="X"){
    codigo="%";
  }
  if(letra=="Y"){
    codigo="<";
  }
  if(letra=="Z"){
    codigo="/";
  }
 }
void limpiar(){
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
}


