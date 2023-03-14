unsigned long pmf = 0; //previous millis fade, para registrar el tiempo transcurrido.
const long interval = 10; //Se utiliza para determinar el tiempo transcurrido para realizar la animación.
unsigned long cumulativeMillis = 0; //Se utiliza para llevar un seguimiento del tiempo transcurrido.
int brightness = 0; //se utiliza para controlar el brillo del LED.
float fadeAmount = 2.55; //Para controlar la cantidad de brillo que se agrega o se resta en cada ciclo de animación.
float brightnessPercentage; // Para calcular y mostrar el porcentaje de brillo en el LED.

void _fade(unsigned long currentMillis){
  unsigned long elapsedMillis = currentMillis - pmf; //calcula el tiempo transcurrido desde la última llamada de función,
  //restando el tiempo actual en milisegundos de la variable pmf y luego asignando el resultado a la variable elapsedMillis.
  pmf = currentMillis; //Asigna el tiempo actual en milisegundos a la variable pmf, para su uso en la siguiente llamada a la función.
  cumulativeMillis += elapsedMillis; //Agrega elapsedMillis a la variable cumulativeMillis y compara la suma con el valor de interval. 

  if (cumulativeMillis >= interval) { //Si la suma es mayor o igual que interval, entonces se realiza la animación y se reinicia cumulativeMillis.
    cumulativeMillis -= interval;

    brightness += fadeAmount; //Incrementa brightness por fadeAmount y verifica si brightness está dentro del rango válido de 0 a 255. 
    if (brightness <= 0 || brightness >= 255){ //Si brightness está fuera de ese rango, invierte la dirección de fadeAmount
      fadeAmount = -fadeAmount;
    }

    if (brightness >= 0 && brightness <= 255) {//Si brightness está dentro del rango válido, 
      analogWrite(led2,brightness); //Establece el brillo del LED
      brightnessPercentage = ceil((brightness * 100.0) / 255.0); //Se calcula el porcentaje de brillo y se almacena en la variable brightnessPercentage.
    }
    
  }
  _show_values(); //Llama a la función para actualizar la pantalla
}