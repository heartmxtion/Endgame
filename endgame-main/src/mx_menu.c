#include "../inc/header.h"

int mx_menu(SDL_Renderer *r, SDL_Event e, int run) {
    if (run == 0) return 0;
    int cont = 1;
    Entity *bgmenu = mx_create_box(r, 0, 0, 700, 1300, MENU_BG, UP);
    Entity *start_button = mx_create_box(r, 300, 150, 100, 400, START_BUTTON, UP);
    Entity *quit_button = mx_create_box(r, 450, 150, 100, 400, QUIT_BUTTON, UP);
    SDL_Color black = {255, 255, 255, 255}; // Если у тебя возникает вопрос почему тут black, то ты просто не шаришь, чел
    TTF_Font *Font = TTF_OpenFont("resource/fonts/OpenSans-Regular.ttf", 80);
    SDL_Surface *titleSurface = TTF_RenderText_Solid(Font, "Super Slime John", black);
    SDL_Texture *titleTexture = SDL_CreateTextureFromSurface(r, titleSurface);
    SDL_Rect titleRect = {50, 80, titleSurface->w, titleSurface->h};
    int x = 0;
    int y = 0;

    while (cont == 1) {
        SDL_GetMouseState(&x, &y);
        while(SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                cont = 0;
            }
        }

        if(e.type == SDL_MOUSEBUTTONDOWN) {
            if (x >= 150 && x <= 150 + 400) { // 400 - это x start_button-а, а 400+400 это х+ширина start_button-а | ширина и х у двух кнопок идентичная, поэтому всего одна проверка
                if (y >= 300 && y <= 300 + 100) {// 300 - это y start_button-а, а 300+100 это y+ширина start_button-а
                    break;
                }
                if (y >= 450 && y <= 450 + 100) {// 500 - это y quit_button-а, а 500+100 это y+ширина quit_button-а
                    cont = 0;
                }
            }
        }

        SDL_RenderClear(r);
        SDL_RenderCopy(r, bgmenu->tex, NULL, &bgmenu->rect);
        SDL_RenderCopy(r, titleTexture, NULL, &titleRect);
        SDL_RenderCopy(r, start_button->tex, NULL, &start_button->rect);
        SDL_RenderCopy(r, quit_button->tex, NULL, &quit_button->rect);
        SDL_RenderPresent(r);

        SDL_Delay(1000/120);
    }

    SDL_DestroyTexture(titleTexture);
    mx_clear_entity(bgmenu);
    mx_clear_entity(start_button);
    mx_clear_entity(quit_button);

    return cont;
}

