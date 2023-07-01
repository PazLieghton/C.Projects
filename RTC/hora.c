/*
Este programa permite el ingreso de la hora (hh:mm:ss) y la modifica en el RTC 
Programacion UNSAM
Autor: David Lopez
Año: 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>
#define P 0x70 /* RTC */

/* Esta funcion otorga/quita (segun <permiso> sea 1/0) privilegios a <cantidad> de puertos a partir del puerto <base> */
void perm(unsigned long base, unsigned long cantidad, int permiso){
  if (ioperm(base, cantidad, permiso) != 0) {
    perror("ioperm");
    printf("Verifique que esta ejecutando con usuario root o en modo root con sudo\n");
    exit(1);
  }
}

/* Esta funcion lee un byte del registro del RTC cuyo nro se recibe */ 
unsigned char in (unsigned char reg){
  outb (reg, P);
  return inb(P + 1);
  }

/* Esta funcion escribe el byte recibido al registro del RTC cuyo nro se recibe */ 
void out (unsigned char valor, unsigned char reg){
  outb (reg, P);
  outb (valor, P + 1);
  }

int main(){
  unsigned char seg, min, hora, a, b;

  printf ("Ingrese la nueva hora (hh:mm:ss):");
  scanf ("%hhx:%hhx:%hhx", &hora, &min, &seg); //hh porque es uchar, x para grabar en BCD

  /* Dar permisos a los ports 70 y 71 */
  perm(P, 2, 1);
  
  /*Leer reg A*/
  a = in (0x0A);
  if ((a & 0x80) != 0) //Verif. bit 7 (UIP). Ojo prioridades operadores 1000 0000
    usleep (1984); //Esperar lo que dura la actualiz. en el peor caso (1984us)

  b = in (0x0B);
  b = b | 0x80; //Setear bit 7 (SET) xxxx xxxx | 1000 0000 => 1xxx xxxx
  out (b, 0x0B);

  out (hora, 0x04);
  out (min, 0x02);
  out (seg, 0x00);

  b = b & 0x7F; //Borrar bit 7 (SET) xxxx xxxx & 0111 1111 => 0xxx xxxx
  out (b, 0x0B);

  /*Retirar permisos */
  perm(P, 2, 0);

  return 0;
}