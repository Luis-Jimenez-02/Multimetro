//Variables para DC
const int pinDC = 34;
float dcValue = 0;
float dcVoltage = 0;
//Variables para AC
const int n = 17; 
const int pinAC = 36;
int acValue = 0;
float acVoltage = 0;
float aux =0;
float acV = 0;

void setup(){
  Serial.begin(9600);
  delay(1000);
}

void loop(){
  //Para calcular el Voltaje de corriente directa
  for(int i = 0; i < 100; i++){
    dcValue = analogRead(pinDC); //Tomar el valor obtenido del pin
    dcVoltage += dcValue * (3.33/4095.0); //Transformalo a valores reales
    delay(1);
  }
  //Promediar
  dcVoltage /= n;

 

  //Para calcular el Voltage de corriente alterna
  for(int i = 0; i < n; i++){
    acValue = analogRead(pinAC); //Tomar el valor del pin
    aux = acValue;  //HAcerlo flotante
    aux = aux * (3.3/4095.0) - 1.56; //Convertirlo a flotante
    acVoltage += (aux * aux); //Al cuadrado
    delay(1);
  }
  //Promediar los resultados
  acVoltage /= n;
  //Obtener raiz cuadrada
  acV = sqrt(acVoltage) ;

  //Imprimir los valores
  Serial.println(dcVoltage);
  Serial.println(acV);
  delay(1000);
}