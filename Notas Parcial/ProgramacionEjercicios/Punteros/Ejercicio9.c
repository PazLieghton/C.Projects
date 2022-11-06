#include <stdio.h>

double prod_esc (const double *a, const double *b, int n)
{
  int i;
  double aux[10];
  for(i=0;i<n;i++){
   aux[i]=(*(a+i))*(*(b+i));
   printf("%lf ",aux[i]);
  }
  return 0;
}

int main(){
  double a[10];
  double vec1[10] = {0,1,2,3,4,5,6,7,8,9};
  double vec2[10] = {0,1,2,3,4,5,6,7,8,9};
  prod_esc(vec1,vec2,10);
  return 0;
}
