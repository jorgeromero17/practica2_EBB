void _show_values(){
  display.clearDisplay(); //Borra todo lo que había en la pantalla
  display.setCursor(0, 0); //Posiciona el cursor en la posición (0, 0) de la pantalla (la esquina superior izquierda)

  String percentage = String(int(brightnessPercentage)); //Convierte la variable brightnessPercentage a String
  String value = String(sensorValue+1); //Convierte la variable sensorValue a String y le suma 1

  if(digitalRead(led1)==1){ //Si el pin del LED 1 está en alto (encendido)
    display.println("Led 1: ON"); //Escribe "Led 1: ON" en la pantalla
  }
  else{ //Si no (está en bajo, apagado)
    display.println("Led 1: OFF"); //Escribe "Led 1: OFF" en la pantalla
  }

  display.println(""); //Salto de línea en blanco
  display.println("Led 2: "+percentage+"%");  // Muestra el valor del porcentaje de brillo del LED 2 en la pantalla.

  display.println(""); //Salto de línea en blanco
  display.println("Led 3: "+value ); //Escribe "Led 3: " seguido del valor de la variable.

  display.display(); //Muestra todo lo escrito en la pantalla.
}