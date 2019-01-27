/*I couldnt write enough comment lines because of overtime.*/
/*Yusuf Patoglu 151044027*/
#include <stdio.h>
#define SIZE 8
typedef enum {white_man, black_man, white_king, black_king, empty} piece;
typedef enum{white = 10, black = 20} player;
void sample_game_1(void);
void sample_game_2(void);
void init_board(piece board[][SIZE]);
void init_board_gif(piece board[][SIZE]);
void init_board_white(piece board[][SIZE]);
void display_board(piece board[][8]);
int check_end_of_game(piece board[][8]);
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p);

int main(void){
	printf("SAMPLE GAME 1.");
	sample_game_1();
	printf("SAMPLE GAME 2.\n");
	sample_game_2();
	
	


	return 0;
}
void init_board(piece board[][8]){
	int i,j;
	for (i = 0; i < SIZE; ++i){
		for (j = 0; j < SIZE; ++j){
			board[i][j] = empty;
		}	
	}


	for(i = 0 ; i < 2 ; ++i){
		for(j = 0 ; j < SIZE ; j++){
			board[i+1][j] = black_man;
		}
	}

	for(i = SIZE - 3 ; i < SIZE - 1; ++i){
		for(j = 0 ; j < SIZE ; j++){
			board[i][j] = white_man;
		}
	}
}
void init_board_gif(piece board[][8]){
	int i,j;

	for (i = 0; i < SIZE; ++i){
		for (j = 0; j < SIZE; ++j){
			board[i][j] = empty;
		}
	}

	board[6][2] = white_man;
	board[6][3] = white_man;
	board[6][4] = white_man;
	board[6][5] = white_man;

	board[5][0] = white_man;
	board[5][1] = white_man;
	board[5][2] = white_man;
	board[5][3] = white_man;
	board[5][4] = white_man;
	board[5][6] = white_man;
	board[5][7] = white_man;

	board[4][2] = white_man;
	board[4][3] = white_man;
	board[4][4] = white_man;
	board[4][6] = white_man;
	board[4][7] = white_man;

	board[1][2] = black_man;
	board[1][3] = black_man;
	board[1][4] = black_man;
	board[1][5] = black_man;


	board[2][1] = black_man;
	board[2][2] = black_man;
	board[2][3] = black_man;
	board[2][4] = black_man;
	board[2][6] = black_man;
	board[2][7] = black_man;

	board[3][0] = black_man;
	board[3][1] = black_man;
	board[3][2] = black_man;
	
	board[3][5] = black_man;
	board[3][7] = black_man;
	board[4][5] = black_man;
	

	
}
void init_board_white(piece board[][SIZE]){
	int i,j;
	for (i = 0; i < SIZE; ++i){
		for (j = 0; j < SIZE; ++j){
			board[i][j] = empty;
		}
	}
	board[0][2] = white;
	board[1][1] = white;
}
void sample_game_1(void){
	int testIsWinFunc;
	piece board[SIZE][SIZE];
	init_board(board);
	display_board(board);
	
	printf("\n");
	move(board,5,0,4,0,white);
	display_board(board);
	printf("\n");
	move(board,2,1,3,1,black);
	display_board(board);
	printf("\n");
	move(board,5,7,4,7,white);
	display_board(board);
	printf("\n");
	move(board,2,7,3,7,black);
	display_board(board);
	printf("\n");
	move(board,4,7,0,7,white);
	display_board(board);
	printf("\n");
	move(board,3,1,4,1,black);
	display_board(board);
	printf("\n");
	move(board,5,1,4,1,white);
	display_board(board);
	printf("\n");
	move(board,2,3,3,3,black);
	display_board(board);
	printf("\n");
	move(board,5,3,4,3,white);
	display_board(board);
	printf("\n");
	move(board,3,3,7,3,black);
	display_board(board);
	printf("\n");


	/*I showed simple moves of white mans and black mans. Also proved
	they became white king and black king when they reach the bound. 
	In samplegame2 function(same in gif) mans does multiple moves in one
	function call. */
	/*I will initialize the board with full of whitemans so we'll check 
	check end of game works or not.
	*/
	if(check_end_of_game(board) == black || check_end_of_game(board) == white ){
		printf("Game over.\n");
	}
	else{
		printf("Still both players have stones.Game continues\n");
	}
	/*Since we have stones game continues */

	init_board_white(board);
	/*Initialzing board to just white*/
	if(check_end_of_game(board) == black || check_end_of_game(board) == white ){
		printf("Game over.\n");
	}
	else{
		printf("Still both players have stones.Game continues\n");
	}


	/*It will say game over.*/


}
void display_board(piece board[][8]){
	int i,j;
	for (i = 0; i < SIZE; ++i){
		for (j = 0; j < SIZE; ++j){
			if(board[i][j] == empty){
				printf("- ");
			}
			else if(board[i][j] == black_man){
				printf("b ");
			}
			else if(board[i][j] == black_king){
				printf("B ");
			}
			else if(board[i][j] == white_man){
				printf("w ");
			}
			else if(board[i][j] == white_king){
				printf("W ");
			}
		}
		printf("\n");
	}
}
int check_end_of_game(piece board[][8]){
	int i,j;
	int blackWin = 1;
	int whiteWin  = 1;
	for (i = 0; i < SIZE; ++i){
		for (j = 0; j < SIZE; ++j){
			if(board[i][j] == white_man || board[i][j] == white_king){
				blackWin = 0;
			}
		}
	}
	for (i = 0; i < SIZE; ++i){
		for (j = 0; j < SIZE; ++j){
			if(board[i][j] == black_man || board[i][j] == white_man){
				whiteWin = 0;
			}
		}
	}
	if(blackWin){
		return black;
	}
	else if(whiteWin){
		return white;
	}
}
void sample_game_2(void){
	piece board[SIZE][SIZE];
	init_board_gif(board);
	display_board(board);
	printf("\n");
	move(board,5,1,4,1,white);
	display_board(board);
	printf("\n");
	move(board,3,1,5,1,black);
	display_board(board);
	printf("\n");
	move(board,4,3,3,3,white);
	display_board(board);
	printf("\n");
	move(board,4,5,4,1,black);
	display_board(board);
	printf("\n");
	move(board,3,3,3,1,white);
	display_board(board);
	printf("\n");
	move(board,1,2,1,0,black);
	display_board(board);
	printf("\n");
	move(board,5,3,4,3,white);
	display_board(board);
	printf("\n");
	move(board,5,1,7,5,black);
	display_board(board);
	printf("\n");
	move(board,4,3,3,3,white);
	display_board(board);
	printf("\n");
	move(board,2,3,3,2,black);
	display_board(board);
	printf("\n");
	move(board,5,6,5,5,white);
	display_board(board);
	printf("\n");
	move(board,7,5,4,5,black);
	display_board(board);
	printf("\n");
	move(board,4,6,4,5,white);
	display_board(board);
	printf("\n");
}

int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p){
	int i = 0,j = 0,k = 0;
	int alreadyKing = 1;
	int moves = 0;
	int sentinel = 1;
	int boundCounter = 3;
	int aboutKing = 0;
	int a = 0;
	int kingX, kingY;
	
	if((from_x >= 0 && from_x <= 9) && (from_x >= 0 && from_y <= 9) && (to_x >= 0 && to_y <= 9) && (to_y >= 0 && to_y <= 9)){
		if(p == white){
			if(board[from_x][from_y] == white_king){
					while(a++<10){
						while(k< boundCounter){
							alreadyKing = 0;
							for(i = from_x ; i < SIZE ; ++i){
								if((board[i][from_y] == black_man) && ((i + 1) < SIZE) && (board[i+1][from_y] == empty)){
									board[from_x][from_y] = empty;
									board[i][from_y] = empty; 
									board[i+1][from_y] = white_king;	
									aboutKing = 1;
								}
							}
							k++;
							moves++;
						}
						k = 0;

				
						while((k)< boundCounter){
							alreadyKing = 0;
							for(i = from_x ; i >= 0 ; --i){
								if((board[i][from_y] == black_man) && ((i - 1) > 0) && (board[i - 1][from_y] == empty)){
									board[from_x][from_y] = empty;
									board[i][from_y] = empty; 
									board[i-1][from_y] = white_king;
									aboutKing = 1;	
								}	
							}	
							k++;
							moves++;
						}
						k = 0;

						while((k)< boundCounter){
							alreadyKing = 0;
							for(i = from_y ; i < SIZE ; ++i){
								if((board[from_x][i] == black_man) && ((i + 1) < SIZE) && (board[from_x][i + 1] == empty)){
									board[from_x][from_y] = empty;
									board[from_x][i] = empty; 
									board[from_x][i + 1] = white_king;
									aboutKing = 1;	
								}	
							}	
							k++;
							moves++;
						}
						k = 0;

						while((k)< boundCounter){
							alreadyKing = 0;
							for(i = from_y ; i >= 0;  --i){
								if((board[from_x][i] == black_man) && ((i - 1) > 0) && (board[from_x][i - 1] == empty)){
									board[from_x][from_y] = empty;
									board[from_x][i] = empty; 
									board[from_x][i - 1] = white_king;
									aboutKing = 1;
								}	
							}	
							k++;
						}
						for(i = 0 ; i < SIZE ; i++){
							for(j = 0; j < SIZE ; j++){
								if(board[i][j] == white_king){
								from_x = i;
								from_y = j;
								kingX = i;
								kingY = j;
								}
							}
						}
					}
				
				}
	

				
			

			while(sentinel && !aboutKing){
				
				if((board[from_x][from_y] == white_man) && ((board[from_x - 1][from_y] == black_man) || (board[from_x - 1][from_y] == black_king) ) && (board[from_x - 2][from_y] == empty)){
					board[from_x][from_y] = empty;
					board[from_x - 1][from_y] = empty;
					board[from_x - 2][from_y] = white_man;
					from_x = from_x - 2;
						if(from_x == 0){
							board[from_x][from_y] = white_king;
					}
					moves++;

				}
				else if((board[from_x][from_y] == white_man) && ((board[from_x][from_y - 1] == black_man) || (board[from_x][from_y - 1] == black_king)) && (board[from_x][from_y - 2] == empty)){
					board[from_x][from_y] = empty;
					board[from_x][from_y - 1] = empty;
					board[from_x][from_y - 2] = white_man;
					
					from_y = from_y - 2;
					moves++;
				}
				else if((board[from_x][from_y] == white_man) && ((board[from_x][from_y + 1] == black_man) || (board[from_x][from_y + 1] == black_king)) && (board[from_x][from_y + 2] == empty)){
					board[from_x][from_y] = empty;
					board[from_x][from_y + 1] = empty;
					board[from_x][from_y + 2] = white_man;
					from_y = from_y + 2;
					moves++;
				}
				else{
					sentinel = 0;
				
				}
			}
			if((board[from_x][from_y] == white_man) && (from_x  == to_x + 1 ) && from_y == to_y && board[to_x][to_y] == empty){ 
				board[from_x][from_y] = empty;
				board[to_x][from_y] = white_man;
				sentinel = 0;	
				return moves;
			}
			if((board[from_x][from_y] == white_man) && (from_x == to_x) && (from_y == to_y + 1) && (board[to_x][to_y] == empty)){ 
				board[from_x][from_y] = empty;
				board[from_x][to_y] = white_man;
				sentinel = 0;
				return moves;
			}
			if((board[from_x][from_y] == white_man) && (from_x == to_x) && (from_y + 1 == to_y) && (board[to_x][to_y] == empty)){ 
				board[from_x][from_y] = empty;
				board[from_x][to_y] = white_man;
				sentinel = 0;
				return moves;
			}
	   	}
		
		
		else if(p == black){
			alreadyKing = 1;
			aboutKing = 0;
			a = 0;
			k = 0;
			if((board[from_x][from_y] == black_king) && alreadyKing){
				while(a++<10){
						while(k< boundCounter){
							alreadyKing = 0;
							for(i = from_x ; i < SIZE ; ++i){
								if((board[i][from_y] == white_man) && ((i + 1) < SIZE) && (board[i+1][from_y] == empty)){
									board[from_x][from_y] = empty;
									board[i][from_y] = empty; 
									board[i+1][from_y] = black_king;	
									aboutKing = 1;
								}
							}
							k++;
							moves++;
						}
						k = 0;

				
						while((k)< boundCounter){
							alreadyKing = 0;
							for(i = from_x ; i >= 0 ; --i){
								if((board[i][from_y] == white_man) && ((i - 1) > 0) && (board[i - 1][from_y] == empty)){
									board[from_x][from_y] = empty;
									board[i][from_y] = empty; 
									board[i-1][from_y] = black_king;
									aboutKing = 1;	
								}	
							}	
							k++;
							moves++;
						}
						k = 0;

						while((k)< boundCounter){
							alreadyKing = 0;
							for(i = from_y ; i < SIZE ; ++i){
								if((board[from_x][i] == white_man) && ((i + 1) < SIZE) && (board[from_x][i + 1] == empty)){
									board[from_x][from_y] = empty;
									board[from_x][i] = empty; 
									board[from_x][i + 1] = black_king;
									aboutKing = 1;	
								}	
							}	
							k++;
							moves++;
						}
						k = 0;

						while((k)< boundCounter){
							alreadyKing = 0;
							for(i = from_y ; i >= 0;  --i){
								if((board[from_x][i] == white_man) && ((i - 1) > 0) && (board[from_x][i - 1] == empty)){
									board[from_x][from_y] = empty;
									board[from_x][i] = empty; 
									board[from_x][i - 1] = black_king;
									aboutKing = 1;
								}	
							}	
							k++;
							moves++;
						}
						for(i = 0 ; i < SIZE ; i++){
							for(j = 0; j < SIZE ; j++){
								if(board[i][j] == black_king){
								from_x = i;
								from_y = j;
								kingX = i;
								kingY = j;
								}
							}
						}
					}
			}
					
			while(sentinel && !aboutKing){
				if((board[from_x][from_y] == black_man) && ((board[from_x + 1][from_y] == white_man) || (board[from_x + 1][from_y] == white_king))&& (board[from_x + 2][from_y] == empty)){
					board[from_x][from_y] = empty;
					board[from_x + 1][from_y] = empty;
					board[from_x + 2][from_y] = black_man;
					from_x = from_x + 2;
					
					if(from_x == SIZE - 1){
						board[from_x][from_y] = black_king;
					}
					moves++;
				}
				else if((board[from_x][from_y] == black_man) && ((board[from_x][from_y - 1] == white_man) || (board[from_x][from_y - 1] == white_king)) && (board[from_x][from_y - 2] == empty)){
					board[from_x][from_y] = empty;
					board[from_x][from_y - 1] = empty;
					board[from_x][from_y - 2] = black_man;
					from_y = from_y - 2;
					moves++;
				}
				else if((board[from_x][from_y] == black_man) && ((board[from_x][from_y + 1] == white_man) || (board[from_x][from_y + 1] == white_king)) && (board[from_x][from_y + 2] == empty)){
					board[from_x][from_y] = empty;
					board[from_x][from_y + 1] = empty;
					board[from_x][from_y + 2] = black_man;
					from_y = from_y + 2;
					 if((board[from_x][from_y] == black_man) &&  ((board[from_x][from_y + 1] == white_man) || (board[from_x][from_y + 1] == white_king)) && (board[from_x][from_y + 2] == empty)){
						board[from_x][from_y] = empty;
						board[from_x][from_y + 1] = empty;
						board[from_x][from_y + 2] = black_man;
						from_y = from_y + 2;
					}
					moves++;
				}
				else{
					sentinel = 0;
				}
			}
			if((board[from_x][from_y] == black_man) && (from_x  == to_x - 1 ) && from_y == to_y && board[to_x][to_y] == empty){ 
				board[from_x][from_y] = empty;
				board[to_x][from_y] = black_man;
				sentinel = 0;
				
				return moves;
			}
			if((board[from_x][from_y] == black_man) && (from_x == to_x) && from_y == to_y + 1 && board[to_x][to_y] == empty){ 
				board[from_x][from_y] = empty;
				board[from_x][to_y] = black_man;
				sentinel = 0;
				return moves;
			}
			if((board[from_x][from_y] == black_man) && (from_x == to_x) && from_y + 1 == to_y && board[to_x][to_y] == empty){ 
				board[from_x][from_y] = empty;
				board[from_x][to_y] = black_man;
				sentinel = 0;

				return moves;
			}	
		}

	}
	else{
		return -1;

	}

	return moves;	
	
}