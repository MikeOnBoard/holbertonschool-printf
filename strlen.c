#include "main.h"

/** Anotaciones para entender el programa
 * empezamos por entender como funciona una sring
 * una string o cadena es un tipo de array/arreglo que crea enos espacios en memoria en la cual coloca un conjunto de caracteres(puede ser una frase o mensaje).
 * existen varias formas de declarar una string, en este caso se declara de tipo puntero.
 * el cual no nos indica ni que longitud tendra ej: string[15](siendo esta la longitud) = "xxxxxxx xxxx";
 * tampoco se precencia su otra forma en la que definira la longitud dependiendo de los caracters ej: string[] = "xxx xxxx x"; aqui la longiud del string depende lo que esta despues de las comillas, declarando que a la hora de imprimir la funcion que lo imprima tomara el rpimer caracter de la string y a partir de ahi imprimira hasta el caracter nulo.
 * la forma en la que se esta declarando el string es en forma de puntero ej: *string = "xxxx xxxx xxx";, este modo de declaracion y de definicion nos indica que el string trabajara con su espacio en memoria definido, sin crear una copia extra cada vez que se modifica el string.
 * toda cadena contara con un carater nulo '\0' el cual dara final al string y que se definira de forma implicita(no necesariamente se mostrara o señalara), de esta manera las funcniones que impriman sus caracteres o su longitud, tendran en cuenta este caracter para dar final a la impresion.
 * dado a que los string y arrays maneajan una longitud descrita por un entero puede ser manejado por un condicional, bucle o estructura de datos.
 * dicho y aclarado esto anteriormente podemos entrar a entender este programa.
 * se declara una variable la cual sera de tipo entero (int length = 0;) y se declarara con un valor de 0.
 * este entero entrara a iterar o se identificara con la longitud del string, recordemos que la variable length tiene el valor de 0.
 * por lo cual length tomara el valor de el primer caracter de la string (str[length = 0] = "xxxx xxxx";) dando la posibilidad de iterar sobre el mismo.
 * el ejercicio nos pide que imprimamos la longitud del string especificado en el programa main que llama a esta funcion prototipo.
 * para poder contar la longitud del string usaremos un bucle while.
 * este bucle iterara sobre el valor de la variable length.
 * este while nos da la condicion de que length sea distinto al valor nulo '\0' el valor de length(el numero del caracter distinto al caacter nulo) aumentara en cada vuelta del bucle while.
 * entonces mientras length sea distinta al caracter nulo sera incrementado su valor.
 * una vez llegue al caracter nullo saldra del bucle realizando la funcion de return.
 * ya que la funcion prototipo es de tipo int habra un retorno de enteros, facilitando la entrega de la longitud del string.
 * por ultimo la funcion return retornara length, el cual ha cmbiado su valor hasta el ultimo caracter del string, dandonos como resultado su longitud y finalizando de forma correcta el programa y el ejercicio.
 * 
 */

int _strlen(char *s)
{
    int length = 0;

    while (s[length] != '\0')
    {
        length++;
    }

    return length;
}
