#include"print.h"

void printBoard(SDL_Renderer* renderer) {
   //system("cls") ;
   SDL_RenderClear(renderer) ;
   SDL_Texture *imageBK = loadTexture("background.bmp", renderer);
   renderTexture(imageBK , renderer , 0 , 0 , 800 , 600) ;
   for(int i = 0 ; i < 4 ; ++i) {
    for(int j = 0  ; j < 4 ; ++j) {
         if(board[i][j] == 0) {
                //cout<<board[i][j]<<" ";
            SDL_Texture *image0 = loadTexture("0.bmp", renderer);
            renderTexture(image0 , renderer , r_pad + j*cell_size , c_pad + i*cell_size , cell_size , cell_size) ;
        }
        else if(board[i][j] == 2)
            {
                //cout<<board[i][j]<<" ";
            SDL_Texture *image2 = loadTexture("2.bmp", renderer);
            renderTexture(image2 , renderer , r_pad + j*cell_size , c_pad + i*cell_size , cell_size , cell_size) ;
        }
        else if(board[i][j] == 4) {
                            //   cout<<board[i][j]<<" ";
            SDL_Texture *image4 = loadTexture("4.bmp", renderer);
            renderTexture(image4 , renderer , r_pad + j*cell_size , c_pad + i*cell_size , cell_size , cell_size) ;
        }
        else if(board[i][j] == 8) {
                           // cout<<board[i][j]<<" ";
            SDL_Texture *image8 = loadTexture("8.bmp", renderer);
            renderTexture(image8 , renderer , r_pad + j*cell_size , c_pad + i*cell_size , cell_size , cell_size) ;
        }
        else if(board[i][j] == 16) {
                          //  cout<<board[i][j]<<" ";
            SDL_Texture *image16 = loadTexture("16.bmp", renderer);
            renderTexture(image16 , renderer , r_pad + j*cell_size , c_pad + i*cell_size , cell_size , cell_size) ;
        }
        else if(board[i][j] == 32) {
                           // cout<<board[i][j]<<" ";
            SDL_Texture *image32 = loadTexture("32.bmp" , renderer) ;
            renderTexture(image32 , renderer , r_pad + j*cell_size , c_pad + i*cell_size , cell_size , cell_size) ;
        }
        else if(board[i][j] == 64) {
                           // cout<<board[i][j]<<" ";
            SDL_Texture *image64 = loadTexture("64.bmp", renderer);
            renderTexture(image64 , renderer , r_pad + j*cell_size , c_pad + i*cell_size , cell_size , cell_size) ;
        }
        else if(board[i][j] == 128) {
                           // cout<<board[i][j]<<" ";
            SDL_Texture *image128 = loadTexture("128.bmp", renderer);
            renderTexture(image128 , renderer , r_pad + j*cell_size , c_pad + i*cell_size , cell_size , cell_size) ;
        }
         //renderTexture(img[board[i][j]], renderer, r_pad + j*cell_size , c_pad + i*cell_size , cell_size , cell_size);
        else if(board[i][j] == 256) {
                           // cout<<board[i][j]<<" ";
            SDL_Texture *image128 = loadTexture("256.bmp", renderer);
            renderTexture(image128 , renderer , r_pad + j*cell_size , c_pad + i*cell_size , cell_size , cell_size) ;
        }
        else if(board[i][j] == 512) {
                           // cout<<board[i][j]<<" ";
            SDL_Texture *image128 = loadTexture("512.bmp", renderer);
            renderTexture(image128 , renderer , r_pad + j*cell_size , c_pad + i*cell_size , cell_size , cell_size) ;
        }
        else if(board[i][j] == 1024) {
                           // cout<<board[i][j]<<" ";
            SDL_Texture *image128 = loadTexture("1024.bmp", renderer);
            renderTexture(image128 , renderer , r_pad + j*cell_size , c_pad + i*cell_size , cell_size , cell_size) ;
        }
        else if(board[i][j] == 2048) {
                           // cout<<board[i][j]<<" ";
            SDL_Texture *image128 = loadTexture("2048.bmp", renderer);
            renderTexture(image128 , renderer , r_pad + j*cell_size , c_pad + i*cell_size , cell_size , cell_size) ;
        }
    }
    //cout<<"\n";

   }
   check(renderer) ;

   //SDL_RenderPresent(renderer);
}
