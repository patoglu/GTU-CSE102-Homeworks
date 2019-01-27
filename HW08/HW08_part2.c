#include <stdio.h> /*Including standart input output library.*/
#include <string.h> /*Including string header for copying from temporary char array.*/
char* find_operations(int arr[], int expected_val, char operations[], size_t arr_len, int cursor, int current); /*Function prototype*/


int main(void){
	int arr[] = {25,12,6,10,32,8}; /*Test array*/
	int expected_val = 44; /*Expected value*/
	char operations[] = "     "; /*Operations that will be filled.*/
	size_t arr_len = 6; /*Size of array.*/
	int cursor= 0; /*Cursor assigned to 0.*/
	int current; /*Current variable*/
	current = arr_len;/*Current is always equals to arr_len(I've done it */
	
	
	printf("%s\n",find_operations(arr,expected_val,operations,arr_len,cursor,current));  /*Calling the function*/








	return 0;
}

char* find_operations(int arr[], int expected_val, char operations[], size_t arr_len, int cursor, int current){
	int i,j; /*Iterator variables*/
	
	char defOperators[3][current];  /*This [current] index value gives warning in C90 standart. Since our current value is not taken by user
									I thought it's unnecessary to allocate memory.*/
	char check[]="     "; 
	int first=arr[0];

	if(arr_len == 1){ 
	
		if(arr[0] == expected_val){ /*If array length is 1 and expected value is equal to our first element of array then we found a solution.*/
			return operations; /*Note that I've always stored sum in array's first element. Of course I recovered it after my process done.*/
		}
		else{ /*Else fill char array with empty spaces.*/
	
			for(i=0;i<current-1;i++){ /

				operations[i]=' ';

			}	
			operations[current-1]='\0';	 /*Adding null character end of string.*/
			return operations; 
		}
	}
	for(i=0;i<3;i++){ /*Iterating till operator count */
		for(j=0;j<current;j++){
			if(j==current-1)
				defOperators[i][j]='\0'; 
			else
				defOperators[i][j] = operations[j];
		}
	}
	
	arr[0]+=arr[current-arr_len+1];
	defOperators[0][cursor] = '+'; /*0. row is for summation*/
	
	
	defOperators[1][cursor] = '-'; /*1, row for substraction*/
	defOperators[2][cursor] = '*'; /*2. row for multiply.*/
	
	strcpy(check,find_operations(arr,expected_val,defOperators[0],arr_len-1,cursor + 1, current));  /*Copying functions return value into check.*/

	if(check[0]!=' '){ /*If the check value's first element is not equals to space then this is a possible value */
		
		strcpy(operations,check);  /*So we copy it into operations.*/
		return operations; /*Then return it*/
	}
	arr[0]=first; /*Store it in first element*/
	arr[0]-=arr[current-arr_len+1]; /*Decrement first element by arr[current - arr -len + 1]*/
	
	strcpy(check,find_operations(arr,expected_val,defOperators[1],arr_len-1,cursor + 1, current)); /*Copying functions return value into check.*/

	if(check[0]!=' '){ /*If the check value's first element is not equals to space then this is a possible value */
		
	
		strcpy(operations,check);/*So we copy it into operations.*/
		return operations; /*Then return it*/

	}
	arr[0]=first;/*Store it in first element*/
	arr[0]*=arr[current-arr_len+1];/*Multiply first element by arr[current - arr -len + 1]*/
	
	strcpy(check,find_operations(arr,expected_val,defOperators[2],arr_len-1,cursor + 1, current)); /*Copying functions return value into check.*/

	if(check[0]!=' '){
		
		strcpy(operations,check);/*So we copy it into operations.*/
		return operations;/*Then return it*/
	}
	arr[0]=first;/*Store it in first element*/

	for(i=0;i<current-1;i++){

		operations[i]=' ';

	}
	operations[current-1]='\0';
	return operations;

}
