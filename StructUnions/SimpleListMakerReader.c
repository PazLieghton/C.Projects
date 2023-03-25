/*Struct with Student Number, Name, and average score FILE READER */

#include <stdio.h>
#include <stdlib.h>

struct list
{	int snumber;//Student Number//
	char name[20];
	float score;
};


int main()
{
	int n, i;
	struct list l;
	FILE *infile;
	infile = fopen ("students.dat", "r");
	if (infile == NULL){
		fprintf(stderr, "\nOPENERROR\n");
		exit(1);
	}
	while (fread(&l, sizeof (struct list),1, infile)){
		printf("Student Number: %d \\ Name: %s \\ Score: %.2f\n", l.snumber, l.name, l.score);
		}
	fclose (infile);
	return 0;
}

