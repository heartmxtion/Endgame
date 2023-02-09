#include "../inc/header.h"

Entity **mx_lvl4(SDL_Renderer *r) {
    Entity **level = (Entity **)malloc(sizeof(Entity) * 296 + 1);
    int c = 0;

    for (int i = 0; i < 26; i++) {
        level[c++] = mx_create_box(r, 0, 0 + 50 * i, 50, 50, WALL, UP);
    }

    for (int i = 0; i < 14; i++) {
        level[c++] = mx_create_box(r, 0 + 50 * i, 0, 50, 50, WALL, UP);
    }

    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 2; j++)
            level[c++] = mx_create_box(r, 0 + 50 * i, 1200 + 50 * j, 50, 50, WALL, UP);
    }
    
    for (int i = 0; i < 2; i++) {
        level[c++] = mx_create_box(r, 300, 150 + 50 * i, 50, 50, WALL, UP);
    }

    for (int i = 0; i < 2; i++) {
        level[c++] = mx_create_box(r, 450, 150 + 50 * i, 50, 50, WALL, UP);
    }

    for (int i = 0; i < 4; i++) {
        level[c++] = mx_create_box(r, 150, 150 + 50 * i, 50, 50, WALL, UP);
    }

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 2; j++)
            level[c++] = mx_create_box(r, 0 + 50 * i, 350 + 50 * j, 50, 50, WALL, UP);
    }

    for (int i = 0; i < 4; i++) {
        level[c++] = mx_create_box(r, 685, 300 + 50 * i, 50, 50, WALL, UP);
    }

    level[c++] = mx_create_box(r, 250, 450, 50, 50, WALL, UP);
    level[c++] = mx_create_box(r, 300, 450, 50, 50, SPIKE, RIGHT);
    level[c++] = mx_create_box(r, 350, 450, 50, 50, SPIKE, RIGHT);
    level[c++] = mx_create_box(r, 400, 450, 50, 50, SPIKE, RIGHT);
    level[c++] = mx_create_box(r, 450, 450, 50, 50, SPIKE, RIGHT);

    for (int i = 0; i < 4; i++) {
        level[c++] = mx_create_box(r, 685, 700 + 50 * i, 50, 50, WALL, UP);
    }
    for (int i = 0; i < 3; i++) {
        level[c++] = mx_create_box(r, 650, 1050 + 50 * i, 50, 50, WALL, UP);
    }
    for (int i = 0; i < 4; i++) {
        level[c++] = mx_create_box(r, 400, 800 + 50 * i, 50, 50, WALL, UP);
    }

    level[c++] = mx_create_box(r, 50, 550, 50, 50, WALL, UP);

    level[c++] = mx_create_box(r, 50, 600, 50, 50, WALL, UP);
    
    for (int i = 0; i < 3; i++) {
        level[c++] = mx_create_box(r, 50 + 50 * i, 650, 50, 50, WALL, UP);
    }

    for (int i = 0; i < 3; i++) {
        level[c++] = mx_create_box(r, 250 + 50 * i, 600, 50, 50, WALL, UP);
    }

    for (int i = 0; i < 4; i++) {
        level[c++] = mx_create_box(r, 500, 450 + 50 * i, 50, 50, WALL, UP);
    }

    level[c++] = mx_create_box(r, 150, 100, 50, 50, SPIKE, LEFT);
    level[c++] = mx_create_box(r, 300, 100, 50, 50, SPIKE, LEFT);
    level[c++] = mx_create_box(r, 300, 50, 50, 50, SPIKE, RIGHT);
    level[c++] = mx_create_box(r, 300, 250, 50, 50, SPIKE, RIGHT);

    level[c++] = mx_create_box(r, 450, 100, 50, 50, SPIKE, LEFT);
    level[c++] = mx_create_box(r, 450, 250, 50, 50, SPIKE, RIGHT);
    level[c++] = mx_create_box(r, 450, 300, 50, 50, SPIKE, LEFT);

    level[c++] = mx_create_box(r, 350, 950, 50, 50, SPIKE, UP);
    level[c++] = mx_create_box(r, 400, 1000, 50, 50, SPIKE, RIGHT);
    level[c++] = mx_create_box(r, 350, 800, 50, 50, SPIKE, UP);
    level[c++] = mx_create_box(r, 400, 750, 50, 50, SPIKE, LEFT);

    level[c++] = mx_create_box(r, 520, 1185, 15, 15, SPIKE, LEFT);
    level[c++] = mx_create_box(r, 370, 1185, 15, 15, SPIKE, LEFT);
    level[c++] = mx_create_box(r, 220, 1185, 15, 15, SPIKE, LEFT);

    level[c++] = mx_create_box(r, 252, 650, 50, 50, SPIKE, RIGHT);
    level[c++] = mx_create_box(r, 300, 650, 50, 50, SPIKE, RIGHT);

    level[c++] = mx_create_box(r, 100, 550, 25, 25, SPIKE, DOWN);

    level[c++] = mx_create_box(r, 600, 1050, 50, 50, CHECKPOINT, UP);

    level[c++] = mx_create_box(r, 100, 425, 150, 60, EXIT, DOWN);

    level[c++] = NULL;
    level[c++] = mx_create_box(r, 0, 0, SCREEN_HEIGHT, SCREEN_WIDTH, BACKGROUND, UP);
    level[c++] = mx_create_box(r, 100, 300, 50, 50, JOHN, UP);
    return level;
}

