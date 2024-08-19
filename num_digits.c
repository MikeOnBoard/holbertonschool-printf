#include "main.h"

/**
 * num_digits - Calcula el número de dígitos en un número entero.
 * @n: El número entero del cual se desea contar los dígitos.
 * 
 * Retorna: El número de dígitos en el número entero dado. Para el caso de 
 *          0 y números negativos, el retorno será al menos 1.
 * 
 * Esta función cuenta el número de dígitos en un número entero `n`. Si el
 * número es negativo, el signo no se cuenta como un dígito, pero se asegura
 * que al menos se cuente un dígito para el 0 y números negativos. La función
 * usa un bucle `while` para dividir el número sucesivamente por 10, incrementando
 * el contador de dígitos en cada iteración, hasta que el número se convierte en 0.
 */

int num_digits(int n) {
    int digits = 0;
    if (n <= 0) digits = 1;
    while (n) {
        n /= 10;
        digits++;
    }
    return digits;
}
