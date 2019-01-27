/*
** hw4_io.c:
**
** The source file implementing input and output functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/

/*The code may be looks little bit long. But it prints the polynomial functions in perfect shape, 
and thinks all the possibilities. I could send this one to Wolfram so they can use it
^^
(Don't get me wrong, I'm pointing
that my code is really accurate.)*/



/*Also the parameters taken as true version. (In PDF there was a wrong example)*/
#include "hw4_io.h"
#include <stdio.h>
/*This function checks the number is whole number or not*/
int isWholeNumber(double number){
	int flag = 0;
	if(number - (int)number == 0){
		flag = 1;
	}
	else{
		flag = 0;
	}
	return flag;
}

int read_polynomial3(double * a0, double * a1, double * a2, double * a3){
	scanf("%lf %lf %lf %lf",a0,a1,a2,a3); /*Reads a0,a1,a2,a3 values*/
}
int read_polynomial4(double * a0, double * a1, double * a2, double * a3, double * a4){
	scanf("%lf %lf %lf %lf %lf",a0,a1,a2,a3,a4); /*Reads a0,a1,a2,a3,a4 values*/
}
void write_polynomial3(double a0, double a1, double a2, double a3){
	if(a0 == 0 && a1 == 0 && a2 == 0 && a3 == 0){
		printf("0");
	}
		if(a3 > 0){
			if(a3 == 1){
				printf("x^3 ");
			}
			else{
				if(isWholeNumber(a3)== 1){
					printf("%.fx^3 ",a3);
				}
				else{
					printf("%.2fx^3 ",a3);
				}

			}	
		}
		else if (a3 < 0){
			if(a3 == -1){
				printf("-x^3 ");
			}
			else{
				if(isWholeNumber(a3)== 1){
					printf("%.fx^3 ",a3);
				}
				else{
					printf("%.2fx^3 ",a3);
				}
			}			
		}
		else{
			/*Print nothing because a3 = 0 which makes all the expression "0"*/
		}

	if(a2 > 0 && a3 != 0){
		if(a2 == 1){
			printf("+x^2 ");
		}
		else{
			if(isWholeNumber(a2)== 1){
				printf("+%.fx^2 ",a2);
			}
			else{
				printf("+%.2fx^2 ",a2);
			}	
		}	
	}
	else if(a2 > 0){
		if(a2 == 1){
			printf("x^2 ");
		}
		else{
			if(isWholeNumber(a2)== 1){
				printf("%.fx^2 ",a2);
			}
			else{
				printf("%.2fx^2 ",a2);
			}	
		}
	}
	else if (a2 < 0){
		if(a2 == -1){
			printf("-x^2 ");
		}
		else{
			if(isWholeNumber(a2)== 1){
				printf("%.fx^2 ",a2);
			}
			else{
				printf("%.2fx^2 ",a2);
			}	
		}
		
	}
	else{
		/*Print nothing because a2 = 0 which makes all the expression "0"*/
	}


	if(a1 > 0 && (a2 != 0 || a3 != 0 )){
		if(a1 == 1){
			printf("+x ");
		}
		else{	
			if(isWholeNumber(a1)== 1){
				printf("+%.fx ",a1);
			}
			else{
				printf("+%.2fx ",a1);
			}
		}
	}
	else if(a1 > 0){
		if(a1 == 1){
			printf("x ");
		}
		else{
			if(isWholeNumber(a1)== 1){
				printf("%.fx ",a1);
			}
			else{
				printf("%.2fx ",a1);
			}	
		}	

	}
	else if (a1 < 0){
		if(a1 == -1){
			printf("-x ");
		}
		else{
			if(isWholeNumber(a1)== 1){
				printf("%.fx ",a1);
			}
			else{
				printf("%.2fx ",a1);
			}
		}
	}
	else{
		/*Print nothing because a2 = 0 which makes all the expression "0"*/
	}

	if(a0 > 0 && (a1 != 0 || a2 != 0 || a3 != 0) ){
		if(isWholeNumber(a0)== 1){
				printf("+%.f ",a0);
			}
			else{
				printf("+%.2f ",a0);
			}
	}
	else if(a0 > 0){
		if(isWholeNumber(a0)== 1){
				printf("%.f ",a0);
			}
			else{
				printf("%.2f ",a0);
			}
	}
	else if (a0 < 0){
		if(isWholeNumber(a0)== 1){
				printf("%.f ",a0);
			}
			else{
				printf("%.2f ",a0);
			}
	}
	else{
		/*Print nothing because a2 = 0 which makes all the expression "0"*/
	}
	printf("\n\n");
}

void write_polynomial4(double a0, double a1, double a2, double a3, double a4){
	if(a0 == 0 && a1 == 0 && a2 == 0 && a3 == 0 && a4 == 0){
		printf("0");
	}

		if(a4 > 0){
			if(a4 == 1){
				printf("x^4 ");
			}
			else{
				if(isWholeNumber(a4)== 1){
					printf("%.fx^4 ",a4);
				}
				else{
					printf("%.2fx^4 ",a4);
				}

			}	
		}
		else if (a4 < 0){
			if(a4 == -1){
				printf("-x^4 ");
			}
			else{
				if(isWholeNumber(a4)== 1){
					printf("%.fx^4 ",a4);
				}
				else{
					printf("%.2fx^4 ",a4);
				}
			}			
		}
		else{
			/*Print nothing because a3 = 0 which makes all the expression "0"*/
		}

	if(a3 > 0 && a4 != 0){
		if(a3 == 1){
			printf("+x^2 ");
		}
		else{
			if(isWholeNumber(a3)== 1){
				printf("+%.fx^3 ",a3);
			}
			else{
				printf("+%.2fx^3",a3);
			}	
		}	
	}
	else if(a3 > 0){
		if(a3 == 1){
			printf("x^3 ");
		}
		else{
			if(isWholeNumber(a3)== 1){
				printf("%.fx^3 ",a3);
			}
			else{
				printf("%.2fx^3 ",a3);
			}	
		}
	}
	else if (a3 < 0){
		if(a3 == -1){
			printf("-x^3 ");
		}
		else{
			if(isWholeNumber(a3)== 1){
				printf("%.fx^3 ",a3);
			}
			else{
				printf("%.2fx^3 ",a3);
			}	
		}
		
	}
	else{
		/*Print nothing because a2 = 0 which makes all the expression "0"*/
	}


	if(a2 > 0 && (a3 != 0 || a4 != 0 )){
		if(a2 == 1){
			printf("+x^2");
		}
		else{	
			if(isWholeNumber(a2)== 1){
				printf("+%.fx^2 ",a2);
			}
			else{
				printf("+%.2fx^2 ",a2);
			}
		}
	}
	else if(a2 > 0){
		if(a2 == 1){
			printf("x^2 ");
		}
		else{
			if(isWholeNumber(a2)== 1){
				printf("%.fx^2 ",a2);
			}
			else{
				printf("%.2fx ",a2);
			}	
		}	

	}
	else if (a2 < 0){
		if(a2 == -1){
			printf("-x^2 ");
		}
		else{
			if(isWholeNumber(a2)== 1){
				printf("%.fx^2 ",a2);
			}
			else{
				printf("%.2fx^2 ",a2);
			}
		}
	}
	else{
		/*Print nothing because a2 = 0 which makes all the expression "0"*/
	}

	if(a1 > 0 && (a2 != 0 || a3 != 0 || a4 != 0) ){
		if(a1 == 1){
			printf("+x");
		}
		else{
			if(isWholeNumber(a1)== 1){
				printf("+%.fx ",a1);
			}
			else{
				printf("+%.2fx ",a1);
			}
		}
		
	}
	else if(a1 > 0){
		if(isWholeNumber(a1)== 1){
				printf("%.fx ",a1);
			}
			else{
				printf("%.2fx ",a1);
			}
	}
	else if (a1 < 0){
		if(isWholeNumber(a1)== 1){
				printf("%.fx ",a1);
			}
			else{
				printf("%.2fx ",a1);
			}
	}
	else{
		/*Print nothing because a2 = 0 which makes all the expression "0"*/
	}

	if(a0 > 0 && (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0) ){
		if(isWholeNumber(a0)== 1){
				printf("+%.f ",a0);
			}
			else{
				printf("+%.2f ",a0);
			}
	}
	else if(a0 > 0){
		if(isWholeNumber(a0)== 1){
				printf("%.f ",a0);
			}
			else{
				printf("%.2f ",a0);
			}
	}
	else if (a0 < 0){
		if(isWholeNumber(a0)== 1){
				printf("%.f ",a0);
			}
			else{
				printf("%.2f ",a0);
			}
	}
	else{
		/*Print nothing because a2 = 0 which makes all the expression "0"*/
	}
	printf("\n\n");












}