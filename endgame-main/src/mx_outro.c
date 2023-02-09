#include "../inc/header.h"

int mx_outro(SDL_Renderer *r) {
    Mix_HaltMusic();    
    Entity *bk = mx_create_box(r, 0, 0, SCREEN_HEIGHT, SCREEN_WIDTH, 14, UP);
    Mix_Music *backgroundSound = Mix_LoadMUS("resource/audio/outro_music.mp3");
    Mix_VolumeMusic(MIX_MAX_VOLUME/10);
    SDL_Event e;
    SDL_PollEvent(&e);
    const Uint8 *keystate = SDL_GetKeyboardState(NULL);

    int run = 1;
    Mix_PlayMusic(backgroundSound, -1);
    while (run == 1) {
        while(SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                Mix_HaltMusic(); 
                return 0;
            }
        }
        if( keystate[ SDL_SCANCODE_SPACE ] ) {   
            Mix_HaltMusic();    
            return 1;
        }
        SDL_RenderCopy(r, bk->tex, NULL, &bk->rect);
        SDL_RenderPresent(r);
        SDL_Delay(1000/120);
    }
    return 1;
}

