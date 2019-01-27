#include <stdio.h> /*Standart input output library*/
#include <stdlib.h> /*Stdlibrary for random numbers*/
#include <time.h>/*Using time.h library for Rand function.*/
void menu(void);/*Simple menu function*/
int getInt(int mini, int maxi);/*it gets a integer between range*/
int numberGeneratorBetweenRange(int mini, int maxi);/*Generates random integer between range.*/
void horseRacingGame(void);/*Horse racing game function*/
void triangleOfSequences(void);/*Triangle of sequences function.*/
void countOccurrence(void);/*Count occurrence function*/
int findLength(int number);/*Finds length of number(required for countOccurrence game).*/
int powerFunc(int base, int exponent);/*My power function*/

int main(void){
	srand(time(NULL));/*Creates a random number in a time*/
	menu();/*Calling menu function on menu for clarafication.*/
	return 0;
}
int getInt(int mini, int maxi){
	int sentinel;/*Loop control sentinel*/
	int number;/*The number will be taken from user*/
	do{
		printf("Please enter a number: \n");
		scanf("%d",&number);
		if(number >= mini && number <= maxi){
			sentinel  =  0;/*If number is between range, then set sentinel to 0 so loop will end.*/
		}
		else{
			printf("Please enter between (%d - %d) range\n",mini,maxi);
			sentinel = 1;/*If the number is not between range set it to 1 so loop will continue.*/
		}
	}while(sentinel);/*sentinel controlled do-while loop.*/
	return number; /*Returning the valid number*/
}
int numberGeneratorBetweenRange(int mini, int maxi){
	int randomNumber; /*Random number variable*/
	int sentinel = 1; /*Loop control sentinel*/

	while(sentinel){ /*While sentinel is true*/
		randomNumber = rand() % maxi + 1; /*Generate random number */
		if(randomNumber>=mini && randomNumber<=maxi){/*If the number is between range*/
			sentinel = 0; /*Set sentinel to 0 so we can quit from the loop.*/
		}	
	}
	return randomNumber;/*Returning the random number we generated.*/
}
void menu(void){
	int sentinel = 1; /*Loop control sentinel*/
	int selection; /*Users selection*/
	do{
		printf("1.Horse Racing Game\n");
		printf("2.Occurrence counter\n");
		printf("3.Triangle of Sequences\n");
		printf("0.Exit\n\n");
		printf("Please select a number from menu.\n");
		scanf("%d",&selection); /*Takes number from user*/
		if(selection<= 3 && selection >=0){ /*If it's between 0-3*/
			if(selection == 0){ /*and if it's 0*/
				sentinel = 0; /*Set sentinel to 0, because 0 is entered.*/
			}
			else{
				sentinel = 1; /*Otherwise continue loop so user can play another one when one is finished*/
			}
			
			switch(selection){
				case 0:
					printf("Exiting the program...\n"); /*If the input is 0 do nothing.*/
					break;
				case 1:
					printf("-----HORSE RACING GAME IS ON-----\n");
					horseRacingGame(); /*Calling horseRacingGame function*/
					break;
				case 2:
					printf("-----OCCURRENCE COUNTING IS ON-----\n");
					countOccurrence(); /*Calling countOccurrence function*/
					break;
				case 3:
					printf("-----TRIANGLE OF SEQUENCES IS ON-----\n");
					triangleOfSequences(); /*Calling triangleOfSequences*/
					break;
				default:
					printf("You shouldn't be here.\n"); /*User can't enter here because this switch loop inside of if condition.*/
					break; /*Anyway it always good to have defaut section in switch function.*/
			}
		}
		
	}while(sentinel); /*While sentinel is true continue this loop.*/



}
void horseRacingGame(){
	int i,j; /*Loop control variables*/
	int userHorse; /*The horse that user selected*/
	int horseCount; /*Count of horses*/
	int horseDistance; /*Random generated horse distance*/
	int winner; /*Winner horse distance for finding winner*/
	int smallNum = 0; /*Small number variable for finding winner*/
	

	horseCount = numberGeneratorBetweenRange(3,5); /*Creating horse number between 3-5*/

	userHorse  = getInt(1, horseCount); /*Checking true inputs between 1-horseCount*/
	printf("Racing starts...\n");
	for(i = 0; i < horseCount; ++i){
		printf("Horse %d:", i+1);/*Printing the horse number*/
		horseDistance = numberGeneratorBetweenRange(10,20); /*Creating instance random variable for that horse*/
		
		for (j = 0; j < horseDistance; ++j){
			printf("-"); /*For that distance this loop will visualize the distance.*/
		}	
		if(horseDistance > smallNum){/*If horseDistance greater than smallNum*/
			winner = i + 1;  /*Save the index of winner.*/
			smallNum = horseDistance; /*Assign that distance to new smallNum so maybe we can find greater ones.*/
		}
		printf("\n");
	}
	if(userHorse == winner){
		printf("You win! Winner is Horse %d.\n",winner ); /*Showing the winner horse if you win.*/
	}
	else{
		printf("You lose! Winner is Horse %d\n",winner);/*Showing the winner horse if you lose. */
	}
	printf("\n");
}

void triangleOfSequences(void){
	int i,j;/*Loop control variables*/
	int randomNumber; /*Random number variable*/
	randomNumber = numberGeneratorBetweenRange(2,10); /*Creating number between range*/

	for(i = 1 ; i <= randomNumber ; i++){
		for(j = 1 ; j <= i ; ++j){
			printf("%d ",i * j ); /*Multiplies the way in PDF*/
		}
		printf("\n");
	}
	printf("\n");

}

int findLength(int number){
	int counter = 0;
	
	while(number){
		number = number / 10; /*While number is > 0 keep dividing it with 10.*/
		counter++; /*Increment counter*/
	}
	return counter; /*Return the counter which is length of number*/
}

void countOccurrence(void){
	int bigNumber; /*The number we will search in*/
	int searchNumber; /*The smaller number we will search*/
	int numLength; /*Length of number*/
	int tempNumber; /*Temporary number variable*/
	int counter = 0; /*Counter variable*/
	printf("Please enter the big number: ");
	scanf("%d", &bigNumber); /*Takes the big number from user.*/

	printf("Please enter the number that you wanna search: \n");
	scanf("%d", &searchNumber); /*Takes the small number from user*/

	numLength = findLength(searchNumber); /*Finds the length of small number*/

	while(bigNumber){ /*While bigNumber is > 0*/
		tempNumber = bigNumber % powerFunc(10,numLength); /*If the small number has "x" digit then we need to check modulus of 10 ^ x digits*/
		if(tempNumber == searchNumber){
			counter++; /*If the number we search equals to tempNumber increment counter*/
		}
		bigNumber = bigNumber / 10; /*Divide counter with 10 */
	}

	printf("Occurence: %d\n",counter); /*Print the occurence of this number*/
	printf("\n");
	}
	
int powerFunc(int base, int exponent){
	int i;
	int sum = 1;
	for(i = 1 ; i <= exponent ; ++i){
		sum = sum * base; /*Multiply the number by itself exponent times*/
	}

	return sum; /*Return the number*/
}