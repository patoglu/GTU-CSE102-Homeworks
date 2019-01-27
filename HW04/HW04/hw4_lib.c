/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/

#include "hw4_lib.h"
#include <stdio.h>

/*Calculating integral of function with Riemann technique.*/
double integral(double f(double x), double xs, double xe, double delta){ /**/
	double sum = 0;  /*First we need to initialize our double sum variable to zero.*/

	/*While xs is smaller (and equal) than xe this loop must continue.*/
	while(xs <= xe){
	/*We divide our graph to little pieces, we multiply delta value with f(delta)
		which gives us area of that little piece.*/
		sum = sum + (delta * f(xs)); 
		/*and we need to increment xs with delta so we can continue calculating areas.*/
		xs = xs + delta;
	}
	/*Returning the final result as sum*/
	return sum;

}

/*Calculating 2d integral of function with Riemann technique.*/
double integral2(double f2(double x, double y), double xs, double xe, double ys, double ye, double delta){
	double sum = 0; /*First we need to initialize our double sum variable to zero.*/
	double i,j; /*These are iteration variables because we're going to have nested loop.*/
	i = xs; /*xs value is assigned to i*/
	while(i <= xe){ /*while i is smaller than our first dimension limit this loop must continue*/
		j = ys; /*ys value is assigned to j*/
		while(j <= ye){ /*while j is smaller than our second dimension limit this loop must continue*/
			/*This expression is same with we calculated first. The only difference is we have to think
			in 3D space so after calculating 2d integral, we have to multiply it with epsilon again so
			we can find the three dimension value.*/
			sum = sum + (f2(i,j))* delta * delta; 
			j+=delta; /*Incrementing j variable with delta*/
		}
		i+=delta; /*Incrementing i variable with delta*/
	} 
	return sum;
}

int derivatives(double f(double a), double x, double eps, double * d1, double * d2){
	double firstDervNum; /*first derivative numerator*/
	double firstDervDenum;/*first derivative denumerator*/
	double secondDervNum;/*second derivative numerator*/
	double secondDervDenum;/*send derivative denumerator*/

	firstDervNum = f(x + eps) - f(x - eps); /*Applying calculus formula to here*/
	firstDervDenum = (2.0) * eps;
	secondDervNum = f(x + eps) -  (2.0) * f(x) + f(x - eps);
	secondDervDenum = (eps * eps);
	if(firstDervDenum == 0.0 && secondDervDenum == 0.0){ /*If one of denumerators are 0. Return -1 and print error message*/
		printf("Can't calculate both d1 and d2...\n");
		return -1;
	}
	else if(firstDervDenum == 0.0 && secondDervDenum != 0.0){ /*If one of denumerators are 0. Return -1 and print error message*/
		*d2 = secondDervNum / secondDervDenum;
		printf("Can't calculate d1.\n...");
		return -1;
	}
	else if(firstDervDenum != 0.0 && secondDervDenum == 0.0){ /*If one of denumerators are 0. Return -1 and print error message*/
		*d1 = firstDervNum / firstDervDenum;
		printf("Can't calculate d2...\n");
		return -1;
	}
	else{
		printf("Calculating both d1 and d2...\n"); /*Otherwise we have no problem and so we can return both *d1 and *d2*/
		*d2 = secondDervNum / secondDervDenum;
		*d1 = firstDervNum / firstDervDenum;
		return 1;
	}
}


int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double * e1, double *e2){

	double dNumeric1, dNumeric2; /*These are our numeric derivatives*/
	double dActual1, dActual2; /*These are our actual derivatives*/
	int check; /*This variable for "derivatives'" functions return value.*/
	check = derivatives(f,x,eps,&dNumeric1,&dNumeric2); /*checks derivatives' return value*/

	dActual1 = d1(x); /*dActual1 is result of first derivative.*/
	dActual2 = d2(x); /*dActual2 is result of second derivative.*/

	if(check == -1){ /*If compare is not possible give an error mesage.*/
		printf("Can't compare these functions.\n");
		return -1;
	}
	else if(check == 1){
		*e1 = dActual1 - dNumeric1; /*Find the difference between dNumeric1 -  dActual1 and dNumeric1- dActual2*/
		*e2 = dActual2 - dNumeric2; /*Find the difference between dNumeric1 -  dActual2 and dNumeric2 - dActual2**/
		if(*e1 < 0){
			*e1 = *e1 * -1.0; /*Since we need to find absolute difference we need to check these*/
		}
		if(*e2 < 0){
			*e2 = *e2 * -1.0;
		}
		return 0;
	}

}

/*NOTE : This algorithm is not accurate for simple functions like x^2. But perfectly finds number 
of roots and real roots for such as function x ^ 3 - 6 x ^ 2 - 11x - 6 (which has 3 different
roots.) */
int find_roots(double f(double x), double * x1, double * x2, double * x3, double * x4){
	int flag = 0; /*flag value for counting number of roots*/
	double i; /*iteration value*/
	double epsilon = 0.001; /*Epsilon value*/
	*x1 = 0.0; /*Initializing all roots to zero because we need to return 0.0 for other roots*/
	*x2 = 0.0;
	*x3 = 0.0;
	*x4 = 0.0;

	for (i = -10000 ; i < 10000 ; i+= epsilon)
	{
		if(f(i) < 0.0001 && f(i) > -0.0001){ /*We'll never able to find the exact 0 value. So we need to give an error range.*/
			if(flag == 0){
				*x1 = i; /*If first root found assign it to *x1 and increment flag */
				flag++;
			}
			else if(flag == 1){
				*x2 = i;/*If second root found assign it to *x2 and increment flag */
				flag++;
			}
			else if(flag == 2){
				*x3 = i;/*If third root found assign it to *x3 and increment flag */
				flag++;
			}
			else if(flag == 3){
				*x4 = i;/*If fourth root found assign it to *x4 and increment flag */
				flag++;
			}
		}
	}
	return flag; /*return flag */
}