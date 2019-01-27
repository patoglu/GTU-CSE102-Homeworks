/*IMPORTANT NOTE: Just before uploading my homework I realised my code gives error 
when map lines are not full of borders. 
For example :
50
10,10
#,#,#,#,#,#,#,#,#,#
B, , , ,#,#, , , ,#
#, ,#, , , , ,#, ,#
#, ,#,#,#,#, ,#, ,#
#, ,#, , , , ,#,#,#
#, ,#, ,#, , , , ,#
#, ,#, ,#,#,#,#,#,#
#, ,#, , , , , , ,#
#, ,#,#,#,#, ,#, ,#
#,#,#,#,#,#,F,#,#,#
This maps works perfectly because I've assumed jungle has just one empty space to get in and other lines are closed.


So this may give segmentation fault error:
50
10,10
#,#,#,#,#,#,#,#,#,#
B, , , ,#,#, , , ,#
#, ,#, , , , ,#, ,#
#, ,#,#,#,#, ,#, ,#
#, ,#, , , , ,#,#,#
#, ,#, ,#, , , , ,#
#, ,#, ,#,#,#,#,#,#
#, ,#, , , , , , ,#
#, ,#,#,#,#, ,#, ,#
#, , , , , ,F,#,#,#
Because there are other empty spaces in jungle's lines. I've implemented my code like in first map and just realised
this could give an error. I hope it won't effect my grade that much. Thank you.
Yusuf Patoglu - 151044027

*/

#include <stdio.h> /*Standart input output library*/
#include <stdlib.h> /*For rand and malloc free functions*/
#include <time.h> /*For random numbers*/
typedef struct forest_t{ /*Forest struct*/
	char **map;
	int width;
	int height;
	int flower_x;
	int flower_y;
}Forest;

typedef struct botanist_t{ /*Boranist struct */
	int coord_x;
	int coord_y;
	int waterBottleSize;
}Botanist;
void init_game(Forest *forest, Botanist *botanist); /*Initializes the game*/
void print_map(Forest *forest); /*Prints the game*/
void searchMap(Forest *forest, Botanist *botanist); /*Searches the map*/

int main(void){
	srand(time(NULL)); /*Initializing the rand function*/
	Forest *forest = (Forest*)malloc(sizeof(Forest)); /*Allocating memory for Forest Struct*/
	Botanist *botanist = (Botanist*)malloc(sizeof(Botanist));/*Allocating memory for Botanist Struct*/	
	init_game(forest, botanist); /*Initializes the game*/
	searchMap(forest, botanist); /*Searches the map with recursive method*/
	free(forest); /*Free forest struct*/
	free(botanist); /*Free botanist struct*/
	return 0;
}
void init_game(Forest *forest, Botanist *botanist){
	int i,j;/*Iterator variables*/
	char comma; /*Junk comma value*/
	char mapElement; /*Map element*/
	FILE *fptr; /*File pointer*/
	fptr = fopen("init.csv","r"); /*Opening the file in reading mode.*/
	if(fptr == NULL){
		printf("Error opening file.\n"); /*Printing error message if error occurs*/
		exit(1);
	}
	else{
		fscanf(fptr,"%d",&botanist->waterBottleSize); /*Takes the bottle size from file.*/
		fscanf(fptr,"%c%d%c%d",&comma,&forest->height,&comma,&forest->width); /*Takes the forest height and width*/
	}
	forest -> map = (char**)malloc(forest->height * sizeof(char *)); /*Allocating space for char ** */

	if(forest -> map == NULL){
		printf("Cannot allocate memory.\n");
		exit(-1);
	}  	
	for(i = 0 ; i < forest->height ; ++i){ /*Allocating space for char *  */
		forest->map[i] = (char*)malloc(forest -> width * sizeof(char));
	}
	i = -1;/*Initial value of i set to -1 because of extra newline character.*/
	j = 0;/*Initial value of i set to 0. */
	while((mapElement = fgetc(fptr)) != EOF){ /*Reading all characters from file and filters the useful ones.*/
		if(mapElement == '\n'){
			i++; /*If we're on new line then j must be zero.*/
			j = 0;			
		}
		else if((mapElement == '#') || (mapElement == ' ')|| (mapElement == 'F')|| (mapElement == 'B')){/*Useful situations*/
			if(mapElement == 'B'){/*Taking botanist coordinates*/
				botanist -> coord_x = i; 
				botanist -> coord_y = j;
			}
			else if(mapElement == 'F'){/*Taking flowers' coordinates.*/
				forest -> flower_x = i;
				forest -> flower_y = j;
			}
			forest->map[i][j] = mapElement; /*Assigning other values.*/
			j++; /*Incrementing the column*/
		}
	}
	fclose(fptr);/*Closing the file*/
}
void print_map(Forest *forest){ /*Printing the file.*/
	int i,j;
	for(i = 0 ; i < forest->height ; ++i){
		for(j = 0 ; j < forest -> width  ; ++j){
			printf("%c ",forest->map[i][j]); /*Printing all elements*/
		}
		printf("\n");
	}
}
	
void searchMap(Forest *forest, Botanist *botanist){ /*Recursive function tries to find flower.*/
	int randomNumber;/*Random number variable.*/
	printf("Water bottle size : %d\n", botanist -> waterBottleSize);
	print_map(forest); /*Printing map*/
	 /**/
	randomNumber = rand() % 4; /*Random number between 0-3 for up down left and right.*/
	if(botanist->waterBottleSize == 0){ /*This is exit condition.*/
		printf("Help! I'm on (%d,%d) !",botanist->coord_x ,botanist->coord_y);
		exit(0);
	}
	else{
		if(randomNumber == 0){ /*Moving up*/
			if(botanist->coord_x == 0){
				searchMap(forest, botanist);
			}
			if(forest->map[botanist->coord_x - 1][botanist->coord_y]!= '#'){
				forest->map[botanist->coord_x][botanist->coord_y] = ' ';
				forest->map[botanist->coord_x - 1][botanist->coord_y] = 'B';
				botanist->coord_x =  botanist->coord_x - 1;
				botanist -> waterBottleSize--;
			}
			else if(forest->map[botanist->coord_x - 1][botanist->coord_y] == '#'){
				searchMap(forest,botanist);
			}
		}
		else if(randomNumber == 1){ /*Moving right*/
			if(botanist -> coord_y == forest->width){
				searchMap(forest,botanist);
			}
			if(forest->map[botanist->coord_x][botanist->coord_y+1]!= '#'){
				forest->map[botanist->coord_x][botanist->coord_y] = ' ';
				forest->map[botanist->coord_x][botanist->coord_y+1] = 'B';
				botanist->coord_y =  botanist->coord_y + 1;
				botanist -> waterBottleSize--;
			}
			else if(forest->map[botanist->coord_x ][botanist->coord_y + 1] == '#'){
				searchMap(forest,botanist);
			}
		}
		else if(randomNumber == 2){ /*Moving down*/
			if(botanist -> coord_x == forest->height){
				searchMap(forest,botanist);
			}
			if(forest->map[botanist->coord_x +1][botanist->coord_y]!= '#'){
				forest->map[botanist->coord_x][botanist->coord_y] = ' ';
				forest->map[botanist->coord_x + 1][botanist->coord_y] = 'B';
				botanist->coord_x =  botanist->coord_x + 1;
				botanist -> waterBottleSize--;
			}
			else if(forest->map[botanist->coord_x + 1][botanist->coord_y] == '#'){
				searchMap(forest,botanist);
			}
		}
		else if(randomNumber == 3){ /*Moving left*/
			if(botanist -> coord_y == 0){
				searchMap(forest,botanist);
			}
			if(forest->map[botanist->coord_x][botanist->coord_y - 1]!= '#'){
				forest->map[botanist->coord_x][botanist->coord_y] = ' ';
				forest->map[botanist->coord_x][botanist->coord_y - 1] = 'B';
				botanist->coord_y =  botanist->coord_y - 1;
				botanist -> waterBottleSize--;
			}
			else if(forest->map[botanist->coord_x][botanist->coord_y - 1] == '#'){
				searchMap(forest,botanist);
			}
		}
		/*If we found the flower then we need to exit*/
		if(botanist -> coord_x == forest -> flower_x && botanist ->coord_y == forest -> flower_y){
			forest->map[botanist->coord_x][botanist->coord_y] = 'F';
			print_map(forest);
			printf("\n");
			printf("I have found it on (%d,%d)\n",botanist->coord_x ,botanist->coord_y);

			exit(0);
		}
		searchMap(forest, botanist); /*Recalling the function to continue searching.*/
	}
	
	
}