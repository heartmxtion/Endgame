#include "../inc/header.h"

void mx_drawDeaths(SDL_Renderer *rend, int count, TTF_Font *Font, SDL_Color black) {
    char *s_count = mx_itoa(count);

    SDL_Surface *counter = TTF_RenderText_Solid(Font, s_count, black);
    SDL_Texture *counterTexture = SDL_CreateTextureFromSurface(rend, counter);
    SDL_Rect counterRect = {120, 7, counter->w, counter->h};
    SDL_RenderCopy(rend, counterTexture, NULL, &counterRect);
    SDL_DestroyTexture(counterTexture);
}

