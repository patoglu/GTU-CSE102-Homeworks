#include <stdio.h>/*Standart input output library*/
#include <stdlib.h>/*For malloc and free functions*/
#include <time.h>/*For clock function.*/
#define TESTALPHA 500000 /*Test macro*/
#define TESTBETA 750000/*Test macro*/
#define TESTDELTA 1000000 /*Test macro*/

typedef struct primeNode_{ /*typedef linkedlist*/
	int primeNumber; /*Data*/
	struct primeNode_ *next; /*Pointing next element*/
}node; /*Struct type name*/
void display(node *head){ /*Displaying each node data.(Just for testing)*/
	node *temp = head;
	printf("\nList elements are\n");
	while(temp != NULL){
		printf("%d\n",temp->primeNumber);
		temp = temp -> next;
	}
}

node* insertPrimeAtEnd(node *head, int primeNum){ /*Inserts last number end of list.*/
	node *newNode; /*Creating newNode */
	newNode = (node*) malloc(sizeof(node)); /*Allocating memory for that node.*/
	newNode -> primeNumber = primeNum; /*Adding one data to end of list.*/
	newNode -> next = NULL; /*End of list pointing to NULL*/
	head->next=newNode; /*Now our original list variable a.k.a head is same as newNode.*/
	return newNode; /*Returning newNode. So with this I'm gaining huge time from runtime.*/
	/*Because I can add new element instantly when I call this function again. If this function
	had void return value then I had to reach end of the list for every instertion. Which is 
	really slow for 1 million numbers like 20 minutes. (It takes like 0.4 seconds now*/

}
int isPrime(int number){ /*This function controls the given number is prime or not. I've done it on CSE 108 lab*/
	int i;
	if(number == 0 || number == 1){
		return 0;
	}
	for(i = 2; i <= number / 2 ; ++i)
        if(number % i == 0)
           return 0;
    return 1;
 
}	
void addPrimeToLinkedList(node *head, int bound){

	node *temp; /*Temp node*/
	int singlePrimeNum; /*Data that I will read from file.*/
	int i = 0; /*Iterator variables*/
	int j = 0;/*Iterator variables*/
	char junk;
	int junkNum;
	int *numbers = malloc(bound * sizeof(int)); /*Allocating memory for bound size.*/
	FILE *fptr;/*File pointer*/
	FILE *fptr2; /*File pointer*/
	fptr = fopen("data.txt","r"); /*Opening the file in reading mode.*/
	fptr2 = fopen("output_prime_LinkedList.txt","w"); /*Opening the file in writing mode.*/ 
	if(fptr == NULL){
		printf("Error opening file.\n"); /*Printing error message if error occurs*/
		exit(1);
	}
	else{
		while(fscanf(fptr,"%d%c%d", &singlePrimeNum,&junk,&junkNum) != EOF && i<bound){ /*Reading from file.*/
				numbers[i++] = singlePrimeNum; /*Initializing all numbers to array.*/

		}
	}
	fclose(fptr); /*Closing fptr because reading process is done.*/
	temp=head; /*Our original node head pointing to temp now.*/
	while(j <= bound){ /*While j < bound add datas to linkedlist one by one.*/
		
		temp=insertPrimeAtEnd(temp,numbers[j]); 
		if(isPrime(numbers[j]) == 1){
			printf("Linkedlist %d\n",numbers[j] );
			fprintf(fptr2, "%d is prime.\n",numbers[j]); /*Writing to the file.*/
		}
		j++;
	}
	fclose(fptr2); /*Closing file.*/
}
void addPrimeToDynamicArr(int *numbers, int bound){
	int singlePrimeNum;  /*Data that I will read from file.*/
	int i = 0; /*Iterator*/
	char junk; /*Junk value*/
	int junkNum;/*Junk value*/
	FILE *fptr; /*File pointer*/
	FILE *fptr2; /*File pointer*/
	numbers = malloc(bound * sizeof(int)); /*Allocating memory for numbers*/

	fptr2 = fopen("output_prime_dynamicArray.txt","w");  /*Opening file in writing mode.*/
	fptr = fopen("data.txt","r"); /*Opening the file in reading mode.*/
	if(fptr == NULL){
		printf("Error opening file.\n"); /*Printing error message if error occurs*/
		exit(1);
	}
	else{
		while(fscanf(fptr,"%d%c%d", &singlePrimeNum,&junk,&junkNum) != EOF && i < bound){
				numbers[i] = singlePrimeNum;
				printf("Dynamic : %d\n",singlePrimeNum ); /*Initializing all datas in dynamic mem method.*/
				if(isPrime(numbers[i])){
					fprintf(fptr2, "%d is prime.\n",numbers[i]);
				}
				i++;


		}
	}
	fclose(fptr);/*Closing file pointers*/
	fclose(fptr2);
	free(numbers); /*Free memory*/
	
}

int main(void){
	FILE *fptr1,*fptr2; 
	int *numbers;
	clock_t launch, done;
	double diff1L, diff2L,diff3L, diff1M,diff2M,diff3M;
	node *primeNumbers = NULL;
	node *temp1=primeNumbers;/*Creating both temp1 and temp2 for linkedlist free process*/
	node *temp2=primeNumbers;
	fptr1 = fopen("output_prime_dynamicArray.txt","w"); /*Opening files in writing mode to write calc times.*/
	fptr2 = fopen("output_prime_LinkedList.txt","w");
	
	primeNumbers = (node*) malloc(sizeof(node)); /*Allocating memory for primeNumbers*/


	launch = clock(); /*Timers set*/
	addPrimeToLinkedList(primeNumbers,TESTALPHA); /*First test*/
	done = clock();
	diff1L = (double)(done - launch) / CLOCKS_PER_SEC;

	while(temp2!=NULL)
	{
		temp2=temp1->next; /*Free process*/
		free(temp1);
	}
	primeNumbers = (node*) malloc(sizeof(node));
	launch = clock(); /*Timers set*/
	addPrimeToLinkedList(primeNumbers,TESTBETA); /*First test*/
	done = clock();
	diff2L = (double)(done - launch) / CLOCKS_PER_SEC;

	while(temp2!=NULL)
	{
		temp2=temp1->next; /*Free process*/
		free(temp1);
	}

	primeNumbers = (node*) malloc(sizeof(node)); 
	launch = clock(); /*Timer set*/
	addPrimeToLinkedList(primeNumbers,TESTDELTA);
	done = clock();
	diff3L= (double)(done - launch) / CLOCKS_PER_SEC;

	while(temp2!=NULL)
	{
		temp2=temp1->next;
		free(temp1);
	}

	launch = clock(); /*Timer set*/
	addPrimeToDynamicArr(numbers,TESTALPHA);
	done = clock();
	diff1M = (double)(done - launch) / CLOCKS_PER_SEC;


	launch = clock(); /*Timer set*/
	addPrimeToDynamicArr(numbers,TESTBETA);
	done = clock();
	diff2M = (double)(done - launch) / CLOCKS_PER_SEC;

	launch = clock(); /*Timer set*/
	addPrimeToDynamicArr(numbers,TESTDELTA);
	done = clock();
	diff3M = (double)(done - launch) / CLOCKS_PER_SEC;
	

	rewind(fptr1); /*Rewinding so I can write calculations times to beginning of file.*/
	rewind(fptr2);

	/*Writing all calculation times.*/
	fprintf(fptr2,"0 - 500000 Linkedlist calc time is is %.3f\n",(double)diff1L );
	fprintf(fptr2,"0 - 750000 Linkedlist calc time is %.3f\n",(double)diff2L );
	fprintf(fptr2,"0 - 1000000 Linkedlist calc time is %.3f\n",(double)diff3L );
	fprintf(fptr1,"0 - 500000 Dynamic Memory calc time is is %.3f\n",(double)diff1M );
	fprintf(fptr1,"0 - 750000 Dynamic Memory calc time is %.3f\n",(double)diff2M );
	fprintf(fptr1,"0 - 1000000 Dynamic Memory calc time is %.3f\n",(double)diff3M );

	
	printf("Done.\n");
	
		
	
	return 0;
}
