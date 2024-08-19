#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, printed_chars = 0;
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

