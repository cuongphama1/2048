#ifndef INITIALIZE_H_INCLUDED
#define INITIALIZE_H_INCLUDED
#include<SDL.h>
#include<bits/stdc++.h>

extern  int SCREEN_WIDTH ;
extern int SCREEN_HEIGHT ;
const std::string WINDOW_TITLE = "2048" ;

void logSDLError(std::ostream& os, const std::string &msg, bool fatal = false);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();


SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);


void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);

#endif // INITIALIZE_H_INCLUDED
