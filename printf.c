#include "main.h"

/** Anotaciones para entender el codigo
 * explicare absolutamente todo el codigo linea por linea para poder adquirir la comprension y el entendimiento de la logica para poder almacenar el conocimiento y resolver nuevos problemas de programacion.
 * _printf sera la funcion que deberemos crear en este ejercicio, sera una variante no tan avanzada de la funcion estandar de la tipica funcion printf.
 * esto debido a que solo tendremos en cuenta los identificadores de %, c y s: los cuales manejaran la impresion de %, de caracteres y de cadenas de caracteres.
 * esta funcion contara con un argumento const char *format esto sera un puntero a una cadena de caracteres constante que sera ingresada a la hora de llamar a la funcion printf, ademas de los argumentos variadicos que seran ingresados despues de dicha cadena, estos identificadores seran reconocidos por esta funcion e imprimira el caso en el cual coincida con el identificador ingresado.
 * dicho esto lo primero sera declarar o declarar y definir siendo el caso, las variables que interactuaran dentro de la funcion para hcer mas facil su legibilidad.
 * va_list args: una variable de tipo va_list, se usara para declarar una lsita de argumentos variadicos inicial.
 * int i: para iterar sobre la variable format por medio de los bucles while, printed_chars = 0: variable para recopilar la cantidad de caracteres que sean impresos mediante estafuncion.
 * char *str: este puntero contendra el valor de la cadena de caracteres que sea ingresado mediante la cadena format.
 * char c: variable que contendra el caracter ingresado en el caso de solo ser un caracter y no una cadena de caracteres.
 * una vez declaradas las variables iniciaremos la lista de argumentos donde va_start(args, format) sera la expresion por la cual seleccionara la variable args con el argumento *format sera la cadena ingresada en la cual se buscara dicho identificador.
 * dicho esto empezaremos a iterar por cada caracter de format para extraer los caracteres e ir escribiendo cada uno de ellos con dicho caso.
 * la condicion format && format[i] sera la que mantendra en fincionamiento el bucle while, en otras palabras mientras format y sus elementos existan while ejecutara las instrucciones que contendra a continuacion:
 * primero usaremos las condiciones proporcionadas por este ejercicio que nos permitira dirigir el flujo de la logica de este codigo.
 * usaremos dos condiciones, un en la cual encontramos un identificador % y la siguiente de otro modo si solo es una cadena de caracteres.
 * la primera condicion buscara dicho identificador % para saber cual formato de impresion sera usado mediante if (format[i] == '%)
 * dentro de este caso manejaremos la impresion del formato especificado, como primera instruccion sera incrementar el elemento en la posicion i,
 * para imprmir lo siguiente al caracter % tendremos que identificar el siguiente caracter despues de, para esto usaremos el control de flujo switch, para buscar si este caracter esta dentro de los casos qeu maneja switch (format para [i]).
 * el primer caso sera %c el cual debera imprimir el caracter que se encentre emparejado con %c, con este caso se trabajara como si fueran una condicion a seguir.
 * las instrucciones seran, extraer el caracter de este argumento y definir la variable c para almacenar ese caracter dentro, para poder extraer este caracter usaremos va_arg(args , int);
 * va_arg sera la funcion que extraera el caracter y c almacenara este caracter, imprimira este caracter mediante write, ademas que sumaremos esta funcion para contabilizar los caracteres totales impresos.
 * en cuanto se halla impreso este caracter rompera el bucle while despues de imprimir dicha cadena y retornara el conteo de caracteres de los argumentos ingresados e imprimidos.
 * el siguiente caso nos funcionara para imprimir una cadena de texto ingresada dentro de los argumentos variadicos, para hacer esto extraeremos mediante va_arg un puntero el cual apuntara a una cadena de caracteres.
 * la variable str  guardara este puntero extraido para poder escribir esta cadena.
 * en caso de que str sea NULL , esta variable tomara el valor de "(nil)" como no hay nada dentro de str en caso de ser NULL para que sea impreso necesita tener un valor o una cadena de caracteres.
 * para imprimirlo write tendra 3 argumentos, el primero sera la salida standar(stoutpt 1, y 2 para stderror salida de errores), luego la direccion en memoria de str y posteriormente la cantidad de elementos entregados por la funcion auxiliar strlen la cual se usa para obtener lalongitud de dicha cadena.
 * el siguiente caso, sera cuando solo hay que imprimir un % para esto simplemente usaremos write(1(stdout), '%'(impresion de caracter), 1(cantidad de elementos impresos por write))
 * luego se rompe el bucle y finaliza la salida de la funcion.
 * dentro de switch tendremos un caso por default en caso de no estar el caso definido dentro de switch debera imprimir el primer caracter % y despues el siguiente caracter, esto para los identificadores nos ingresado dentro de switch o un identificador desconocido.
 * write (1, format[i - 1], 1) format [i - 1] imprimira el caracter anterior a este, el cual sera % por eso i el caracter siguiente a % - 1 caracter % es escrito dentro de esta expresion.
 * luego imprimira el caracter actual, i con write(1, format[i], i).
 * de esta manera saldremos del caso donde el caracter es igual a %, sera else el caso contrario a esto, este imprimira el caracter literal para manejar el caso de una cadena literal sin identificador.
 * hay que tener en cuenta que todo esto lo haremos dentro de el bucle while, si es una cadena literal imprimira todos los caracteres, y saldra del bucle pero si el caso es un identificador, realizara las instrucciones para cada caso y rompera el bucle.
 * una vez fuera de este bucle liberaremos memoria mendiante la funcion va_end(args) liberara la variable lista de argumentos args.
 * retornaremos la variable int printed_chars la cual habra contado la totalidad de caracteres impresos, finalizando el codigo y terminando asi el ejercicio de manera correcta.
 */

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, printed_chars = 0, enteros;
    char *str, c;
    va_start(args, format);
    while (format && format[i]) {
        if (format[i] == '%') {
            i++;
            switch (format[i]) {
                case 'c':
                    c = va_arg(args, int);
                    printed_chars += write(1, &c, 1);
                    break;
                case 's':
                    str = va_arg(args, char *);
                    if (!str)
                        str = "(null)";
                    printed_chars += write(1, str, _strlen(str));
                    break;
                case '%':
                    printed_chars += write(1, "%", 1);
                    break;
                case 'i' :
                case 'd' :
                    enteros = va_arg(args, int);
                    str = itoa(enteros);
                    if (!str)
                        str = "(null)";
                    printed_chars += write(1, str, _strlen(str));
                    free(str);
                    break;
                default:
                    printed_chars += write(1, &format[i-1], 1);
                    printed_chars += write(1, &format[i], 1);
                    break;
            }
        } else {
            printed_chars += write(1, &format[i], 1);
        }
        i++;
    }
    va_end(args);
    return printed_chars;
}

