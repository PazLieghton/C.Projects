/*Struct with Student Number, Name, and average score, will write to a file*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct list
{	int snumber;//Student Number//
	char name[20];
	float score;
}l;


/*This function will receive a struct and show their contents*/

void show_struct (struct list list) {
	printf("Student Number: %d - Name: %s - Score %.2f",list.snumber, list.name, list.score);
}


/*This function will travel a struct and travel through it*/

void show_everything(struct list list[], int amount){
	int i;
	for (i = 1 ; i < amount + 1 ; i++){
	show_struct(list[i]);
	}
}


int main()
{
	int n, i;
	printf("Please submit the amount of students: \n");
	scanf ("%d", &n);
	
	struct list l[n];
	FILE *outfile;
	outfile = fopen ("students.dat", "w");
	if (outfile == NULL){
		fprintf(stderr, "\nOPENERROR\n");
		exit(1);
	}
	

	for ( i = 1; i < n + 1; i++){
		printf("Student Number:\n");
	        scanf("%d", &l[i].snumber);
	        printf("Name:\n");
	      	scanf("%s", &l[i].name);
	        printf("\nScore:\n");
	        scanf("%f", &l[i].score);
	        fwrite (&l, sizeof(l),1,outfile);
	}
	if (fwrite != 0)
		printf("DONE\n");
	else
		printf("WERROR\n");
	show_everything(l,n);
	fclose (outfile);
	return 0;
}

