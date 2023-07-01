/*1. Escribir una función en lenguaje C que reciba como 
argumento un nro de registro (0-13), lea el valor de ese 
registro del RTC y lo imprima por pantalla como hexadecimal.
2. Hacer un programa que use la función del ejercicio
anterior para mostrar los valores de los primeros 13 registros 
del RTC. A cada valor de registro impreso, agregarle una 
descripción previa, de unos pocos caracteres, que especifique a
qué registro pertenece el valor mostrado.
3. Modifique el programa del ejercicio anterior. Además de 
mostrar la descripción y el valor de cada registro leído, imprima 
sobre la misma línea de la pantalla el valor del registro en 
formato binario de 8 caracteres. Recuerde que en la guía de
sistemas de numeración debió realizar la función para convertir a binario.*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>
#define P 0x70

