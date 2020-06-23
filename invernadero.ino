/*Programa que activa el riego de un invernadero por goteo
 * si pulsamos la tecla "r" y lo desactiva si pulsamos la letra "s".Ademas, toma datos de humedad del suelo, 
 * de humedad ambiente, de temperatura ambiental,del nivel de agua cubriente, y de luminosidad.
 * La comunicacion con el PC es Bluetooth al PC.*/

//Libreria con todas las funciones necesarias creadas. 
#include "funciones.h"

void setup() 
{ 
   Serial.begin(9600);
   SerialBT.begin(9600);
   
   dht.setup(2); //Conexion con DHT-11 (sensor temperatura-humedad)
   pinMode(3, OUTPUT); (Conexion con el rele)
  
   //Realizamos una interrupcion por software para que podamos comunicarnos por bluetooth y poder activar/desactivar el riego
   Timer1.initialize(2000000); //Tiempo que dejamos

   Timer1.attachInterrupt(Comunicacion); //Funcion comunicacion

   contador = 0; //Establecimiento de un contador
}

void loop() 
{  
    char entrada;  //Variable para la letra que vamos a introducir

    //Llamo en cada loop a la funcion temperatura-humedad ya que suele dar problemas con el resto del codigo 
    
    while(temperatura_ambiente == 0) TempHum();
    
    if (SerialBT.available() > 0) //Funcion para introducir por teclado mediante en la conexion bluetooth
    {
        
        entrada = SerialBT.read(); 
  
        if (entrada == 'r') 
        {
            TempHum(); 
            Regar(); //Funcion regar (Activa el riego cuando introducimos la "r")
            
        }
        else if (entrada == 's')
        {
            TempHum();
            noRegar(); //Funcion no regar (Desactiva el riego cuando introducimos la "s")
        }
    }
}
