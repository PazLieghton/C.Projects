//Struct with Student Number, Name, and average score, will write to a file//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct list
{	int snumber;//Student Number//
	char name[20];
	float score;
}l;

int main()
{
	int n, i;
	file *outfile;
	outfile = fopen ("students.dat", "w");
	if (outfile == NULL){
		printf(stderr, "\nOPENERROR\n");
		exit(1);
	}
	
	printf("Please submit the amount of students: \n");
	scanf ("%d", &n);
	
	return 0;
}

