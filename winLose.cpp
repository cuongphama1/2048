#include"winLose.h"

void check(SDL_Renderer* renderer) {
  int checkLose = 0 ;
  int checkWin = 0 ;
  int tempBoard[6][6] ;

  for(int i = 0 ; i < 6 ; ++i) {
    for(int j = 0 ; j < 6 ; ++j) {
        tempBoard[i][j] = 0 ;
    }
  }

  for(int i = 1 ; i <= 4 ; ++i) {
    for(int j = 1 ; j <= 4 ; ++j) {
        tempBoard[i][j] = board[i-1][j-1] ;
    }
  }

  for(int i = 1 ; i <= 4 ; ++i) {
    for(int j = 1 ; j <= 4 ; ++j) {
        if(tempBoard[i][j] == tempBoard[i-1][j] || tempBoard[i][j] == tempBoard[i][j-1]
           || tempBoard[i][j] == tempBoard[i+1][j] || tempBoard[i][j] == tempBoard[i][j+1] )
            checkLose += 1 ;
    }
  }
  //checkLose = 0 ;
  if(checkLose == 0) {
    //SDL_RenderClear(renderer) ;
    SDL_Texture *imageLose = loadTexture("lose.bmp", renderer);
    renderTexture(imageLose , renderer , 550 , 50 , 200 , 400) ;
    SDL_RenderPresent(renderer) ;
  }

  for(int i = 0 ; i < 4 ; ++i) {
    for(int j = 0 ; j < 4 ; j++) {
        if(board[i][j] == 2048)
            checkWin = 1 ;
    }
  }
  //checkWin = 1 ;
  if(checkWin == 1) {
    SDL_Texture *imageLose = loadTexture("win.bmp", renderer);
    renderTexture(imageLose , renderer , 550 , 50 , 200 , 400) ;
    SDL_RenderPresent(renderer) ;
  }
}

