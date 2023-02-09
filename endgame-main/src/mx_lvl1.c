#include "../inc/header.h"

Entity **mx_lvl1(SDL_Renderer *r) {
    Entity **level = (Entity **)malloc(sizeof(Entity) * 142 + 1);
    int c = 0;
    for (int i = 0; i < 9; i++) {
        level[c++] = mx_create_box(r, 0 + 50 * i, 0, 50, 50, WALL, UP);
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            level[c++] = mx_create_box(r, 600 + 50 * j, 0 + 50 * i, 50, 50, WALL, UP);
        }
    }

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 3; j++) {
            level[c++] = mx_create_box(r, 550 + 50 * j, 200 + 50 * i, 50, 50, WALL, UP);
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            level[c++] = mx_create_box(r, 400 + 50 * j, 1000 + 50 * i, 50, 50, WALL, UP);
        }
    }
    
    for (int i = 0; i < 25; i++) {
        level[c++] = mx_create_box(r, 0, 50 + 50 * i, 50, 50, WALL, UP);
    }

    for (int i = 0; i < 7; i++) {
        level[c++] = mx_create_box(r, 50 + 50 * i, 1250, 50, 50, WALL, UP);
    }

    for (int i = 0; i < 5; i++) {
        level[c++] = mx_create_box(r, 350, 600 + 50 * i, 50, 50, WALL, UP);
    }
    
    level[c++] = mx_create_box(r, 500, 950, 50, 50, SPIKE, UP);
    level[c++] = mx_create_box(r, 200, 600, 150, 60, EXIT, DOWN);
    level[c++] = NULL;
    level[c++] = mx_create_box(r, 0, 0, SCREEN_HEIGHT, SCREEN_WIDTH, BACKGROUND, UP);
    level[c++] = mx_create_box(r, 550, 50, 50, 50, JOHN, UP);
    return level;   
}

