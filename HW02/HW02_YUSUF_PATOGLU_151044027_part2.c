#include <stdio.h>
int takeNumber(void); /*Takes the number from user. Checks the number valid or not till valid number entered.*/
int findDigitNumber(int number);/*Finds the digit number of number*/
int main(void){
	int digit;  /*single digit variable*/
	int i; /*iteration variable*/
	int number; /*original number*/
	int digitNumber; /*Digit number*/
	int first=0; /*First, second,third,fourth and fifth digit numbers.*/
	int second=0;
	int third=0;
	int fourth=0;
	int fifth = 0;
	
	number = takeNumber(); /*Takes the number from user till valid and assingns to number variable */
	digitNumber = findDigitNumber(number);
	if(digitNumber == 5){ /*If the number is 5 we'll use all 5 variables (first, second, third, fourth and fifth.*/
		for(i = 1; i <= digitNumber ; ++i){
			digit = number % 10; /*Takes the last digit of number and assings it to single digit variable.*/
			if(i == 1){
				first = digit;
			}
			else if(i == 2){
				second = digit;
			}
			else if(i == 3){
				third = digit;
			}
			else if(i == 4){		
				fourth = digit;
			}
			else  if(i == 5){
				fifth = digit;
			}
			else{

			}
			number = number / 10; /*Makes the integer division so we can continue taking modulus of last digit*/
		}
		printf("The fifth digit is %d \n",fifth); /*Prints the result*/
		printf("The fourth digit is %d \n",fourth);
		printf("The third digit is %d \n",third);
		printf("The second digit is %d \n",second);
		printf("The first digit is %d \n",first);

	}
	else if(digitNumber == 4){ /*If the number is 4 we'll use all 4 variables (first, second, third and fourth.*/
			for(i = 1; i <= digitNumber ; ++i){
			digit = number % 10; /*Takes the last digit of number and assings it to single digit variable.*/
			if(i == 1){
				first = digit;
			}
			else if(i == 2){
				second = digit;
			}
			else if(i == 3){
				third = digit;
			}
			else if(i == 4){		
				fourth = digit;
			}
			else{

			}
			number = number / 10;  /*Makes the integer division so we can continue taking modulus of last digit*/
		}
		printf("The fourth digit is %d \n",fourth); /*Prints the result*/
		printf("The third digit is %d \n",third);
		printf("The second digit is %d \n",second);
		printf("The first digit is %d \n",first);

	} 
	else if(digitNumber == 3){ /*If the number is 3 we'll use all 3 variables (first, second and third)*/
			for(i = 1; i <= digitNumber ; ++i){
			digit = number % 10; /*Takes the last digit of number and assings it to single digit variable.*/
			if(i == 1){
				first = digit;
			}
			else if(i == 2){
				second = digit;
			}
			else if(i == 3){
				third = digit;
			}
			else{

			}
			number = number / 10;  /*Makes the integer division so we can continue taking modulus of last digit*/
		}
		printf("The third digit is %d \n",third); /*Prints the result*/
		printf("The second digit is %d \n",second);
		printf("The first digit is %d \n",first);
	}
	else if(digitNumber == 2){ /*If the number is 2 we'll use all 2 variables (first and second).*/
			for(i = 1; i <= digitNumber ; ++i){
				digit = number % 10; /*Takes the last digit of number and assings it to single digit variable.*/
				if(i == 1){
					first = digit;
				}
				else if(i == 2){
					second = digit;
				}
				else{

				}
				number = number / 10;  /*Makes the integer division so we can continue taking modulus of last digit*/
			}
		printf("The second digit is %d \n",second); /*Prints the result*/
		printf("The first digit is %d \n",first);
	}

	

}
int takeNumber(void){
	int number;
	int counter = 0;
	do{
		if(counter>0){
			printf("Please enter a valid number(between 23 - 98760)\n");
		}
		else{
			printf("Please enter a number.\n");
		}
		scanf("%d",&number);
		counter++;	

	}while(number < 23 || number > 98760); /*Keeps the loop till the number is valid*/

	return number;
}
int findDigitNumber(int number){
	int counter = 0;
	while(number){
		number = number / 10; /*Increments the counter till the number is zero so we can find the digit number and return it.*/
		counter++; 
	}
	return counter;
}