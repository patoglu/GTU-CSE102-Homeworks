#include <stdio.h> /*Only including standart input output library.*/
#define DATESIZE 20 /*Date size macro*/
#define TOKENSIZE 10 /*Token size macro*/
#define WEEKDAYS 7 /*Weekdays macro*/
#define MONTHNUMBER 12 /*Month number macro*/
void writeAllDates(int convertedstartDay,int convertedendDay,int convertedstartMonth, int convertedendMonth, int convertedstartYear, int convertedendYear);
/*Write all dates to file.*/
int tenMultiplier(int xTimes);
 /*Multiplies the number by ten x times.*/
int findDigitNum(char *number); /*Finds digit of number*/
void dateTokenizer(char date[], char *day, char *month, char *year, char delimeter); /*Seperates the date in day month year format*/
void stringToInteger(char *day, char *month, char *year, int *convertedDay, int *convertedMonth, int* convertedYear);/*Converts string to integer.*/
void readAllDaysWriteFormatted(); /*Reads all days in input.txt and writes them with new format with newdate.txt*/
int findDayNameOfDate(int day, int month, int year); /*This functions finds the day name of the date.*/

int main(void){
	/*Required main variables*/
	char startDate[DATESIZE]; 
	char endDate[DATESIZE]; 

	char day[TOKENSIZE]; 
	char month[TOKENSIZE]; 
	char year[TOKENSIZE];

	int convertedstartDay;
	int convertedstartMonth;
	int convertedstartYear;


	int convertedendDay;
	int convertedendMonth;
	int convertedendYear;

	printf("Please enter start date in DD/MM/YYYY format.>\n");
	scanf("%s", startDate);
	printf("Please enter end date in DD/MM/YYYY format.>\n");
	scanf("%s", endDate);
	/*Tokenizes the start date and converts it to int form*/
	dateTokenizer(startDate,day,month,year,'/');
	stringToInteger(day,month,year,&convertedstartDay,&convertedstartMonth,&convertedstartYear);
	/*Tokenizes the start date and converts it to int form*/
	dateTokenizer(endDate,day,month,year,'/');
	stringToInteger(day,month,year,&convertedendDay,&convertedendMonth,&convertedendYear);
	
	/*Writes all dates to input.txt*/
	writeAllDates(convertedstartDay, convertedendDay, convertedstartMonth, convertedendMonth, convertedstartYear, convertedendYear);
	/*Reads all dates and writes into newdate.txt*/
	readAllDaysWriteFormatted();
	

	return 0;
}
void dateTokenizer(char date[], char *day, char *month, char *year, char delimeter){
	int i = 0;
	int j = 0;
	int found = 0;
	/*Checking delimeter is in the string.*/
	while(date[i]){ 
		if(date[i++] == delimeter){
			found = 1;
		}
	}
	/*If there is no delimeter in the string, print error message and prevent segmentation fault.*/
	if(found == 0){
		printf("Can't tokenize this string. There are no matching delimeter in string.\n");
		printf("Please enter as DD/MM/YYYY format. Otherwise segment fault will occur.\n");
	}
	i = 0;
	/*Copying into day*/
	while((date[i] != delimeter) && found == 1){
		day[j] = date[i];
		++i;
		++j;
	}
	/*Terminate it with null character.*/
	day[j] = '\0';

	j = 0;
	++i;
	/*Copying into month*/
	while(date[i] != delimeter  && found == 1){
			
		month[j] = date[i];
		++i;
		++j;
	}
	/*Terminate it with null character.*/
	month[j] = '\0';

	j = 0;
	++i;
	/*Copying into month*/
	while(date[i] != '\0'  && found == 1){

		year[j] = date[i];
		++i;
		++j;
	}
	/*Terminate it with null character.*/
	year[j] = '\0';
}
void stringToInteger(char *day, char *month, char *year, int *convertedDay, int *convertedMonth, int* convertedYear){
	int i = 0;
	int number = 0;
	int numLength;
	numLength = findDigitNum(day);
	/*Finds the numerical value of day string.*/
	while(day[i] != '\0'){
		switch(day[i]){
			case '0':
				break;
			case '1':
				number = number + tenMultiplier(numLength - 1) * 1;

				break;
			case '2':
				number = number + tenMultiplier(numLength -1) * 2;
				break;
			case '3':
				number = number + tenMultiplier(numLength -1) * 3;
				break;
			case '4':
				number = number + tenMultiplier(numLength -1) * 4;
				break;
			case '5':
				number = number + tenMultiplier(numLength -1) * 5;
				break;
			case '6':
				number = number + tenMultiplier(numLength -1) * 6;
				break;
			case '7':
				number = number + tenMultiplier(numLength -1) * 7;
				break;
			case '8':
				number = number + tenMultiplier(numLength -1) * 8;
				break;
			case '9':
				number = number + tenMultiplier(numLength -1) * 9;
				break;
			default:
				break;
		}
		--numLength;
		i++;
	}
	
	i = 0;
	numLength = findDigitNum(month);
	*convertedDay = number;
	number = 0;
	/*Finds the numerical value of month string.*/
	while(month[i] != '\0'){

		switch(month[i]){
			case '0':
				break;
			case '1':
				number = number + tenMultiplier(numLength - 1) * 1;

				break;
			case '2':
				number = number + tenMultiplier(numLength -1) * 2;
				break;
			case '3':
				number = number + tenMultiplier(numLength -1) * 3;
				break;
			case '4':
				number = number + tenMultiplier(numLength -1) * 4;
				break;
			case '5':
				number = number + tenMultiplier(numLength -1) * 5;
				break;
			case '6':
				number = number + tenMultiplier(numLength -1) * 6;
				break;
			case '7':
				number = number + tenMultiplier(numLength -1) * 7;
				break;
			case '8':
				number = number + tenMultiplier(numLength -1) * 8;
				break;
			case '9':
				number = number + tenMultiplier(numLength -1) * 9;
				break;
			default:
				break;
		}
		i++;
		--numLength;
	}
	i = 0;
	numLength = findDigitNum(year);
	*convertedMonth = number;
	number = 0;
	/*Finds the numerical value of day year.*/
	while(year[i] != '\0'){
		switch(year[i]){
			case '0':
				break;
			case '1':
				number = number + tenMultiplier(numLength - 1) * 1;
				break;
			case '2':
				number = number + tenMultiplier(numLength -1) * 2;
				break;
			case '3':
				number = number + tenMultiplier(numLength -1) * 3;
				break;
			case '4':
				number = number + tenMultiplier(numLength -1) * 4;
				break;
			case '5':
				number = number + tenMultiplier(numLength -1) * 5;
				break;
			case '6':
				number = number + tenMultiplier(numLength -1) * 6;
				
				break;
			case '7':
				number = number + tenMultiplier(numLength -1) * 7;
				break;
			case '8':
				number = number + tenMultiplier(numLength -1) * 8;
				break;
			case '9':
				number = number + tenMultiplier(numLength -1) * 9;
			
				break;
			default:
				break;
		}
		i++;
		--numLength;
	}
	*convertedYear = number;

}
int tenMultiplier(int xTimes){ /*Makes the 10^n expression.*/
	int i;
	int sum = 1;
	for(i = 1 ; i <= xTimes ; ++i){
		sum = sum * 10;
	}
	return sum;
}
int findDigitNum(char *number){ /*Finds digit number of given string.*/
	int i = 0;
	while(number[i] != '\0'){
		i++;
	}
	return i;
}
void writeAllDates(int convertedstartDay,int convertedendDay,int convertedstartMonth, int convertedendMonth, int convertedstartYear, int convertedendYear){
	int i;
	int flag = 0;
	int february = 28; /*Special case for february.*/
	int startDay ;
	int startMonth ;
	

	
	int endMonth ;
	
	FILE *fp;
	fp=fopen("input_date.txt","w");

	

	startDay = convertedstartDay;
	startMonth = convertedstartMonth;


	
	endMonth = convertedendMonth;
	

	/*While startdate - enddate >= 0 this loop will continue.*/
	while((convertedendYear - convertedstartYear) >= 0){
		if(convertedendYear == convertedstartYear){
			flag = 2;
		}	
		switch(startMonth){
			/*There are 31 days in 1.3.5.6.8.10. and 12. months*/
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if(flag == 0){
					for(i = startDay; i <= 31 ; ++i){
						fprintf(fp,"%02d/%02d/%d\n", i,startMonth,convertedstartYear);	
					}	
				}
				else if(flag == 1){
					for(i = 1; i <= 31 ; ++i){
						fprintf(fp, "%02d/%02d/%d\n", i,startMonth,convertedstartYear);	
					}
				}
				else if(flag == 2 && startMonth < endMonth ){
					for(i = 1; i <= 31 ; ++i){
						fprintf(fp, "%02d/%02d/%d\n", i,startMonth,convertedstartYear);	
					}
				}
				else if(flag == 2 && startMonth == endMonth ){
					for(i = 1; i <= convertedendDay ; ++i){
						fprintf(fp, "%02d/%02d/%d\n", i,startMonth,convertedstartYear);	
					}
				}
				break;
			/*There are 28 days in February but 29 in every 4 year.*/
			case 2:
				if(convertedstartYear % 4 == 0){
					february +=1;
				}
				if(flag == 0){
					for(i = startDay; i <= february ; ++i){
						fprintf(fp,"%02d/%02d/%d\n", i,startMonth,convertedstartYear);	
					}	
				}
				else if(flag == 1){
					for(i = 1; i <= february ; ++i){
						fprintf(fp,"%02d/%02d/%d\n", i,startMonth,convertedstartYear);	
					}
				}
				else if(flag == 2 && startMonth < endMonth ){
					for(i = 1; i <= february ; ++i){
						fprintf(fp,"%02d/%02d/%d\n", i,startMonth,convertedstartYear);	
					}
				}
				else if(flag == 2 && startMonth == endMonth){
					for(i = 1; i <=  convertedendDay ; ++i){
						fprintf(fp,"%02d/%02d/%d\n", i,startMonth,convertedstartYear);	
					}
				}
				february = 28;
				break;
			
			/*There are 30 days in 4.6.9. and 11. months.*/		
			case 4:
			case 6:
			case 9:
			case 11:

				if(flag == 0){
					for(i = startDay; i <= 30 ; ++i){
						fprintf(fp,"%02d/%02d/%d\n", i,startMonth,convertedstartYear);	
					}	
				}
				else if(flag == 1){
					for(i = 1; i <= 30 ; ++i){
						fprintf(fp,"%02d/%02d/%d\n", i,startMonth,convertedstartYear);	
					}
				}
				else if(flag == 2 && startMonth < endMonth ){
					for(i = 1; i <= 30 ; ++i){
						fprintf(fp,"%02d/%02d/%d\n", i,startMonth,convertedstartYear);	
					}
				}
				else if(flag == 2 && startMonth == endMonth){
					for(i = 1; i <=  convertedendDay ; ++i){
						fprintf(fp,"%02d/%02d/%d\n", i,startMonth,convertedstartYear);	
					}
				}
				break;
			
		
		}
		flag = 1;
		if(startMonth == 12){
			startMonth = 1;
			convertedstartYear++;
		}
		else{
			startMonth++;
		}
		
	}
	fclose(fp);
}
void readAllDaysWriteFormatted(){
	char junk; /*For "/" character.*/
	int day;
	int month;
	int year;
	int dayIndex;
	int monthIndex;
	/*Weekdays array.*/
	char dayName[WEEKDAYS][DATESIZE] = {"Sunday","Monday","Tuesday","Wednesday","Thursday" 
										,"Friday","Saturday"};
	/*Month days array.*/
	char monthName[MONTHNUMBER][DATESIZE] = {"January","February","March","April","May",
											"June","July","August","September","October",
											"November","December"};
	/*Opening file.*/
	FILE * fromFile; 
	FILE *toFile;
	fromFile = fopen ("input_date.txt", "r");
	
	toFile = fopen("new_date.txt","w");
	/*Takes inputs from input txt.*/
	while(fscanf(fromFile, "%d%c%d%c%d", &day, &junk, &month, &junk, &year) != EOF){
		dayIndex = findDayNameOfDate(day,month,year);
		monthIndex = month - 1;
		/*Writes them into new_input.txt*/
		fprintf(toFile,"%s,%s %d,%d\n",dayName[dayIndex], monthName[monthIndex], day, year);
		printf("%s,%s %d,%d\n\n",dayName[dayIndex], monthName[monthIndex], day, year);
	}
   
  
}
/*There was couple algorithms to find the day name of date.
I understand Lewis Carroll's method and implemented in C programming language.
https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week#Implementation-dependent_methods*/
int findDayNameOfDate(int day, int month, int year){
	int dayIndex;
	if ( month < 3 ) /*If month is January or February increment day by year and decrement year.*/
	{
	    day += year;
	    year--;
	}
	else
	{
	    day += year - 2; /*Other wise increment day by year - 2*/
	}

	dayIndex  = (23 * month / 9) + day + 4 + year / 4 - year / 100 + year / 400; 
	dayIndex = (dayIndex % 7) ; /*Day index is equal to remainder.*/
	return dayIndex;
}