#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>
#define P 0x70

unsigned char in (unsigned char reg){
  outb(reg, P);
  return inb(P + 1);
}

int main(){
  unsigned char a,seg;
  if (ioperm(P,2,1)){
    perror("ioperm");
    exit(1);
  }
  a = in (0x0A);
  if ((a & 0x80) != 0)
    usleep(1984);

  outb(0x09, P);
  seg = inb(P+1);
  printf("%02x",seg);

  printf("\n\n\nTest");
  return 0;
}
