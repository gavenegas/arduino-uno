#include "DHT.h"
#include "DistanceGP2Y0A21YK.h" // Carga de librerías

#define DHTPIN 8     // Pin donde está conectado el sensor de Tº y Hº
#define DHTTYPE DHT22   // Sensor DHT22 de proximidad

DHT dht(DHTPIN, DHTTYPE);

#define trigPin 9 //Trig proximidad
#define echoPin 10 //Echo proximidad
#define led 11  //Led Rojo
#define led2 12 //Led Verde
 
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
    Serial.println("Iniciando...");

}
 
void loop() {
  //--------HUMEDAD Y TEMPERATURA--
  float h = dht.readHumidity(); //Leemos la Humedad
  float t = dht.readTemperature(); //Leemos la temperatura en grados Celsius
  float f = dht.readTemperature(true); //Leemos la temperatura en grados Fahrenheit
  long duration, distance; //Cálculo del sensor de proximidad
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(1); 
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    digitalWrite(led,HIGH);
    digitalWrite(led2,LOW);
      if (distance < 15) { 
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
}
 
if (distance >= 19){ //Distancia en cm que activa la medición
  Serial.println("Out of range");  
    Serial.print("\t"); //creo tabla para exportar a CSV
    delay(100);   //cada cuanto tiempo realiza nuevo ciclo
}
else { 
  Serial.print("Humedad:");
  Serial.print(h);
    Serial.print("\t");  //creo tabla para exportar a CSV    
  Serial.print("Temperatura:");
  Serial.print(t);
  Serial.print("*C ");
      Serial.print("\t"); //creo tabla para exportar a CSV     
   Serial.print(distance);
   Serial.println("cm");
     Serial.print("\t"); //creo tabla para exportar a CSV
      Serial.print("Geo:-33.3638472,-70.7108879 ");
    Serial.print("\t"); //creo tabla para exportar a CSV
     Serial.print("image.jpg ");
    Serial.print("\t"); //creo tabla para exportar a CSV
     delay(1000);   //cada cuanto tiempo realiza nuevo ciclo 
}

}
