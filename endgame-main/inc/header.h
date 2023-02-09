#pragma once

#include <stdbool.h>
#include <string.h> // стринги
#include <locale.h> // локале
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>
#include <unistd.h>

#define SCREEN_WIDTH 1300
#define SCREEN_HEIGHT 700

typedef struct t_john {
    SDL_Rect rect;
    SDL_Texture *tex;
    int index;
    int facing;
    void *ext;
}              Entity;

enum obj {
    JOHN = 1,
    WALL = 2,
    SPIKE = 3,
    CHECKPOINT = 4,
    EXIT = 5,
    BACKGROUND = 6,
    BG_INTRO = 7,
    CHECKPOINT_NOT_ACTIVE = 8,
    SC_BG = 9,
    JACQUE = 10,
    MENU_BG = 11,
    START_BUTTON = 12,
    QUIT_BUTTON = 13,
    SECRET_EXIT = 17,
    IWALL = 18,
    ISPIKE = 19,
    SECRET = 22 // не спрашивайте почему
};

enum rotation {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

int mx_intro(SDL_Renderer *rend, SDL_Event event);
int mx_iscolisions(int x, int y, int w, int h, Entity **list);
int mx_menu(SDL_Renderer *r, SDL_Event e, int run);
int mx_outro(SDL_Renderer *r);
void mx_drawDeaths(SDL_Renderer *rend, int count, TTF_Font *Font, SDL_Color black);
void mx_draw_list(SDL_Renderer *r, Entity **list);
void mx_del_lvl(Entity **list);
void mx_clear_entity(Entity *en);
Entity **mx_lvl1(SDL_Renderer *r);
Entity **mx_lvl2(SDL_Renderer *r);
Entity **mx_lvl3(SDL_Renderer *r);
Entity **mx_lvl4(SDL_Renderer *r);
Entity **mx_lvl5(SDL_Renderer *r);
Entity **mx_secret(SDL_Renderer *r);
Entity **mx_get_level(SDL_Renderer *r, int level);
Entity *mx_create_box(SDL_Renderer *r, int y, int x, int h, int w, int index, int faceing);
bool collision_spike (int x, int y, int w, int h, Entity *b);
bool collision (int x, int y, int w, int h, Entity *b);
SDL_Surface *mx_get_texture(int index);
char *mx_itoa(int number);

