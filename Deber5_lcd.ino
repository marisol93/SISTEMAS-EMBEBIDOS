/*
 * UNIDAD 2
 * Nombre: Irma Túquerres
 * Realice la rotación de izquierda a derecha de la palabra "ARDUINO" vista en una lcd.
 */
//visualizar datos en la lcd Y UN CONTADRO
//se usa columna fila 16 columnas y 2 filas
const int btn=6;
#include<LiquidCrystal.h>
LiquidCrystal lcd {13,12,11,10,9,8};//RS,E, D4 D5 D6 D7
const char vector[7]={'A','R','D','U','I','N','O'};
int i;
int cont=0;
void setup() {
  lcd.begin(16,2);
  pinMode(btn,INPUT);
}

void loop() {
  lcd.setCursor(0,0);
  for(i=0;i<7;i++){
    lcd.setCursor(i,0);
    lcd.print(vector[i]);
    delay(200);
    lcd.print(" ");
    delay(200);
  }
  
  lcd.setCursor(0,0);
  for(i=6;i>=0;i--){
    lcd.setCursor(i,0);
    lcd.print(vector[i]);
    delay(200);
    lcd.print(" ");
    delay(200);
  }
}
