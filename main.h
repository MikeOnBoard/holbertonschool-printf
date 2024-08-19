#ifndef MAIN_H
#define MAIN_H

/** Anotaciones para entender el codigo
 * este sera el archivo de cabecera que contendra el codigo de la funcion printf.c, se usara de manera que contenga las librerias que seran utilizadas por las funciones como main.c o printf.c.
 * ademas debera contener las llamadas de las funciones prototipo que se usaran en este ejercicio.
 * para este caso solo contendra las funciones printf, putchar, strlen, estas funciones tendran archivos exprernos para poderse usar dentro de la funcion printf.
 * conclusiones para este codigo:
 * archivo de cabecera main.h para usar en las funciones principales que se vayan a usar.
 * aqui estaran las declaraciones de las funciones para usarse.
 */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _putchar(char c);

int _printf(const char *format, ...);

int _strlen(char *s);

int num_digits(int n);

char *itoa(int n);

#endif /** MAIN_H **/