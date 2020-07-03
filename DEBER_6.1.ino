String pass="1234";
String letra="";
int led1=8;//led verde
int led2=7;//led rojo
void setup() {
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  Serial.println("Ingrese una contraseña");
}

void loop() {
  if(Serial.available()>0){
    letra=Serial.readString();
    Serial.print(letra);
    if(letra==pass){
      digitalWrite(led1,HIGH);
      digitalWrite(led2,LOW);
      delay(200);
    }
    else{
      digitalWrite(led2,HIGH);
      digitalWrite(led1,LOW);
    }
  }
  // put your main code here, to run repeatedly:

}
