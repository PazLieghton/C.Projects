//1 - A function that allows lifo insertion in a simple linked list//
//2 - A function that creates a Lifo pile with user input data//
//3 - A function that returns the quantity of elements in a list//
//4 - A function that returns a the odds and pairs of int numbers in a linked list//
//5 - A function that allows fifo insertion
#include <stdio.h>
#include <stdlib.h>


//Typedef init node//
//Nodo is Node//

typedef struct nodo {
	int data;
	struct nodo *sig;
}nodo;


//1
nodo *insert_lifo(nodo *l, int d){
	nodo *new;
	new = (nodo*)malloc(sizeof(nodo));
	new -> data = d;
	new -> sig = l;
	return new;
}

void user_input_lifo(nodo **l){
	int i,c;
	int imp;
	printf("\nHow many numbers do you want to add?: ");
	scanf("%d",&c);
	for (i = 1; i<=c ; i++){
		printf("\nInsert Number: ");
		scanf("%d",&imp);
		*l = insert_lifo(*l,imp);
	}
}

//5

nodo *insert_fifo(nodo *l, int d){
	nodo *new, *p;
	new = (nodo*)malloc(sizeof(nodo));
	new -> data = d;
	new -> sig = NULL;
	if (l == NULL){
		return new;
	}
	p = l;
	while(p -> sig != NULL){
		p = p->sig;
	}
	p -> sig = new;
	return l;
}

//Num Counter

void user_input_fifo(nodo **l){
	int i,c;
	int imp;
	printf("\nHow many numbers do you want to add?: ");
	scanf("%d",&c);
	for (i = 1; i<=c ; i++){
		printf("\nInsert Number: ");
		scanf("%d",&imp);
		*l = insert_fifo(*l,imp);
	}
}
//Generic Function for showing a simple linked list//

void show(nodo *l){
	printf("List");
	while (l != NULL){
		printf(" --> %d", l->data);
		l = l-> sig;
	}
	printf("\n");
}


int main(){
	int switcher;
	//Lista means List
	nodo *lista = NULL;

	printf("This is an example of a simple linked list with Lifo and Fifo operators\n");
	printf("1 - To add x amount of numbers to a simple linked lists in LIFO\n");
	printf("2 - To return the amount of elements in the current list\n");
	printf("3 - To return the odds and pairs of numbers in a linked list\n");
	printf("4 - A function that allows fifo insertion for x number of elements\n");
	printf("5 - Show the function\n");
	printf("PRESS E TO EXIT\n");

    
    while (1) {
        printf("\n\nEnter your choice: ");
        scanf("%d", &switcher);

        switch (switcher) {
            case 1:
                printf("You entered 1.\n");
                user_input_lifo(&lista);
                break;
            case 2:
                printf("You entered 2.\n");
                break;
            case 3:
                printf("You entered 3.\n");
                break;
            case 4:
                printf("You entered 4.\n");
                user_input_fifo(&lista);
                break;
            case 5:
            	printf("You entered 5.Show program\n");
                show(lista);
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid input.\n");
                break;
        }
    }
	return 0;
}