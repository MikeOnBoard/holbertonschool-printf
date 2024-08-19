#include "main.h"

/**
 * itoa - Convierte un número entero en una cadena de caracteres.
 * @num: El número entero que se desea convertir en una cadena.
 * @str: El buffer de caracteres donde se almacenará la cadena resultante.
 * @base: La base numérica para la conversión (por ejemplo, 10 para decimal, 16 para hexadecimal).
 *
 * Esta función convierte el número entero `num` en una cadena de caracteres y almacena
 * el resultado en el buffer `str`, utilizando la base especificada en `base`.
 *
 * El proceso se realiza de la siguiente manera:
 * 1. Se determina si el número es negativo. Si lo es y la base es 10, se marca para agregar el signo '-' en la cadena.
 * 2. Se calculan los dígitos del número y se almacenan en el buffer en orden inverso.
 * 3. Se agrega un carácter nulo al final de la cadena para marcar el final de la cadena de caracteres.
 * 4. Se revierten los caracteres en el buffer para obtener la representación correcta del número en la cadena.
 *
 * Pasos detallados:
 * 1. Inicializa un puntero `ptr` al final del buffer `str` para construir la cadena desde el final hacia el principio.
 * 2. Si `num` es 0, coloca '0' en el buffer y termina.
 * 3. Si el número es negativo y la base es 10, coloca el signo '-' en el buffer y hace que el número sea positivo para la conversión.
 * 4. Realiza la conversión del número a la base especificada. Esto se hace dividiendo el número por la base y almacenando el resto en el buffer.
 * 5. Después de convertir todos los dígitos, el buffer contiene los caracteres en orden inverso. Reviértelos para obtener la representación correcta.
 * 6. Finalmente, coloca el carácter nulo al final del buffer para marcar el fin de la cadena.
 *
 * Retorna:
 *  Una cadena de caracteres que representa el número entero `num` en la base especificada.
 */

char *itoa(int n) {
    int digits = num_digits(n);
    int is_negative;
    char *str = malloc(digits + 1);
    int i;
    if (!str) return NULL;
    
    str[digits] = '\0';
    if (n == 0) {
        str[0] = '0';
        return str;
    }
    
    is_negative = 0;
    if (n < 0) {
        is_negative = 1;
        n = -n;
    }
    
    i = digits - 1;
    while (n) {
        str[i--] = (n % 10) + '0';
        n /= 10;
    }
    
    if (is_negative) str[0] = '-';
    
    return str;
}