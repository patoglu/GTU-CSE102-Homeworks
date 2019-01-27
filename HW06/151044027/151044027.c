#include <stdio.h> /*Only including standart i/o library*/
#define BUFFERSIZE 1024 /*Maximum Buffer Size*/
void menu();  /*Menu function*/
void encrypt_open_msg();  /*Encryptor*/
void decrypt_secret_msg(); /*Decryptor*/
int find_size_of_line(char line[]); /*Finds size of given string*/
void reverse_line(char line[], int line_length); /*Reverses the given string*/
void charsGoReverse(char line[], int line_length, int key); /*Decrypts the letters in -x direction.*/
void charsGoStraight(char line[], int line_length, int key);/*Decrypts the letters in +x direction.*/
int main(void){
	menu(); /*Just calling menu function in main.*/
	return 0;
}
void menu(){
	int selection; /*Menu selection variable*/
	int sentinel = 1; /*Sentinel for controlling the loop*/
	printf("Please select a process from menu.\n"); 
	do{
		printf("1. Encrypt\n");
		printf("2. Decrypt\n");
		printf("0. Exit\n");
		printf("Choice:\n");
		scanf("%d", &selection);
		switch(selection){
			case 1:
				encrypt_open_msg(); /*Case 1 encrypts*/ 
				break;
			case 2:
				decrypt_secret_msg(); /*Case 2 decrypts*/
				break;
			case 0:
				sentinel = 0; /*Case 0 makes the sentinel 0 so loop can end*/
				break;
			default:
				printf("That's not a valid input.Try again\n"); /*Warning for invalid inputs.*/
				break;
		}		
	}while((selection < 0 || selection > 2) || sentinel == 1 );/*This loops continues while inputs are wrong*/
}
void decrypt_secret_msg(){
	int counter = 0; /*Counter for printing error message*/
	int keyNum; /*Key number that will be taken from user.*/
	int sizeOfLine;/*Size of line variable*/
	char line[BUFFERSIZE];/*Line string*/
	FILE *fromFile;/*Reading file pointer*/
	FILE *toFile;/*Writing file pointer.*/

	do{
		printf("Please enter key number>\n");
		if(counter++ > 0){
			printf("Key number must be betweem 1-26 try again.\n"); /*Printing error message*/
		}
		scanf("%d",&keyNum);/*Taking key num from user*/
		
	}while((keyNum < 1 || keyNum > 26));/*If it's not between 1-26 loop continues */


	fromFile = fopen("secret_msg.txt","r");/*Opening secret msg in read mode.*/
	toFile = fopen("open_msg.txt","w");/*Opening open msg in write mode.*/

    if(fromFile == NULL){
      printf("Error opening file!\n");  /*Checking if there are any errors*/             
    }
    if(toFile == NULL){
      printf("Error opening file!\n"); /*Checking if there are any errors*/ 
    }
 
		while (fgets (line, BUFFERSIZE, fromFile)!=NULL) { /*I used fgets function. It gets line by line from file and stops at NULL character.*/
			sizeOfLine = find_size_of_line(line);/*Finding size of line.*/ 
	        reverse_line(line,sizeOfLine);/*Reversing the line*/
	        charsGoStraight(line,sizeOfLine,keyNum);/*Decrypting the reversed line*/
	      	printf("%s",line);/*Printing it.*/
	        fprintf(toFile,"%s",line);/*Printing it to open message file.*/
    	}
   fclose(fromFile);/*Closing files*/
   fclose(toFile);/*Closing files*/
   printf("\n");
}
void encrypt_open_msg(){
	int counter = 0; /*Counter for printing error message*/
	int keyNum; /*Key number that will be taken from user.*/
	int sizeOfLine;/*Size of line variable*/
	char line[BUFFERSIZE];/*Line string*/
	FILE *fromFile;/*Reading file pointer*/
	FILE *toFile;/*Writing file pointer.*/

	do{
		printf("Please enter key number>\n");
		if(counter++ > 0){
			printf("Key number must be betweem 1-26 try again.\n"); /*Printing error message*/
		}
		scanf("%d",&keyNum); /*Taking key num from user*/
		
	}while((keyNum < 1 || keyNum > 26)); /*If it's not between 1-26 loop continues */

	fromFile = fopen("open_msg.txt","r"); /*Opening open msg in read mode.*/
	toFile = fopen("secret_msg.txt","w"); /*Opening secret msg in write mode.*/

   if(fromFile == NULL){
      printf("Error opening file!\n");   /*Checking if there are any errors*/             
   }
   if(toFile == NULL){
      printf("Error opening file!\n");  /*Checking if there are any errors*/   
   }
 
		while (fgets (line, BUFFERSIZE, fromFile)!=NULL) { /*I used fgets function. It gets line by line from file and stops at NULL character.*/
		
			sizeOfLine = find_size_of_line(line);  /*Finding size of line.*/ 
	        reverse_line(line,sizeOfLine); /*Reversing the line*/
	        charsGoReverse(line,sizeOfLine,keyNum); /*Decrypting the reversed line*/
	      	printf("%s", line);	/*Printing it.*/
	        fprintf(toFile,"%s",line);/*Printing it to open message file.*/
    	}
   fclose(fromFile);/*Closing files*/
   fclose(toFile);/*Closing files*/
   printf("\n");

}
int find_size_of_line(char line[]){
	int i = 0;
	while(line[i] != '\0'){ /*This loop will continue till it reaches the end line*/
		++i;/*Increments the counter*/
	}
	return i;/*Returns the counter*/
}
void reverse_line(char line[], int line_length){
	int i,k;
	char temp;
	for(i = 0 , k = line_length - 2 ; i < (int) line_length / 2 ; ++i,--k){ /*This loop reverses the given string*/
		temp = line[i];
		line[i] = line[k];
		line[k] = temp;
	}
	line[line_length] = '\0'; /*Terminating it with null character.*/
}
void charsGoReverse(char line[], int line_length, int key){
	int i ;/**/
	for (i = 0; i < line_length; ++i){/*This loop will turn linelength times*/
		if(line[i] >= 'a' && line[i] <= 'z'){/*Since only small letters will be in file. I just controlled (a-z).*/
			if((line[i] - key ) < 'a'){
				line[i] = 'z' - 'a' + line[i] - key + 1; /*If it reaches bound we need to turn back to first letter then increment*/
			}
			else{
				line[i] = line[i] - key;	/*If it doesnt reach bound we'll simply increment.*/
			}
		}
		else if(line[i] == ' '){
			line[i] = '_'; /*If there is a space makes it "_" */
		}
		else if(line[i] == '.'){
			line[i] = '*'; /*If there is a dot makes it "*" */
		}
		
	}
}
void charsGoStraight(char line[], int line_length, int key){
	int i ;
	for (i = 0; i < line_length; ++i){/*This loop will turn linelength times*/
		if(line[i] >= 'a' && line[i] <= 'z'){/*Since only small letters will be in file. I just controlled (a-z).*/
			if((line[i] + key ) > 'z'){/*Since only small letters will be in file. I just controlled (a-z).*/
				line[i] = 'a' + key - 'z' + line[i] - 1;/*If it reaches bound we need to turn back to first letter then increment*/
			}
			else{
				line[i] = line[i] + key; /*If it doesnt reach bound we'll simply increment.*/	
			}
		}
		else if(line[i] == '_'){ /*If there is a underlinechar makes it " " */
			line[i] = ' ';
		}
		else if(line[i] == '*'){ /*If there is a star makes it " " */
			line[i] = '.';
		}	
	}
}