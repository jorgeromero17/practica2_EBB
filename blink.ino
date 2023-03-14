bool flagb = true; //para alternar el estado del led
unsigned long pmb = 0; //pmb = previous millis blink, para almacenar el tiempo transcurrido desde la última vez que el LED cambió de estado.

void _blink(unsigned long currentMillis){
  const long interval = 1000; //Representa el intervalo de tiempo en milisegundos en el que el LED debe cambiar de estado.
  
  if (currentMillis - pmb >= interval) { //Se comprueba si ha pasado el intervalo de tiempo establecido desde la última vez que el LED cambió de estado.
    pmb = currentMillis; //se actualiza la variable con el tiempo actual
    if(flagb){ //si la variable flagb es verdadera, el LED se enciende.
      digitalWrite(led1, HIGH);
    }
    else{  //si la variable flagb es falsa, el LED se apaga.
      digitalWrite(led1, LOW);
    }
    flagb = !flagb; //se invierte el valor de la variable para alternar el estado del LED entre encendido y apagado.
    _show_values(); //Llama a la función para actualizar la pantalla
  }
}