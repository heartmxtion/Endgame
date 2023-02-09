#include "../inc/header.h"

Entity **mx_lvl2(SDL_Renderer *r) {
    Entity **level = (Entity **)malloc(sizeof(Entity) * 296 + 1);
    int c = 0;

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 5; j++) {
            level[c++] = mx_create_box(r, 0 + 50 * j, 0 + 50 * i, 50, 50, WALL, UP);
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 6; j++) {
            level[c++] = mx_create_box(r, 400 + 50 * j, 0 + 50 * i, 50, 50, WALL, UP);
        }
    }

    level[c++] = mx_create_box(r, 350, 250, 50, 50, SPIKE, UP);
    level[c++] = mx_create_box(r, 350, 500, 50, 50, SPIKE, UP);
    level[c++] = mx_create_box(r, 350, 750, 50, 50, SPIKE, UP);
    level[c++] = mx_create_box(r, 350, 1000, 50, 50, SPIKE, UP);
    level[c++] = mx_create_box(r, 250, 375, 50, 50, SPIKE, DOWN);
    level[c++] = mx_create_box(r, 250, 625, 50, 50, SPIKE, DOWN);
    level[c++] = mx_create_box(r, 250, 875, 50, 50, SPIKE, DOWN);
    level[c++] = mx_create_box(r, 250, 1200, 150, 60, EXIT, UP);

    level[c++] = NULL;
    level[c++] = mx_create_box(r, 0, 0, SCREEN_HEIGHT, SCREEN_WIDTH, BACKGROUND, UP);
    level[c++] = mx_create_box(r, 350, 50, 50, 50, JOHN, UP);
    return level;   
}

