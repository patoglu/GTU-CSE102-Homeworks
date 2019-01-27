#include <stdio.h>
#include <stdlib.h>
int getStudentNumber(void); /*Gets the student number till it's valid.*/
int mainLoop(void); /*Main loop for calculating required processes for each student.*/
int menuSelectionController(void); /*Controls the menu inputs and handles wrong inputs on menu selection.*/
void displayGrades(int a, int b, int c, int d, int f); /*Displays the grades*/
void displayAverage(int sum, int numStudents); /*Displays the average grade.*/
void displaySuccessful(int grade, int index); /*Displays the most successful student*/
void displayUnsuccessful(int grade, int index); /*Displays the most unsuccessful student*/
int main(void){
	

mainLoop();  /*Just calling mainLoop on main, for clarification.*/

	return 0;
}

int getStudentNumber(void){
	int number;
	int count = 0;
	do{
		if(count > 0){
			printf("Not in Range!!!\n\n");
			printf("Enter something between 3 - 50 !!!\n\n");
		}
		printf("Enter student count:");
		scanf("%d",&number);
		count++;
	}while(number < 3 || number > 50); /*Just take numbers between 3 - 50*/

	return number;
	
}
int menuSelectionController(void){
	int selection;
	int count = 0;
	do{
		if(count > 0){
			printf("False Selection!!!\n");
	}
		
	printf("                      Make Selection:");
	scanf("%d",&selection);
	count++;
	}while(!((selection >= 1 && selection <= 5) || selection == -1)); /*Controls the inputs. If not between 1 -5 asks again. If it's -1 takes it.*/

	return selection;
}

void displayGrades(int a, int b, int c, int d, int f){ /*Simple function for showing grades*/

	printf("%d student got letter grade 'A'\n",a);
	printf("%d student got letter grade 'B'\n",b);
	printf("%d student got letter grade 'C'\n",c);
	printf("%d student got letter grade 'D'\n",d);
	printf("%d student got letter grade 'F'\n",f);

}

void displayAverage(int sum, int numStudents){
	double average;

	average = (double)sum / (double)numStudents; /*Casting the variables to double so when we assing it to double "average" variable we guarantee the assignment won't give any warning.*/

	printf("The average Score of %d Student is %.2f\n",numStudents,average);
}

void displaySuccessful(int grade, int index){ /*Simple function for displaying most successful student.*/
	printf("Most Successful student: \n");
	printf("Index: %d\n",index );
	printf("Score: %d\n",grade);
}
void displayUnsuccessful(int grade, int index){ /*Simple function for displaying most successful student.*/
	printf("Most Unsuccessful student: \n");
	printf("Index: %d\n",index );
	printf("Score: %d\n",grade);

}

int mainLoop(void){
	int indexOfSuccessful; /*Variable for successful student.*/
	int indexOfUnsuccessful;/*Variable for unsuccessful student.*/
	int gradeA = 0;/*variables for each grades.*/
	int gradeB = 0;
	int gradeC = 0;
	int gradeD = 0;
	int gradeF = 0;

	int sum = 0;/*Sum of total grades*/
	int average;/*Average variable for calculating average.*/

	int randomNumber;/**/

	int mostSuccessful = -1;/*For comparison -1 assigned to most successful */
	int mostUnsuccessful = 101;/*For comparison 101 assigned to most unsuccessful*/
	int menuSelection;/*Menu selection variable*/
	int i;/*Iteration variable*/
	int studentNumber;/*Total student number*/
	studentNumber = getStudentNumber();/*Gets the students number and assings it to studentNumber variable.*/ 
	srand(40); /*srand set to 40 as you said in homework pdf.*/
	for(i = 1; i <= studentNumber;++i){	/*Loop continues between 1-studentNumber*/
			randomNumber = rand() % 101; /*This creates random numbers between 1 and 100.*/ 
			printf("%d ",   randomNumber ); /*Prints each random number generated.*/
			sum += randomNumber; /*Sum is getting bigger while the iteration is continues.*/
			if( i % 10 == 0){ /*If we printed 10 numbers then we can go to newline for clarification*/
				printf("\n");
			}
			if(randomNumber > mostSuccessful){
				mostSuccessful = randomNumber; 
				indexOfSuccessful = i;/*Finds the mostSuccessful student and index of it.*/
			}
			if(randomNumber < mostUnsuccessful){
				mostUnsuccessful = randomNumber;
				indexOfUnsuccessful = i;/*Finds the most Unsuccessful student and index of it.*/
			}
			/*Checks the numbers and increments the grade variables*/
			if(randomNumber >= 0 && randomNumber <= 59){
				gradeF++;
			}
			else if(randomNumber >= 60 && randomNumber <=69){
				gradeD++;
			}
			else if(randomNumber >= 70 && randomNumber <=79){
				gradeC++;
			}
			else if(randomNumber >= 80 && randomNumber <=89){
				gradeB++;
			}
			else if(randomNumber >= 90 && randomNumber <=100){
				gradeA++;
			}
			else{

			}
		}
		printf("\n");
	do{
		
	printf("------------------------------\n");
	printf("Student Score Calculator Menu for %d Student\n",studentNumber);
	printf("1)Most Successful Student\n");
	printf("2)Most Unsuccessful Student\n");
	printf("3)Letter Grade Statistics\n");
	printf("4)Calculate Average\n");
	printf("5)Show all Data\n");

	menuSelection = menuSelectionController();

	switch(menuSelection){
		case 1:
			displaySuccessful(mostSuccessful, indexOfSuccessful);/*Prints the most successful student*/
			break;
		case 2:
			displayUnsuccessful(mostUnsuccessful, indexOfUnsuccessful);/*Prints the most unsuccessful student*/
			break;
		case 3:
			displayGrades(gradeA, gradeB, gradeC, gradeD, gradeF);/*Displays the letterGrades.*/
			break;
		case 4:
			displayAverage(sum, studentNumber);	 /*Displays the final average.*/
			break;
		case 5:
			displaySuccessful(mostSuccessful, indexOfSuccessful);/*Displays the all info.*/
			displayUnsuccessful(mostUnsuccessful, indexOfUnsuccessful);
			displayGrades(gradeA, gradeB, gradeC, gradeD, gradeF);
			displayAverage(sum, studentNumber);
			break;
		case -1:
			printf("Exiting program...\n");/*If it's -1, quit the program.*/
			return 0;
		default:/**/
			printf("Please only enter selection between 1-5 and -1 for quit.\n"); /*If it's not -1 and not between 1-5 keep asking the selection with warning.*/

	}

	}while(menuSelection);/*While menu Selection is valid continue iterating the loop*/
	
	
}