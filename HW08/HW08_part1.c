/*Sometimes I'm getting segmentation fault on this part of homework.*/
#include <stdio.h>   /*Standart input output library.*/
#include <stdlib.h> /*Stdlib for srand*/
#include <time.h> /*Time.h for time(null)*/
#define BOARDSIZE 10 /*Board size*/
typedef enum {penalty, snake, stair, boost, trap, none} blockTypes;  /*Typedef variables*/
typedef struct structureForBlocks{/*Main struct*/
	char text[10];
	int data;
	blockTypes type;
	int pos_x;
	int pos_y;
	int jump_x;
	int jump_y;
}block;
void fillStruct(block funcBoard[BOARDSIZE][BOARDSIZE]);/*Filling board function*/
void printStruct(block funcBoard[BOARDSIZE][BOARDSIZE]);/*printing struct*/
void indexSubstractor(int px, int py, int dice, int *newPx, int* newPy);/*index substractor for locations*/
void playGame(block funcBoard[BOARDSIZE][BOARDSIZE],int px, int py, int data);/*Playing game function*/

int main(){
	srand(time(NULL));/*For random numbers*/
	block board[BOARDSIZE][BOARDSIZE];/*board array in block type*/
	fillStruct(board);/*Filling struct first*/
	printStruct(board);/*Printing it*/
	playGame(board,9,9,1);/*Playing the game*/


	return 0;
}
void playGame(block funcBoard[BOARDSIZE][BOARDSIZE], int px, int py, int data){
	int drawDice; /*Drawing dice*/
	int i,j;/*Iterator variables*/
	int newPx;/*calculated variable*/
	int newPy;/*calculated variable */
	drawDice = rand() % 6 + 1; /*Dice throw*/
	indexSubstractor(px,py,drawDice,&newPx,&newPy);/*Calling index substractor to get values*/

	if(px == 0 && py == 0){	
		printf("Game Over.\n");/* if px is equal to 0 and py equal to 0 then the game is over.*/
		return;
	}
	printf("Dice : %d\n",drawDice ); /*Drawing dice*/
	printf("newPx = %d newPy = %d\n",newPx,newPy );

	if(funcBoard[newPx][newPy].type == penalty){/*Penalty part*/
		printf("penalty\n");
		playGame(funcBoard,px,py,data);
	}
	else if(funcBoard[newPx][newPy].type == snake){/*Snake part*/
		printf("Snake\n");
		px = funcBoard[newPx][newPy].jump_x;
		py = funcBoard[newPx][newPy].jump_y;
		playGame(funcBoard,px,py,data);
	}
	else if(funcBoard[newPx][newPy].type == stair){/*Stair part*/
		printf("Stair\n");
		px = funcBoard[newPx][newPy].jump_x;
		py = funcBoard[newPx][newPy].jump_y;
		playGame(funcBoard,px,py,data);
	}
	else if(funcBoard[newPx][newPy].type == boost){/*Boost part*/
		printf("boost\n");
		px = funcBoard[newPx][newPy].jump_x;
		py = funcBoard[newPx][newPy].jump_y;
		playGame(funcBoard,px,py,data);

	}
	else if(funcBoard[newPx][newPy].type == trap){/*Trap part*/
		printf("Trap\n");
		px = funcBoard[newPx][newPy].jump_x;
		py = funcBoard[newPx][newPy].jump_y;
		playGame(funcBoard,px,py,data);

	}

	else if(funcBoard[newPx][newPy].type == none){/*None part*/
		printf("None\n");
		px = funcBoard[newPx][newPy].jump_x;
		py = funcBoard[newPx][newPy].jump_y;
		playGame(funcBoard,px,py,data);

	}
}

void fillStruct( block funcBoard[BOARDSIZE][BOARDSIZE]){
	int i,j;
	int data = 1;
	int turn = 0;
	for(i = 0 ; i < BOARDSIZE ; ++i){/*Filling struct with values.*/
		if(turn % 2 == 0){
			for (j = 0; j < BOARDSIZE; ++j){
				if((data == 7) || (data == 17) || (data == 32) || (data == 57) || (data == 69) || (data == 76) || (data == 89)){
					funcBoard[BOARDSIZE - i - 1][BOARDSIZE - j - 1].type = stair;
				}
				else if((data == 6) || (data == 25) || (data == 45) || (data == 60) || (data == 63) || (data == 73) || (data == 98) || (data == 99)){
					funcBoard[BOARDSIZE - i - 1][BOARDSIZE - j - 1].type = snake;
				}
				else if((data == 13) || (data == 48) || (data == 85)){
					funcBoard[BOARDSIZE - i - 1][BOARDSIZE - j - 1].type = penalty;
				}
				else if((data == 29) || (data == 36) || (data == 50) || (data == 66) || (data == 82)){
					funcBoard[BOARDSIZE - i - 1][BOARDSIZE - j - 1].type = boost;
				}
				else if((data == 40) || (data == 54) || (data == 79) || (data == 93)){
					funcBoard[BOARDSIZE - i - 1][BOARDSIZE - j - 1].type = trap;
				}
				else{
					funcBoard[BOARDSIZE - i - 1][BOARDSIZE - j - 1].type = none;
				}
				funcBoard[BOARDSIZE - i - 1][BOARDSIZE - j - 1].data = data++;
				funcBoard[BOARDSIZE - i - 1][BOARDSIZE - j - 1].pos_x = BOARDSIZE - i - 1;
				funcBoard[BOARDSIZE - i - 1][BOARDSIZE - j - 1].pos_y = BOARDSIZE - j - 1;
				funcBoard[BOARDSIZE - i - 1][j].jump_x = BOARDSIZE - i - 1;
				funcBoard[BOARDSIZE - i - 1][j].jump_y = j; 	
			}
		}
		else{
			for (j = 0; j < BOARDSIZE; ++j){
				if((data == 7) || (data == 17) || (data == 32) || (data == 57) || (data == 69) || (data == 76) || (data == 89)){
					funcBoard[BOARDSIZE - i - 1][j].type = stair;
				}
				else if((data == 6) || (data == 25) || (data == 45) || (data == 60) || (data == 63) || (data == 73) || (data == 98) || (data == 99)){
					funcBoard[BOARDSIZE - i - 1][j].type = snake;
				}
				else if((data == 13) || (data == 48) || (data == 85)){
					funcBoard[BOARDSIZE - i - 1][j].type = penalty;
				}
				else if((data == 29) || (data == 36) || (data == 50) || (data == 66) || (data == 82)){
					funcBoard[BOARDSIZE - i - 1][j].type = boost;
				}
				else if((data == 40) || (data == 54) || (data == 79) || (data == 93)){
					funcBoard[BOARDSIZE - i - 1][j].type = trap;
				}
				else{
					funcBoard[BOARDSIZE - i - 1][j].type = none;
				}
				funcBoard[BOARDSIZE - i - 1][j].data = data++;
				funcBoard[BOARDSIZE - i - 1][j].pos_x = BOARDSIZE - i - 1;
				funcBoard[BOARDSIZE - i - 1][j].pos_y = j;
				funcBoard[BOARDSIZE - i - 1][j].jump_x = BOARDSIZE - i - 1;
				funcBoard[BOARDSIZE - i - 1][j].jump_y = j;
			}	
		}
		turn++;	
	}
	for(i = 0 ; i < BOARDSIZE ; ++i){
		for(j = 0 ; j < BOARDSIZE ; ++j){
			if(funcBoard[i][j].data == 6){
				funcBoard[i][j].jump_x = 9;
				funcBoard[i][j].jump_y = 9;
			}
			if(funcBoard[i][j].data == 7){
				funcBoard[i][j].jump_x = 8;
				funcBoard[i][j].jump_y = 0;
			}
			if(funcBoard[i][j].data == 17){
				funcBoard[i][j].jump_x = 7;
				funcBoard[i][j].jump_y = 2;
				
			}
			if(funcBoard[i][j].data == 25){
				funcBoard[i][j].jump_x = 8;
				funcBoard[i][j].jump_y = 1;
			}
			if(funcBoard[i][j].data == 29){
				funcBoard[i][j].jump_x = 6;
				funcBoard[i][j].jump_y = 3;
				
			}
			if(funcBoard[i][j].data == 32){
				funcBoard[i][j].jump_x = 4;
				funcBoard[i][j].jump_y = 1;
			}
			if(funcBoard[i][j].data == 36){
				funcBoard[i][j].jump_x = 5;
				funcBoard[i][j].jump_y = 9;
			}
			if(funcBoard[i][j].data == 40){
				funcBoard[i][j].jump_x = 6;
				funcBoard[i][j].jump_y = 4;
			}
			if(funcBoard[i][j].data == 45){
				funcBoard[i][j].jump_x = 7;
				funcBoard[i][j].jump_y = 8;
			}
			if(funcBoard[i][j].data == 50){
				funcBoard[i][j].jump_x = 4;
				funcBoard[i][j].jump_y = 4;
			}
			if(funcBoard[i][j].data == 54){
				funcBoard[i][j].jump_x = 5;
				funcBoard[i][j].jump_y = 1;
			}
			if(funcBoard[i][j].data == 57){
				funcBoard[i][j].jump_x = 2;
				funcBoard[i][j].jump_y = 6;
			}
			if(funcBoard[i][j].data == 60){
				funcBoard[i][j].jump_x = 5;
				funcBoard[i][j].jump_y = 6;
			}
			if(funcBoard[i][j].data == 63){
				funcBoard[i][j].jump_x = 4;
				funcBoard[i][j].jump_y = 1;
			}
			if(funcBoard[i][j].data == 66){
				funcBoard[i][j].jump_x = 2;
				funcBoard[i][j].jump_y = 0;
			}
			if(funcBoard[i][j].data == 69){
				funcBoard[i][j].jump_x = 2;
				funcBoard[i][j].jump_y = 6;
			}
			if(funcBoard[i][j].data == 73){
				funcBoard[i][j].jump_x = 3;
				funcBoard[i][j].jump_y = 2;
			}
			if(funcBoard[i][j].data == 76){
				funcBoard[i][j].jump_x = 1;
				funcBoard[i][j].jump_y = 7;
			}
			if(funcBoard[i][j].data == 79){
				funcBoard[i][j].jump_x = 2;
				funcBoard[i][j].jump_y = 3;
			}
			if(funcBoard[i][j].data == 82){
				funcBoard[i][j].jump_x = 1;
				funcBoard[i][j].jump_y = 3;
			}
			if(funcBoard[i][j].data == 89){
				funcBoard[i][j].jump_x = 0;
				funcBoard[i][j].jump_y = 3;
			}
			if(funcBoard[i][j].data == 93){
				funcBoard[i][j].jump_x = 1;
				funcBoard[i][j].jump_y = 2;
			}
			if(funcBoard[i][j].data == 98){
				funcBoard[i][j].jump_x = 2;
				funcBoard[i][j].jump_y = 1;
			}
			if(funcBoard[i][j].data == 99){
				funcBoard[i][j].jump_x = 4;
				funcBoard[i][j].jump_y = 5;
			}


		}
	}

}
void printStruct(block funcBoard[BOARDSIZE][BOARDSIZE]){ /*Printing struct.*/
	int i,j;
	for(i = 0 ; i < BOARDSIZE ; ++i){
		for (j = 0; j < BOARDSIZE; ++j){
			printf("%2d %2d %2d %2d %2d %2d   ",funcBoard[i][j].data,
					funcBoard[i][j].pos_x,
					funcBoard[i][j].pos_y,
					funcBoard[i][j].jump_x,
					funcBoard[i][j].jump_y,
					funcBoard[i][j].type);
					

		}
		printf("\n");
		printf("\n");
		
	}


}

void indexSubstractor(int px, int py, int dice, int *newPx, int* newPy){ /*Index substractor function.*/
	int temp;
	
	if(py >= dice && px % 2 == 1){ 
			*newPy = py - dice; 
			*newPx = px;	
	}
	else if(py < dice && px % 2 == 1){
		temp = (py - dice) * -1;
		(*newPy) = temp;
		(*newPx)--;
	}
	else if(py <= dice && px % 2 == 0){
		*newPy = *newPy + dice + 1;
		*newPx = px;
	}
	else if(py > dice && px % 2 == 0){
		temp =  (py - dice) * -1;
		(*newPy) = 9 - temp;
		(*newPx)--;
	}

}