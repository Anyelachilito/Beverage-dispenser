#include <Keypad.h>
#include <LiquidCrystal.h>
//.<

const byte filas = 4; 
const int ledPIN_RED = 2;
const int ledPIN_GREEN = 15;

const byte pinObstaculo =4; //pin de dato del sensor de proximidad
int hayObstaculo = HIGH;

const byte columnas = 4;

const int Trigger=33;   //pin del sensor Usonido
const int Echo=34;      //pin del sensor Usonido
void validar_nivel();

//Crear el objeto LCD con los números correspondientes (rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(23, 22, 21, 19, 18, 5);
//LiquidCrystal lcd(D15, D2, D4, D5, D18, D19);
byte pinesFilas[]  =   {26, 27, 25, 26};
byte pinesColumnas[] = {14, 12,  1, 13};
char teclas[4][4] = {{'1','2','3','A'},
                     {'4','5','6','B'},
                     {'7','8','9','C'},
                     {'*','0','#','D'}};
Keypad teclado1 = Keypad( makeKeymap(teclas), pinesFilas, pinesColumnas, filas, columnas);  


void setup() {
  pinMode(ledPIN_RED , OUTPUT);  //definir pin como salida
  pinMode(ledPIN_GREEN , OUTPUT);  //definir pin como salida
  Serial.begin(9600);
  Serial.println("Teclado 4x4 con Biblioteca Keypad");
  Serial.println();
  // Inicializar el LCD con el número de  columnas y filas del LCD
  lcd.begin(16, 2);

  pinMode(hayObstaculo, INPUT); //sensor proximidad

  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW);
  
  
}

void loop() {

  hayObstaculo = digitalRead(pinObstaculo);
  
  //Verifica si alguna tecla fue presionada
  char tecla_presionada = teclado1.getKey();
  bool n = true;
  long t;
  long d;

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

  t = pulseIn(Echo, HIGH);
  d = t/59;
  
  switch (tecla_presionada) {  
    case '1':
      Serial.println("Seleccionó bebida uno");
      lcd.setCursor(0, 0);
      lcd.print("Selecciono");
      delay(100);
      lcd.setCursor(0, 1);
      lcd.print("bebida uno");
      delay(2000);
      lcd.clear();
      delay(2000);
      
      if(d <=10){
        lcd.setCursor(0, 0);
        lcd.print("A: Pequeno");
        delay(100);
        lcd.setCursor(0, 1);
        lcd.print("B: Grande");
        delay(2000);
        lcd.clear();
      }else{
        Serial.println("Lo sentimos no hay bebida");
        lcd.setCursor(0, 0);
        lcd.print("Lo sentimos no");
        delay(100);
        lcd.setCursor(0, 1);
        lcd.print("hay bebida");
        delay(2000);
        lcd.clear();
        digitalWrite(ledPIN_RED , HIGH);   // poner el Pin en HIGH
        delay(700);                   // esperar un segundo
        digitalWrite(ledPIN_RED, LOW);    // poner el Pin en LOW 
      }
      break;
    case '2':     
      Serial.println("Selecciono bebida dos");
      lcd.setCursor(0, 0);
      lcd.print("Selecciono");
      delay(100);
      lcd.setCursor(0, 1);
      lcd.print("pepsi");
      delay(2000);
      lcd.clear();
      delay(2000);
      if(d<=10){
        lcd.setCursor(0, 0);
        lcd.print("A: Pequeno");
        delay(100);
        lcd.setCursor(0, 1);
        lcd.print("B: Grande");
        delay(2000);
        lcd.clear();
      }else{
        Serial.println("Lo sentimos no hay bebida");
        lcd.setCursor(0, 0);
        lcd.print("Lo sentimos no");
        delay(100);
        lcd.setCursor(0, 1);
        lcd.print("hay bebida");
        delay(2000);
        lcd.clear();
        digitalWrite(ledPIN_RED , HIGH);   // poner el Pin en HIGH
        delay(700);                   // esperar un segundo
        digitalWrite(ledPIN_RED, LOW);    // poner el Pin en LOW 
      }
      break;
    case 'A':
      Serial.println("Selecciono tamaño pequeño");
      lcd.setCursor(0, 0);
      lcd.print("Selecciono");
      delay(100);
      lcd.setCursor(0, 1);
      lcd.print("tamano pequeno");
      delay(2000);
      lcd.clear();
      delay(2000);

      if(hayObstaculo==LOW){
        surtir_vaso_pequenio();
      }else{
        lcd.setCursor(0, 0);
        lcd.print("Ubique el vaso");
        delay(100);
        lcd.setCursor(0, 1);
        lcd.print("debajo: ");
        delay(2000);
        lcd.clear();
        digitalWrite(ledPIN_RED , HIGH);   // poner el Pin en HIGH
        delay(700);                   // esperar un segundo
        digitalWrite(ledPIN_RED, LOW);    // poner el Pin en LOW 
      }
      
      break;
    case 'B':
      Serial.println("Selecciono tamaño grande");
      lcd.setCursor(0, 0);
      lcd.print("Selecciono");
      delay(100);
      lcd.setCursor(0, 1);
      lcd.print("tamano grande");
      delay(2000);
      lcd.clear();
      delay(2000);
      
      if(hayObstaculo==LOW){
        surtir_vaso_grande();
      }else{
        lcd.setCursor(0, 0);
        lcd.print("Ubique el vaso");
        delay(100);
        lcd.setCursor(0, 1);
        lcd.print("debajo: ");
        delay(2000);
        lcd.clear();
        digitalWrite(ledPIN_RED , HIGH);   // poner el Pin en HIGH
        delay(700);                   // esperar un segundo
        digitalWrite(ledPIN_RED, LOW);    // poner el Pin en LOW 
      }
      
//      if(b == false){
//        lcd.setCursor(0, 0);
//        lcd.print("Surtiendo bebida");
//        delay(2000);
//        lcd.clear();
//        digitalWrite(ledPIN_GREEN , HIGH);   // poner el Pin en HIGH
//        delay(15000);                   // esperar un segundo
//        digitalWrite(ledPIN_GREEN, LOW);    // poner el Pin en LOW
//      }else{
//        Serial.println("Opcion no Valida");
//        lcd.setCursor(0, 0);
//        lcd.print("Ubique el vaso");
//        delay(100);
//        lcd.setCursor(0, 1);
//        lcd.print("debajo: ");
//        delay(2000);
//        lcd.clear();
//        digitalWrite(ledPIN_RED , HIGH);   // poner el Pin en HIGH
//        delay(700);                   // esperar un segundo
//        digitalWrite(ledPIN_RED, LOW);    // poner el Pin en LOW 
//      }
       
      break;
    
  }
   if (tecla_presionada)
  {
   if(tecla_presionada != '1' && tecla_presionada != '2' && tecla_presionada != 'A' && tecla_presionada != 'B'){
      Serial.println("Opcion no Valida");
      lcd.setCursor(0, 0);
      lcd.print("Opcion");
      delay(100);
      lcd.setCursor(0, 1);
      lcd.print("no valida");
      delay(2000);
      lcd.clear();
      digitalWrite(ledPIN_RED , HIGH);   // poner el Pin en HIGH
      delay(300);                   // esperar un segundo
      digitalWrite(ledPIN_RED, LOW);    // poner el Pin en LOW
      delay(300); 
      digitalWrite(ledPIN_RED , HIGH);   // poner el Pin en HIGH
      delay(300);                   // esperar un segundo
      digitalWrite(ledPIN_RED , LOW);    // poner el Pin en LOW
      delay(300); 
   }
  } 


}

void surtir_vaso_pequenio()
{
  lcd.setCursor(0, 0);
  lcd.print("Surtiendo bebida");
  delay(1000);
         
  // Escribimos el número de segundos trascurridos
  int i=1;
  while(i<9)
  {
    lcd.setCursor(0, 1);
    lcd.print(i);
    lcd.print(" Segundos");
    digitalWrite(ledPIN_GREEN , HIGH);   // poner el Pin en HIGH
    delay(1000);
    i+=1;
  }
  digitalWrite(ledPIN_GREEN, LOW);    // poner el Pin en LOW
  lcd.clear();

  
}

void surtir_vaso_grande()
{
  lcd.setCursor(0, 0);
  lcd.print("Surtiendo bebida");
  delay(1000);
         
  // Escribimos el número de segundos trascurridos
  int i=1;
  while(i<16)
  {
    lcd.setCursor(0, 1);
    lcd.print(i);
    lcd.print(" Segundos");
    digitalWrite(ledPIN_GREEN , HIGH);   // poner el Pin en HIGH
    delay(1000);
    i+=1;
  }
  digitalWrite(ledPIN_GREEN, LOW);    // poner el Pin en LOW
  lcd.clear();

}

void validar_opcion_numero(bool n)
{
  char tecla_numero = teclado1.getKey();

  if (tecla_numero== '1')
  {
    lcd.setCursor(0, 0);
    lcd.print("Selecciono");
    delay(100);
    lcd.setCursor(0, 1);
    lcd.print("bebida uno");
    delay(2000);
    lcd.clear();

      if(n == true){
         lcd.setCursor(0, 0);
         lcd.print("A: Pequeno");
         delay(100);
         lcd.setCursor(0, 1);
         lcd.print("B: Grande");
         delay(2000);
         lcd.clear();
      }else{
        lcd.setCursor(0, 0);
        lcd.print("Lo sentimos no");
        delay(100);
        lcd.setCursor(0, 1);
        lcd.print("hay bebida");
        delay(2000);
        lcd.clear();
        digitalWrite(ledPIN_RED , HIGH);   // poner el Pin en HIGH
        delay(700);                   // esperar un segundo
        digitalWrite(ledPIN_RED, LOW);    // poner el Pin en LOW 
      }
    
  } else if(tecla_numero=='2')
  {
    lcd.setCursor(0, 0);
    lcd.print("Selecciono");
    delay(100);
    lcd.setCursor(0, 1);
    lcd.print("bebida dos");
    delay(2000);
    lcd.clear();

      if(n == false){
         lcd.setCursor(0, 0);
         lcd.print("A: Pequeno");
         delay(100);
         lcd.setCursor(0, 1);
         lcd.print("B: Grande");
         delay(2000);
         lcd.clear();
      }else{
        lcd.setCursor(0, 0);
        lcd.print("Lo sentimos no");
        delay(100);
        lcd.setCursor(0, 1);
        lcd.print("hay bebida");
        delay(2000);
        lcd.clear();
        digitalWrite(ledPIN_RED , HIGH);   // poner el Pin en HIGH
        delay(700);                   // esperar un segundo
        digitalWrite(ledPIN_RED, LOW);    // poner el Pin en LOW 
      }
  }else{
      lcd.setCursor(0, 0);
      lcd.print("Opcion");
      delay(100);
      lcd.setCursor(0, 1);
      lcd.print("no valida");
      delay(2000);
      lcd.clear();
      digitalWrite(ledPIN_RED , HIGH);   // poner el Pin en HIGH
      delay(300);                   // esperar un segundo
      digitalWrite(ledPIN_RED, LOW);    // poner el Pin en LOW
      delay(300); 
      digitalWrite(ledPIN_RED , HIGH);   // poner el Pin en HIGH
      delay(300);                   // esperar un segundo
      digitalWrite(ledPIN_RED , LOW);    // poner el Pin en LOW
      delay(300); 
  }
  
}

void validar_opcion_bebida(char tecla_tamanio)
{

//  char tecla_tamanio = teclado1.getKey();


  switch(tecla_tamanio){
    case 'A':
      lcd.setCursor(0, 0);
      lcd.print("Selecciono");
      delay(100);
      lcd.setCursor(0, 1);
      lcd.print("tamano pequenio");
      delay(2000);
      lcd.clear();
      delay(2000);
      surtir_vaso_pequenio();
      
      break;
    
  }
//  if(tecla_tamanio=='A')
//  {
//    lcd.setCursor(0, 0);
//      lcd.print("Selecciono");
//      delay(100);
//      lcd.setCursor(0, 1);
//      lcd.print("tamano pequenio");
//      delay(2000);
//      lcd.clear();
//      delay(2000);
//      surtir_vaso_pequenio();
//  }else if(tecla_tamanio=='B'){
//    lcd.setCursor(0, 0);
//      lcd.print("Selecciono");
//      delay(100);
//      lcd.setCursor(0, 1);
//      lcd.print("tamano grande");
//      delay(2000);
//      lcd.clear();
//      delay(2000);
//      surtir_vaso_grande();
//  }else{
//    lcd.setCursor(0, 0);
//      lcd.print("Opcion");
//      delay(100);
//      lcd.setCursor(0, 1);
//      lcd.print("no valida");
//      delay(2000);
//      lcd.clear();
//      digitalWrite(ledPIN_RED , HIGH);   // poner el Pin en HIGH
//      delay(300);                   // esperar un segundo
//      digitalWrite(ledPIN_RED, LOW);    // poner el Pin en LOW
//      delay(300); 
//      digitalWrite(ledPIN_RED , HIGH);   // poner el Pin en HIGH
//      delay(300);                   // esperar un segundo
//      digitalWrite(ledPIN_RED , LOW);    // poner el Pin en LOW
//      delay(300); 
//  }
}
