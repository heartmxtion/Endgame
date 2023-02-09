#include "../inc/header.h"

Entity *mx_create_box(SDL_Renderer *r, int y, int x, int h, int w, int index, int faceing) {
    Entity *temp = (Entity *)malloc(sizeof(Entity));
    temp->tex = SDL_CreateTextureFromSurface(r, mx_get_texture(index));
    SDL_QueryTexture(temp->tex, NULL, NULL, &temp->rect.w, &temp->rect.h);
    temp->rect.y = y;
    temp->rect.x = x;
    temp->rect.h = h;
    temp->rect.w = w;
    temp->index = index;
    temp->facing = faceing;
    return temp;
}

