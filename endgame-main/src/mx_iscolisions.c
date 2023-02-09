#include "../inc/header.h"

int mx_iscolisions(int x, int y, int w, int h, Entity **list) {
    for (int i = 0; list[i] != NULL; i++) {
        if (list[i]->index == 3) {
            if (collision_spike(x, y, w, h, list[i]))
                return i;
        }
        else if (collision(x, y, w, h, list[i]) && list[i]->index != 8) {
            return i;
        }
    }
    return -1;
}

