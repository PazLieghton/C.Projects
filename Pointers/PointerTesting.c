#include <stdio.h>

int main (){
	
	printf("1 - Changing a value using pointers\n");
	
	/*I will try to change the value of i to 75 using pointers*/
	int *p;
	int i;
	int k;
	i = 42;
	k = i;
	p = &i;
	
	/*The following pointer changes i*/
	
	*p = 75;
	
	printf("%d the value of ""i""\n\n",i); 
	
	/*2 - What's wrong with these lines of code*/
	
	/*char c = 'A'*/
	/*double *p = &c*/
	
	char c = 'a';
	char *j = &c;
	
	
	


	return 0;
}

