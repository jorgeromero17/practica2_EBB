int sensorPin = A1; //Corresponde al pin analógico 1 del microcontrolador.
int sensorValue = 0; //para guardar el valor leido por el pin analogo.
unsigned long pmp = 0; //pmp = previous millis potentiometer, para almacenar el tiempo desde el ultimo llamado.
bool flagp = true; //Se utiliza para cambiar el estado del LED.

void _potentiometer(unsigned long currentMillis){
  sensorValue = analogRead(sensorPin); //Se lee el valor analógico del pin y se asigna.
  _show_values(); //Llama a la función para actualizar la pantalla y se asigna a la variable.
  if (currentMillis - pmp >= sensorValue) {  //Si han pasado al menos sensorValue milisegundos desde la última vez que se actualizó el led
    pmp = currentMillis; //Se actualiza la variable con el valor de currentMillis
    if(flagp){ // Si la variable flagp es verdadera, se enciende el led 
      digitalWrite(led3, HIGH);
    }
    else{ //Si no, se apaga.
      digitalWrite(led3, LOW);
    }
    flagp = !flagp; //se invierte el valor de la variable para alternar el estado del LED.
  }
}