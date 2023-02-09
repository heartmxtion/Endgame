#include "../inc/header.h"

bool collision_spike (int x, int y, int w, int h, Entity *b) {
    int bottomB;
    int middle;

    //Calculate the sides of rect A
    int leftA = x;
    int rightA = x + w;
    int topA = y;
    int bottomA = y + h;

    //Calculate the sides of rect B
    if (b->facing == UP) {
        middle = b->rect.x + b->rect.w / 2;
        bottomB = b->rect.y + b->rect.h - 2;
    } else if (b->facing == RIGHT) {
        middle = b->rect.x + 1;
        bottomB = b->rect.y + b->rect.h / 2;
    } else if (b->facing == DOWN) {
        middle = b->rect.x + b->rect.w / 2;
        bottomB = b->rect.y + 1;
    } else { // LEFT
        middle = b->rect.x + b->rect.w - 1;
        bottomB = b->rect.y + b->rect.h / 2;
    }

    int leftB = b->rect.x;
    int rightB = b->rect.x + b->rect.w;
    int topB = b->rect.y;

    if (bottomA > topB && x < middle && middle < x + w && topA < b->rect.y + b->rect.h)
        return true;

    if (bottomA < topB && x < middle && middle < x + w && topA > b->rect.y + b->rect.h)
        return true;

    if (((leftA > leftB && leftA < rightB) 
        || (rightA > leftB && rightA < rightB))
        && bottomA > bottomB && topA < bottomB)
        return true;

    return false;
}

bool collision (int x, int y, int w, int h, Entity *b) {
    //Calculate the sides of rect A
    int leftA = x;
    int rightA = x + w;
    int topA = y;
    int bottomA = y + h;

    //Calculate the sides of rect B
    int leftB = b->rect.x;
    int rightB = b->rect.x + b->rect.w;
    int topB = b->rect.y;
    int bottomB = b->rect.y + b->rect.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB ) return false;
    if( topA >= bottomB ) return false;
    if( rightA <= leftB ) return false;
    if( leftA >= rightB ) return false;
    return true;
}

