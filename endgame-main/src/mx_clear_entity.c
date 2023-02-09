#include "../inc/header.h"

void mx_clear_entity(Entity *en) {
    SDL_DestroyTexture(en->tex);
    free(en);
    en = NULL;
}

