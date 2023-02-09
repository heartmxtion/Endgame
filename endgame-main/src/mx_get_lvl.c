#include "../inc/header.h"

Entity **mx_get_level(SDL_Renderer *r, int level) {
    switch (level)
    {
    case -1:
        return mx_secret(r);
        break;
    case 1:
        return mx_lvl1(r);
        break;
    case 2:
        return mx_lvl2(r);
        break;
    case 3:
        return mx_lvl3(r);
        break;
    case 4:
        return mx_lvl4(r);
        break;
    case 5:
        return mx_lvl5(r);
        break;
    default:
        return NULL;
        break;
    }
    return NULL;
}

