#include "../inc/header.h"

SDL_Surface *mx_get_texture(int index) {
    char *arr[14] = {"resource/textures/john.png", "resource/textures/grey_brick.png", "resource/textures/spike.png", 
                    "resource/textures/checkpoint_active.png", "resource/textures/portal.png", "resource/textures/bk1.png", 
                    "resource/textures/intro_bg.png", "resource/textures/checkpoint_disactivated.png", "resource/textures/end.png",
                    "resource/textures/zak.png", "resource/textures/Innovation_campus.png", "resource/textures/Start_adventure.png", 
                    "resource/textures/Exit.png", "resource/textures/outro.png"};
    return IMG_Load(arr[index - 1]);
}

