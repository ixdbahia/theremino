/*
  Theremino: Versión casera de un theremin basado en una fotoresistencia LDR y Arduino
  Infinito por Descubrir Bahía Blanca
  https://github.com/ixdbahia/theremino
  Basado en código original de Arduino Starter Kit
*/

int valorSensor; // Definimos una variable para las lecturas del sensor
int minimoSensor = 1023; // Umbral mínimo para las lecturas del sensor
int maximoSensor = 0; // Umbral máximo para las lecturas del sensor
const int ledPin = 13; // Definimos el pin del LED incorporado en la placa Arduino
void setup() {
pinMode(ledPin, OUTPUT);
digitalWrite(ledPin, HIGH);
while (millis() < 5000) {
valorSensor = analogRead(A0);
if (valorSensor > maximoSensor) {
maximoSensor = valorSensor;
}
if (sensorValue < sensorLow) {
minimoSensor = valorSensor;
}
}
digitalWrite(ledPin, LOW);
}
void loop() {
valorSensor = analogRead(A0); // Leemos el valor del sensor a través del pin A0
int nota = // Definimos una variable para la nota a reproducir por el buzzer
map(valorSensor,minimoSensor,maximoSensor, 50, 4000);
tone(8,nota,20); // Hacemos que el buzzer ejecute la nota
delay(10); // Esperamos 10 milisegundos antes de reiniciar el loop
}
