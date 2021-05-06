#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED
#include<SDL.h>
#include<SDL_ttf.h>
#include<bits/stdc++.h>

extern int score ;

void renderText(SDL_Texture*texture , SDL_Renderer*renderer , TTF_Font*font , SDL_Color fg ) ;


#endif // TEXT_H_INCLUDED
