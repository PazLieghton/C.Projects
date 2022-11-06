#include <stdio.h>

int main(){

int v[10] = {1,2,3,4,5,6,7,8,9,10};
int *p;

p = v+10;
//p va a &v[10], al imprimir *p va a apuntar a v[10]//
p--;
printf("%d ",*p);
p--;
printf("%d ",*p);
p--;
printf("%d ",*p);
p--;
printf("%d ",*p);
p--;
printf("%d ",*p);
p--;
printf("%d ",*p);
p--;
printf("%d ",*p);
p--;
printf("%d ",*p);
p--;
printf("%d ",*p);
p--;
printf("%d ",*p);

return 0;
}

//for (i = 0; i < 10, i++){
//  p--;
//  printf("%d ",*p);
//}
