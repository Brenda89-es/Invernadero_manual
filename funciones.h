
/*Fichero de cabecera con las distintas funciones para la toma de datos*/
//LIBRERIAS

//Libreria humedad y temperatura para el sensor dht11
#include <DHT.h>
//Libreria para la interrupcion por software
#include <TimerOne.h>
//Libreria para el control por Bluetooth
#include <SoftwareSerial.h>

//VARIABLES GLOBALES

//Conexion Bluetooth a los pines analogicos A2 y A1

SoftwareSerial SerialBT (A2,A1); 
//Temperatura y humedad (Ambiente)
DHT dht;
int temperatura_ambiente; 
int humedad_ambiente;

//Humedad suelo

const int pin_suelo = A0;
int valor_sensor_suelo = 0; 

const int rele = 3;

//Nivel agua

const int pin_agua = A5; 
int valor_sensor_agua = 0; 
int agua; 

//Luminosidad incidente
const int ldr = A3;
int valor_sensor_luminosidad = 0; 

int contador; 


//FUNCIONES 

/*Observese que en cada funcion llamamos pedimos los datos de temperatura y humedad puesto que suele dar problemas 
con una funcion independiente, por eso se es redundante*/

//Riego activado
void Regar()
{
    digitalWrite(rele, HIGH);

    delay(dht.getMinimumSamplingPeriod());
    temperatura_ambiente = dht.getTemperature();
    humedad_ambiente = dht.getHumidity();
    
    return;
}

//Riego desactivado
void noRegar()
{
   digitalWrite(rele, LOW);

   delay(dht.getMinimumSamplingPeriod());
   temperatura_ambiente = dht.getTemperature();
   humedad_ambiente = dht.getHumidity();

   return; 
}

//Lectura del sensor de humedad de suelo
int lectura_humedad_suelo()
{
  valor_sensor_suelo = map(analogRead(pin_suelo),0, 1023, 100,0);  

  return valor_sensor_suelo;
}

//Lectura del sensor de la temperatura ambiente
int lectura_temperatura_ambiente()
{
  delay(dht.getMinimumSamplingPeriod());
 
  temperatura_ambiente = dht.getTemperature(); 
  
  return temperatura_ambiente; 
}

//Lectura del sensor de humedad ambiente
int lectura_humedad_ambiente()
{
    delay(dht.getMinimumSamplingPeriod());  
  
    humedad_ambiente = dht.getHumidity(); 
    
    return humedad_ambiente;
}

//Lectura del sensor de luminosidad
int lectura_luminosidad()
{
  valor_sensor_luminosidad = map(analogRead(ldr), 0,1023, 100,0); 

  int temperatura = lectura_temperatura_ambiente();
  
  return valor_sensor_luminosidad;
}

//Lectura del sensor de agua

int lectura_nivel_agua()
{  
   valor_sensor_agua = analogRead(pin_agua); 

   agua=valor_sensor_agua*100/1023;
  
   return (agua);
}

//Comunicacion Bluetooth-PC
void Comunicacion ()
{
    lectura_humedad_suelo();
    lectura_nivel_agua();
    lectura_luminosidad();
    lectura_humedad_ambiente();
    lectura_temperatura_ambiente();
    lectura_humedad_suelo();
    
    SerialBT.print(contador); SerialBT.print("\t"); SerialBT.print(valor_sensor_suelo); SerialBT.print("\t"); SerialBT.print(temperatura_ambiente); SerialBT.print("\t"); 
    SerialBT.print(humedad_ambiente);SerialBT.print("\t"); SerialBT.print(valor_sensor_luminosidad); SerialBT.print("\t"); SerialBT.print(agua);
    SerialBT.println();

    contador ++;
    
    return;
}

void TempHum ()
{
    delay(dht.getMinimumSamplingPeriod());
    temperatura_ambiente = dht.getTemperature();
    humedad_ambiente = dht.getHumidity();
    
    return;
}
