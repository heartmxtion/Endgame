#include "../inc/header.h"

void mx_draw_list(SDL_Renderer *r, Entity **list) {
    for (int i = 0; list[i] != NULL; i++) {
        if(list[i]->index < 0) {
            list[i] = mx_create_box(r, list[i]->rect.y, list[i]->rect.x, list[i]->rect.h, list[i]->rect.w, 8, 0);
        }
        SDL_RenderCopyEx(r, list[i]->tex, NULL, &list[i]->rect, list[i]->facing * 90, NULL, SDL_FLIP_NONE);
    }
}

