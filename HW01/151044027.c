#include <stdio.h>  /*Standart input output library*/
#include <math.h>   /*Math library for pow(),sqrt() etc. functions.*/
#define PI 3.14
  /*Function prototypes*/
double getSidex();  /*Gets the x side of rectangle.*/
double getSidey();  /*Gets the y side of rectange.*/
double circle_area(double radius);  /*Calculates the circle area.*/
double calc_hypotenuse(int side1, int side2);  /*Calculates the hypotenuse*/
double calc_radius_of_smallest_circle(int side1, int side2);  /*Calculates the radius of smallest circle.*/ 
double calc_radius_of_largest_circle(int side1, int side2);  /*Calculates the radius of largest circle.*/
double calc_area_of_smallest_circle(int side1, int side2);  /*Calculates the area of smallest circle.*/
double calc_area_of_largest_circle(int side1, int side2);  /*Calculates the area of largest circle.*/
double calc_area_of_smallest_square(int side1, int side2);  /*Calculates the area of smallest square*/
double calc_area_of_largest_square(int side1, int side2);  /*Calculates the are of largest square.*/
double calc_area_of_square (int side);  /*Calculates the are of a square.*/
void display_results();  /*A function for show final results.*/
/*Function prototypes end*/

int main()
{
	display_results();  /*Just calling display results on main for clarification.*/
	return 0;
}
double circle_area(double radius){
	double area;
	area = PI * pow(radius,2);   /* pi *r *r  */
	return area;
}
double calc_area_of_square (int side){
	double area; 
	area = pow(side, 2);   /*side * side */
	return area;
}

double calc_hypotenuse(int side1, int side2){
	double hipotenus;

	hipotenus = pow(side1,2) + pow(side2,2); 

	hipotenus = sqrt(hipotenus);  /* x^2 = y^2 + z^2*/

	return hipotenus;

}
double calc_radius_of_largest_circle(int side1, int side2){
	if(side1 > side2){
		return side2 / 2.0;   /*returns the smaller one*/
	}
	else{
		return side1 / 2.0;
	}
}
double calc_area_of_largest_circle(int side1, int side2){
	double radius;
	double area;
	radius = calc_radius_of_largest_circle(side1,side2);   /*Calculates the radius of largest circle*/
	area = circle_area(radius);
	return area;
}

double calc_radius_of_smallest_circle(int side1, int side2){
	double hypotenuse;
	double radius;
	hypotenuse = calc_hypotenuse(side1, side2);   /*Calculates the hypotenuse*/
	radius = hypotenuse / 2.0;
	return radius;
}
double calc_area_of_smallest_circle(int side1, int side2){
	double radius;
	double area;
	radius = calc_radius_of_smallest_circle(side1, side2);   /*Calculates the radius of smallest circle*/
	area = circle_area(radius);
	return area;
}
double calc_area_of_smallest_square(int side1, int side2){
	double area;
	if(side1>side2){
		area = pow(side1,2);   /*Returns the area which has larger side.*/
	}
	else{
		area = pow(side2,2);
	}
	return area;
}
double calc_area_of_largest_square(int side1, int side2){
	

	double area;
	if(side1>side2){
		area = pow(side2,2);    /*Returns the area which has smaller side.*/
	}
	else{
		area = pow(side1,2);
	}
	return area;
}

double getSidex(){
	double firstSide;
	printf("Please enter first side: ");   /*Takes the x side from user*/
	scanf("%lf", &firstSide);
	return firstSide;

}
double getSidey(){
	double secondSide;
	printf("Please enter the second side: ");   /*Takes the y side from user*/
	scanf("%lf", &secondSide);
	return secondSide;
}
void display_results(void){
	int x;
	int y;
	
	double largest_circle;
	double largest_square;
	double smallest_circle;
	double smallest_square;

	x = getSidex();
	y = getSidey();

	largest_circle = calc_area_of_largest_circle(x,y);
	largest_square = calc_area_of_largest_square(x,y);
	smallest_circle = calc_area_of_smallest_circle(x,y);
	smallest_square = calc_area_of_smallest_square(x,y);
	  /*Prints the final results with 2 digits after dot*/
	printf("The area of the largest circle that fits inside a rectangle is: ");
	printf("%.2f\n",largest_circle);

	printf("The area of the largest square that fits inside the rectangle is : ");
	printf("%.2f\n",largest_square);

	printf("The area of the smallest circle that surrounds the same rectangle is: ");
	printf("%.2f\n",smallest_circle);

	printf("The area of the smallest square that surrounds the same rectangle is: ");
	printf("%.2f\n",smallest_square);

}	
