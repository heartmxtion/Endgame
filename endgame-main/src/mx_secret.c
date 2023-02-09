#include "../inc/header.h"

Entity **mx_secret(SDL_Renderer *r) {
    Entity **level = (Entity **)malloc(sizeof(Entity) * 296 + 1);
    int c = 0;

    level[c++] = mx_create_box(r, 568, 45, 58, 56, IWALL, UP);
    level[c++] = mx_create_box(r, 590, 124, 58, 170, IWALL, UP);
    level[c++] = mx_create_box(r, 525, 305, 68, 35, IWALL, UP);
    level[c++] = mx_create_box(r, 545, 340, 68, 39, IWALL, UP);
    level[c++] = mx_create_box(r, 473, 392, 68, 300, IWALL, UP);
    level[c++] = mx_create_box(r, 410, 660, 68, 190, IWALL, UP);
    level[c++] = mx_create_box(r, 390, 720, 20, 20, ISPIKE, UP);
    level[c++] = mx_create_box(r, 390, 730, 20, 20, ISPIKE, UP);
    level[c++] = mx_create_box(r, 255, 840, 150, 50, SECRET_EXIT, UP);
    level[c++] = NULL;
    level[c++] = mx_create_box(r, 0, 0, 700, 1300, SC_BG, UP);
    level[c++] = mx_create_box(r, 515, 45, 50, 50, JACQUE, UP);
    return level;
}

