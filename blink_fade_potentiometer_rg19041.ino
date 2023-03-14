#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Declaración de variables para los LEDs
int led1 = 3, led2 = 4, led3 = 5;

// Declaración de variables para el objeto display
int RST = 9, CE = 10, DC = 11, DIN = 12, CLK = 13;
Adafruit_PCD8544 display = Adafruit_PCD8544(CLK, DIN, DC, CE, RST);

void setup() {
  // Inicialización de los LEDs
  _leds_initialization();
  // Inicialización del display
  _display_initialization();
}

void loop() {
  // Se obtiene el tiempo actual en milisegundos
  unsigned long currentMillis = millis();
  // Llamada a la función _blink para controlar el parpadeo del LED 1
  _blink(currentMillis);
  // Llamada a la función _fade para controlar la intensidad del LED 2
  _fade(currentMillis);
  // Llamada a la función _potentiometer para controlar el LED 3 con un potenciómetro
  _potentiometer(currentMillis);
}

