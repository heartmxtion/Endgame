#include "../inc/header.h"

Entity **mx_lvl5(SDL_Renderer *r) {
    Entity **level = (Entity **)malloc(sizeof(Entity) * 60 + 1);
    int c = 0;

    for (int i = 0; i < 26; i++)
        level[c++] = mx_create_box(r, 0, 0 + 50 * i, 50, 50, WALL, UP);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 2; j++)
            level[c++] = mx_create_box(r, 200 + 50 * i, 0 + 50 * j, 50, 50, WALL, UP);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 2; j++)
            level[c++] = mx_create_box(r, 200 + 50 * i, 1200 + 50 * j, 50, 50, WALL, UP);
    for (int i = 0; i < 7; i++)
        level[c++] = mx_create_box(r, 50 + 50 * i, 200, 50, 50, WALL, UP);
    level[c++] = mx_create_box(r, 203, 100, 50, 50, SPIKE, RIGHT);
    level[c++] = mx_create_box(r, 350, 150, 50, 50, SPIKE, LEFT);
    level[c++] = mx_create_box(r, 400, 200, 50, 50, SPIKE, DOWN);
    level[c++] = mx_create_box(r, 552, 200, 50, 50, SPIKE, LEFT);
    level[c++] = mx_create_box(r, 550, 250, 50, 50, WALL, UP);
    for (int i = 0; i < 5; i++)
        level[c++] = mx_create_box(r, 50, 250 + 50 * i, 50, 50, SPIKE, DOWN);
    for (int i = 0; i < 10; i++)
        level[c++] = mx_create_box(r, 200 + 50 * i, 300, 50, 50, WALL, UP);
    for (int i = 0; i < 7; i++)
        level[c++] = mx_create_box(r, 50 + 50 * i, 500, 50, 50, WALL, UP);
    level[c++] = mx_create_box(r, 400, 500, 50, 50, SPIKE, DOWN);
    for (int i = 0; i < 3; i++)
        level[c++] = mx_create_box(r, 550 + 50 * i, 350, 50, 50, WALL, UP);
    for (int i = 0; i < 2; i++)
        level[c++] = mx_create_box(r, 600 + 50 * i, 500, 50, 50, WALL, UP);
    level[c++] = mx_create_box(r, 550, 500, 50, 50, SPIKE, UP);
    for (int i = 0; i < 3; i++)
        level[c++] = mx_create_box(r, 600, 550 + 50 * i, 50, 50, WALL, UP);
    level[c++] = mx_create_box(r, 303, 345, 45, 50, SPIKE, RIGHT);
    level[c++] = mx_create_box(r, 303, 455, 45, 50, SPIKE, LEFT);
    level[c++] = mx_create_box(r, 500, 350, 50, 50, CHECKPOINT, UP);
    for (int i = 0; i < 10; i++)
        level[c++] = mx_create_box(r, 150 + 50 * i, 700, 50, 50, WALL, UP);
    level[c++] = mx_create_box(r, 550, 650, 50, 50, SPIKE, UP);
    level[c++] = mx_create_box(r, 350, 650, 50, 50, SPIKE, LEFT);
    level[c++] = mx_create_box(r, 250, 550, 50, 50, SPIKE, RIGHT);
    level[c++] = mx_create_box(r, 153, 650, 50, 50, SPIKE, LEFT);
    for (int i = 0; i < 3; i++)
        level[c++] = mx_create_box(r, 150, 750 + 50 * i, 50, 50, WALL, UP);
    level[c++] = mx_create_box(r, 100, 750, 50, 50, CHECKPOINT, UP);
    for (int i = 0; i < 6; i++)
        level[c++] = mx_create_box(r, 50 + 50 * i, 950, 50, 50, WALL, UP);
    for (int i = 0; i < 4; i++)
        level[c++] = mx_create_box(r, 350, 850 + 50 * i, 50, 50, WALL, UP);
    level[c++] = mx_create_box(r, 300, 900, 50, 50, SPIKE, UP);
    level[c++] = mx_create_box(r, 353, 800, 50, 50, SPIKE, LEFT);
    for (int i = 0; i < 4; i++)
        level[c++] = mx_create_box(r, 400 + 50 * i, 850, 50, 50, WALL, UP);
    for (int i = 0; i < 4; i++)
        level[c++] = mx_create_box(r, 650, 800 + 50 * i, 50, 50, WALL, UP);
    level[c++] = mx_create_box(r, 500, 750, 50, 50, SPIKE, RIGHT);
    for (int i = 0; i < 2; i++)
        level[c++] = mx_create_box(r, 500, 1000 + 50 * i, 50, 50, WALL, UP);
    level[c++] = mx_create_box(r, 503, 950, 50, 50, SPIKE, LEFT);
    level[c++] = mx_create_box(r, 503, 1100, 50, 50, SPIKE, RIGHT);
    level[c++] = mx_create_box(r, 353, 1050, 50, 50, SPIKE, RIGHT);
    level[c++] = mx_create_box(r, 203, 1150, 50, 50, SPIKE, LEFT);
    for (int i = 0; i < 3; i++)
        level[c++] = mx_create_box(r, 550 + 50 * i, 1000, 50, 50, WALL, UP);
    level[c++] = mx_create_box(r, 50, 1230, 150, 60, EXIT, UP);
    level[c++] = mx_create_box(r, 690, 750, 50, 50, SECRET, UP);
    level[c++] = NULL;
    level[c++] = mx_create_box(r, 0, 0, SCREEN_HEIGHT, SCREEN_WIDTH, BACKGROUND, UP);
    level[c++] = mx_create_box(r, 150, 0, 50, 50, JOHN, UP);
    return level;
}

