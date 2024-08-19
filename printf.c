#include "main.h"

int _printf(const char *format, ...)
{
   
    char c;
    char *str;
    va_list args;
    int conteo = 0;
    if (format == NULL)
    {
        return -1;
    }
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
            case 'c':
                c = va_arg(args, int);
                _putchar(c);
                conteo++;
                break;
            case 's':
                str = va_arg (args, char*);
                if (str == NULL)
                {
                    while (*str)
                    {
                        _putchar(*str);
                        str++;
                        conteo++;
                    }
                }
                break;
            case '%':
                _putchar('%');
                conteo++;
                break;
            default:
                _putchar('%');
                _putchar(*format);
                conteo += 2;
                break;
            }
        }
        else
        {
            _putchar(*format);
        }
        format++;
    }
    va_end(args);
    return(conteo);
}
