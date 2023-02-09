#include "../inc/header.h"

int mx_intro(SDL_Renderer *rend, SDL_Event event) {
    SDL_Color black = {255, 255, 255, 255}; // Если у тебя возникает вопрос почему тут black, то ты просто не шаришь, чел
    TTF_Font *Font = TTF_OpenFont("resource/fonts/OpenSans-Regular.ttf", 64);
    Entity *titleBackground = mx_create_box(rend, 0, 0, SCREEN_HEIGHT, SCREEN_WIDTH, BG_INTRO, 0);
    SDL_Surface *titleSurface = TTF_RenderText_Solid(Font, "cumPUSYata devs presents", black);
    SDL_Texture *titleTexture = SDL_CreateTextureFromSurface(rend, titleSurface);
    SDL_Rect titleRect = {245, 250, titleSurface->w, titleSurface->h};
    SDL_Surface *titleSurface2 = TTF_RenderText_Solid(Font, "Super Slime John", black);
    SDL_Texture *titleTexture2 = SDL_CreateTextureFromSurface(rend, titleSurface2);
    SDL_Rect titleRect2 = {397, 250, titleSurface2->w, titleSurface2->h};
    Mix_Chunk *intro1 = Mix_LoadWAV("resource/audio/intro1.wav");
    Mix_Chunk *intro2 = Mix_LoadWAV("resource/audio/intro2.wav");
    Mix_VolumeChunk(intro1 ,MIX_MAX_VOLUME/10);
    Mix_VolumeChunk(intro2 ,MIX_MAX_VOLUME/10);
    Mix_PlayChannel(-1, intro1, 0);
    
    time_t starttime;
    time_t endtime;
    time(&starttime);

    int start = 1;
    bool ft = false;
    while(start == 1){
        time(&endtime);
        while(SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                start = 0;
                break;
            }
        }
        if(difftime(endtime, starttime) < 2.0){
            SDL_RenderCopy(rend, titleBackground->tex, NULL, &titleBackground->rect);
            SDL_RenderCopy(rend, titleTexture, NULL, &titleRect);
            SDL_RenderPresent(rend);
        }
        if(difftime(endtime, starttime) == 2.0 && !ft){
            SDL_RenderClear(rend);
            Mix_PlayChannel(-1, intro2, 0);
            ft = true;
        }
        if(difftime(endtime, starttime) >= 2.0){
            SDL_RenderCopy(rend, titleBackground->tex, NULL, &titleBackground->rect);
            SDL_RenderCopy(rend, titleTexture2, NULL, &titleRect2);
            SDL_RenderPresent(rend);
        }
    
        if(difftime(endtime, starttime) == 4.0){
            start = 1;
            SDL_RenderClear(rend);
            break;
        } 
        SDL_Delay(1);
    }
    SDL_DestroyTexture(titleTexture2);
    SDL_DestroyTexture(titleTexture);
    mx_clear_entity(titleBackground);
    Mix_FreeChunk(intro1);
    Mix_FreeChunk(intro2);
    return start;
}

