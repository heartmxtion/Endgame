#include "../inc/header.h"

void mx_del_lvl(Entity **list) {
    int i = 0;
    for (; list[i] != NULL; i++) {
        SDL_DestroyTexture(list[i]->tex);
        free(list[i]);
        list[i] = NULL;
    }
    free(list[i + 1]);
    SDL_DestroyTexture(list[i + 1]->tex);
    free(list[i + 2]);
    SDL_DestroyTexture(list[i + 2]->tex);
    free(list);
    list = NULL;
}

