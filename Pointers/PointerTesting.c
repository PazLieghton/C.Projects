#include <stdio.h>

/*Function Odd numbers Part 3*/
int odd (int *v, int size)
	{
	int i;
	int odd = 0;
	
	for (i = 0; i < size; i++)
		{
		if (*(v+i) % 2 != 0)
			odd++;
		}
	return odd;
	}

/*Function of max in a doubles vector Part 4*/

double* max (double *v, int size){
	int i;
	double *pmax;
	
	if(size == 0);
		return NULL;
		
	pmax = v;
	for (i = 1; i < size; i++)
	{
		if (*(v+i) > *pmax)
			pmax = v + i;
	}
	return pmax;
}


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
	
	printf("2bis - Print the inverse of a vector using pointers\n");
	
	int v[10] = {101,202,303,404,505,606,707,808,909,1000};

	
	int *q = v;

	for (i = 1; i < 11 ; i ++){
		printf ("%d \n",*(q+10-i));
		
	}
	
	printf("\n3 - Function that returns quantity of odd numbers in a vector\n");
	
	printf("Quantity of odd numbers is: %d\n", odd(v,10));
	
	printf("4 - Function that returns the maximum value of a vector of doubles");

	double n[10] = {1,2,3,4,5,6,7,8,9,10};
	double *result;
	result = max (n,10);
	
	if (result != NULL)
		printf("\nMaximum value is: %lf\n", *result);
	else
		printf("\nNULL Vector\n");
	
	return 0;
}

