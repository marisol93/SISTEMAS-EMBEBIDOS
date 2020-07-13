/*
 * Deber 12:
 * Nombre: Irma Túquerres
 */
 #include<MsTimer2.h>//libreria 
 #include<LiquidCrystal.h>//libreria
 #include<avr/wdt.h>//libreria 
 LiquidCrystal lcd (13,12,11,10,9,8);//delclacar pines de la LCD
 int segundos;
 int minutos;
 int cont=0;
 
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  MsTimer2::set(100,contador);//llamando metodo contador que se accione con el timer
  MsTimer2::start();

}

void loop() {
  // put your main code here, to run repeatedly:

}
void contador(){//metodo del contador 
  segundos++;//variable que cuenta en segundos 
  cont++;//varible par validad el if que hara posible el reinicio a los 28 segundos
  if(segundos==60){
    segundos=0;
    minutos=minutos+1;
  }
  if(minutos==60){
    minutos=0;
  }
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print(minutos);
  lcd.setCursor(4,0);
  lcd.print(":");
  lcd.setCursor(5,0);
  lcd.print(segundos);
  if(cont==28){
    wdt_disable();
    wdt_enable(WDTO_30MS);//habilita reinicio del sistema
  }
  
}

