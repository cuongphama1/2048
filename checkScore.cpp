#include"checkScore.h"
void checkScore(int copyBoard[4][4]) {
  int now2 , now4 , now8 , now16 , now32 , now64 , now128 , now256 , now512 , now1024 , now2048  ;
  int cop2 , cop4 , cop8 , cop16 , cop32 , cop64 , cop128 , cop256 , cop512 , cop1024 , cop2048  ;
   now2 = now4 = now8 = now16 = now32 = now64 = now128 = now256 = now512 = now1024 = now2048 = 0 ;
   cop2 = cop4 = cop8 = cop16 = cop32 = cop64 = cop128 = cop256 = cop512 = cop1024 = cop2048 = 0 ;
   for(int i = 0 ; i < 4 ; ++i) {
    for(int j = 0 ; j < 4 ; j++) {
        if(board[i][j] == 2)
            now2 += 1 ;
        if(board[i][j] == 4)
            now4 += 1 ;
        if(board[i][j] == 8)
            now8 += 1 ;
        if(board[i][j] == 16)
           now16 += 1 ;
        if(board[i][j] == 32)
           now32 += 1 ;
        if(board[i][j] == 64)
           now64 += 1 ;
        if(board[i][j] == 128)
           now128 += 1 ;
        if(board[i][j] == 256)
           now256 += 1 ;
        if(board[i][j] == 512)
           now512 += 1 ;
        if(board[i][j] == 1024)
           now1024 += 1 ;
        if(board[i][j] == 2048)
           now2048 += 1 ;
        if(copyBoard[i][j] == 2)
            cop2 += 1 ;
        if(copyBoard[i][j] == 4)
            cop4 += 1 ;
        if(copyBoard[i][j] == 8)
            cop8 += 1 ;
        if(copyBoard[i][j] == 16)
            cop16 += 1 ;
        if(copyBoard[i][j] == 32)
            cop32 += 1 ;
        if(copyBoard[i][j] == 64)
            cop64 += 1 ;
        if(copyBoard[i][j] == 128)
            cop128 += 1 ;
        if(copyBoard[i][j] == 256)
            cop256 += 1 ;
        if(copyBoard[i][j] == 512)
            cop512 += 1 ;
        if(copyBoard[i][j] == 1024)
            cop1024 += 1 ;
        if(copyBoard[i][j] == 2048)
            cop2048 += 1 ;

    }
  }
      if(now2 > cop2)
        score += (now2 - cop2)*2 ;
      if(now4 > cop4)
        score += (now4 - cop4)*4 ;
      if(now8 > cop8)
        score += (now8 - cop8)*8 ;
      if(now16 > cop16)
        score += (now16 - cop16)*16 ;
      if(now32 > cop32)
        score += (now32 - cop32)*32 ;
      if(now64 > cop64)
        score += (now64 - cop64)*64 ;
      if(now128 > cop128)
        score += (now128 - cop128)*128 ;
      if(now256 > cop256)
        score += (now256 - cop256)*256 ;
      if(now512 > cop512)
        score += (now512 - cop512)*512 ;
      if(now1024 > cop1024)
        score += (now1024 - cop1024)*1024 ;
      if(now2048 > cop2048)
        score += (now2048 - cop2048)*2048 ;


}
