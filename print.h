#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED

#include"initialize.h"
#include"winLose.h"
extern int board[4][4] ;
extern int c_pad ;
extern int r_pad ;
extern int cell_size ;
void printBoard(SDL_Renderer* renderer) ;

#endif // PRINT_H_INCLUDED
