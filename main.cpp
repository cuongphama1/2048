#include <bits/stdc++.h>
#include <SDL.h>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<SDL_mixer.h>
//#include<SDL_ttf.h>
#include"checkScore.h"
#include"text.h"
#include"initialize.h"
#include"print.h"

using namespace std;

 int board[4][4] ;
int dirLine[] = {1 , 0 , -1 , 0} ;
int dirColumn[] = {0 , 1 , 0 , -1} ;


void newgame() ;

void applyMove(int direction) ;
bool canDoMove(int line , int column , int nextLine , int nextColumn) ;
void addPiece() ;

pair<int , int> generateUnOccupiedPosition() ;
void playGame(SDL_Renderer*renderer , SDL_Event e) ;


 int SCREEN_WIDTH = 800;
 int SCREEN_HEIGHT = 600;
int c_pad = 0 , r_pad = 100 ;
int cell_size = (SCREEN_HEIGHT - 2*c_pad)/6 ;
int score = 0 ;

int main(int argc, char* argv[])
{

    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);
    SDL_Init(SDL_INIT_AUDIO) ;

    //TTF_Font* font = NULL;
	//SDL_Surface* surface = NULL;


    if (TTF_Init() < 0)
{
	cout << "Error" << endl ;
}
     SDL_Event e ;
     SDL_Texture *bk = loadTexture("menu.bmp", renderer);
    renderTexture(bk , renderer ,0 ,0 , 800 , 600) ;
    SDL_RenderPresent(renderer) ;
    while (true) {
        SDL_RenderClear(renderer) ;
        // Đợi 10 mili giây
        SDL_Delay(10);

        // Nếu không có sự kiện gì thì tiếp tục trở về đầu vòng lặp
        if ( SDL_WaitEvent(&e) == 0) continue;

        // Nếu sự kiện là kết thúc (như đóng cửa sổ) thì thoát khỏi vòng lặp
        if (e.type == SDL_QUIT) break;

        // Nếu nhấn phìm ESC thì thoát khỏi vòng lặp
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) break;

        // Nếu chuột (mouse) được nhấn (xuống)
        if (e.type == SDL_MOUSEBUTTONDOWN) {
            //filled_rect.x = e.button.x; // Lấy hoành độ x của chuột
            //filled_rect.y = e.button.y; // Lấy tung độ y của chuột
            // Xoá toàn bộ màn hình và vẽ lại với màu sắc tuỳ thuộc chuột trái hay phải được nhấn
            if (e.button.button == SDL_BUTTON_LEFT) {
                if(e.button.x >= 200 && e.button.x <= 560 && e.button.y >= 130 && e.button.y <= 240)
                    playGame(renderer , e) ;
                if(e.button.x >= 200 && e.button.x <= 560 && e.button.y >= 260 && e.button.y <= 370) {
                    SDL_Texture *option = loadTexture("option.bmp" , renderer) ;
                    renderTexture(option , renderer , 0 , 0 , 800 , 600) ;
                    SDL_RenderPresent(renderer) ;
                }

                if(e.button.x >= 200 && e.button.x <= 560 && e.button.y >= 410 && e.button.y <= 520)
                    return 0 ;
            }
        }
    }



     Mix_CloseAudio() ;
	//waitUntilKeyPressed();
	TTF_Quit();
    quitSDL(window, renderer);
    return 0;
}



void newgame() {
   for(int i = 0 ; i < 4 ; ++i) {
      for(int j = 0 ; j < 4 ; ++j) {
        board[i][j] = 0 ;
      }
   }
   addPiece() ;
   score = 0 ;
}



void applyMove(int direction) {
  int copyBoard[4][4] ;

  for(int i = 0 ; i < 4 ; ++i) {
    for(int j = 0 ; j < 4 ; ++j)
        copyBoard[i][j] = board[i][j] ;

  }
  int startLine = 0 , startColumn = 0 , lineStep = 1 , columnStep = 1 ;
  if(direction == 0 ) {
    startLine = 3 ;
    lineStep = -1 ;
  }
  else if(direction == 1) {
    startColumn = 3 ;
    columnStep = -1 ;
  }

  int movePossible = 0 , CanAddPiece = 0 ;
  do {
   movePossible = 0 ;
   for(int line = startLine ; line >= 0 && line < 4 ; line += lineStep) {
    for(int column = startColumn ; column >= 0 && column < 4 ; column += columnStep) {
        int nextLine = line + dirLine[direction] ;
        int nextColumn = column + dirColumn[direction] ;

        if(board[line][column] && canDoMove(line , column , nextLine , nextColumn)) {
            board[nextLine][nextColumn] += board[line][column] ;
            board[line][column] = 0 ;
            movePossible = CanAddPiece = 1 ;
        }
    }
  }
  } while(movePossible) ;
  if(CanAddPiece) {
    addPiece() ;
  }
   checkScore(copyBoard) ;
}

bool canDoMove(int line , int column , int nextLine , int nextColumn) {
  if(nextLine < 0 || nextColumn < 0 || nextLine >= 4 || nextColumn >= 4
     || (board[line][column] != board[nextLine][nextColumn] &&  board[nextLine][nextColumn] != 0))
        return false ;
  return true ;
}

pair<int , int> generateUnOccupiedPosition() {
  int occupied = 1 , line , column ;
  while(occupied) {
    line = rand() % 4 ;
    column = rand() % 4 ;
    if(board[line][column] == 0) {
        occupied = 0 ;
    }
  }
  return make_pair(line , column) ;
}

void addPiece() {
  pair<int , int> pos = generateUnOccupiedPosition() ;
  board[pos.first][pos.second] = 2 ;
}


void playGame(SDL_Renderer*renderer , SDL_Event e) {
    SDL_Texture* texture = NULL;
    TTF_Font*font = TTF_OpenFont("VeraMoBd.ttf", 30);
    SDL_Color fg = { 243, 156, 18 };
     //
    Mix_OpenAudio(44100 , MIX_DEFAULT_FORMAT , 2 , 2048) ;
    Mix_Music*backgroundSound = Mix_LoadMUS("bk.mp3") ;

    srand(time(0)) ;
    newgame();
    Mix_PlayMusic(backgroundSound , -1) ;
    while(true) {
        //srand(time(0)) ;
        SDL_RenderClear(renderer);
        //system("cls") ;

        SDL_Delay(10) ;

        if ( SDL_WaitEvent(&e) == 0) continue;

        if (e.type == SDL_QUIT) break;

        if (e.type == SDL_KEYDOWN) {
            // Nếu nhấn phìm ESC thì thoát khỏi vòng lặp
            if (e.key.keysym.sym == SDLK_ESCAPE) break;

            // Nếu phím mũi tên trái, dịch sang trái
            // (cộng chiều rộng, trừ bước, rồi lấy phần dư để giá trị luôn dương, và hiệu ứng quay vòng)
            if (e.key.keysym.sym == SDLK_LEFT) applyMove(3) ;
            // Tương tự với dịch phải, xuống và lên
            if (e.key.keysym.sym == SDLK_RIGHT) applyMove(1) ;
            if (e.key.keysym.sym == SDLK_DOWN) applyMove(0) ;
            if (e.key.keysym.sym == SDLK_UP) applyMove(2) ;
            if (e.key.keysym.sym == SDLK_n) newgame() ;


        }
        printBoard(renderer);
        renderText(texture , renderer , font , fg) ;
        SDL_RenderPresent(renderer);

    }
    Mix_FreeMusic(backgroundSound) ;

}



