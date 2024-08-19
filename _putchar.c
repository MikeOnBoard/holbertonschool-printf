#include <unistd.h>

/*Anotaciones para este programa
*_putchar - writes the caracter c to stdout
* @c: The caracter to print
*Return: On succes 1.
 On error, -1 is returned, and errno is set appropiately.
*/

int _putchar(char c)
{


    return (write(1, &c, 1));
}