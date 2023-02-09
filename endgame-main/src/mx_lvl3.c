#include "../inc/header.h"

Entity **mx_lvl3(SDL_Renderer *r) {
    Entity **level = (Entity **)malloc(sizeof(Entity) * 296 + 1);
    int c = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            level[c++] = mx_create_box(r, 250 + 50 * j, 0 + 50 * i, 50, 50, WALL, UP);
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            level[c++] = mx_create_box(r, 250 + 50 * j, 800 + 50 * i, 50, 50, WALL, UP);
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 2; j++)
            level[c++] = mx_create_box(r, 0 + 50 * j, 0 + 50 * i, 50, 50, WALL, UP);
    }

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 2; j++)
            level[c++] = mx_create_box(r, 100 + 50 * i, 600 + 50 * j, 50, 50, WALL, UP);
    }

    level[c++] = mx_create_box(r, 200, 250, 50, 50, SPIKE, UP);
    level[c++] = mx_create_box(r, 100, 350, 50, 50, SPIKE, DOWN);
    level[c++] = mx_create_box(r, 200, 450, 50, 50, SPIKE, UP);
    level[c++] = mx_create_box(r, 250, 500, 50, 50, SPIKE, RIGHT);
    level[c++] = mx_create_box(r, 400, 550, 50, 50, SPIKE, LEFT);
    level[c++] = mx_create_box(r, 450, 600, 33, 33, SPIKE, DOWN);
    level[c++] = mx_create_box(r, 450, 633, 33, 33, SPIKE, DOWN);
    level[c++] = mx_create_box(r, 450, 666, 33, 33, SPIKE, DOWN);
    level[c++] = mx_create_box(r, 400, 700, 50, 50, SPIKE, RIGHT);
    level[c++] = mx_create_box(r, 250, 750, 50, 50, SPIKE, LEFT);
    level[c++] = mx_create_box(r, 200, 800, 50, 50, SPIKE, UP);
    level[c++] = mx_create_box(r, 100, 900, 50, 50, SPIKE, DOWN);
    level[c++] = mx_create_box(r, 200, 1000, 50, 50, SPIKE, UP);

    level[c++] = mx_create_box(r, 100, 1200, 150, 60, EXIT, UP);

    level[c++] = NULL;
    level[c++] = mx_create_box(r, 0, 0, SCREEN_HEIGHT, SCREEN_WIDTH, BACKGROUND, UP);
    level[c++] = mx_create_box(r, 200, 50, 50, 50, JOHN, UP);
    return level;   
}

