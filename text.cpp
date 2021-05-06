#include"text.h"

void renderText(SDL_Texture*texture , SDL_Renderer*renderer , TTF_Font*font , SDL_Color fg) {
    std::string text = std::to_string(score);
	SDL_Surface*surface = TTF_RenderText_Solid(font, text.c_str(), fg);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	SDL_Rect srcRest;
	SDL_Rect desRect;
	TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h);

	srcRest.x = 0;
	srcRest.y =  0;

	desRect.x = 700;
	desRect.y = 500;

	desRect.w = srcRest.w;
	desRect.h = srcRest.h;
 SDL_RenderCopy(renderer, texture, &srcRest, &desRect);
}
