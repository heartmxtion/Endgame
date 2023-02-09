#include "../inc/header.h"

/*Эта игра как кампус: Всё сложно, но реально!!
Пройдя эту игру вы почуствуете ту же боль, что ощущаем мы под конец марафона.
Главный герой символизирует участников марафона, которые как и вы при каждой ошибке задумываются, 
а ради чего всё это? Может стоит бросить кампус и пойти в ресёрч? Или лучше продавать говно?*/

int main (int argc, char *argv[]) {
    if (argv[0]) {};
    if (argc != 1) {
        write(2, "usage: ./endgame\n", 18);
        return -1;
    }
    if (SDL_Init(SDL_INIT_VIDEO) != 0) { //Инициализируй музыку если всё будет плохо
        system("pause");
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("Super Slime John", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (win == NULL) {
        system("pause");
        return 1;
    }
    
    TTF_Init();
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
    Mix_Music *backgroundSound = Mix_LoadMUS("resource/audio/bg_music.mp3");
    Mix_Chunk *jump = Mix_LoadWAV("resource/audio/slime_jump.wav");
    Mix_VolumeMusic(MIX_MAX_VOLUME/50);
    Mix_VolumeChunk(jump ,MIX_MAX_VOLUME/10);

    SDL_Event e;
    SDL_PollEvent(&e);
    const Uint8 *keystate = SDL_GetKeyboardState(NULL);
    int run = mx_intro(rend, e);
    run = mx_menu(rend, e, run);
    int lvl = 1;
    int deathsCount = 0;
    Mix_PlayMusic(backgroundSound, -1);
    
    bool firstTime = true;

    SDL_Color black = {255, 255, 255, 255}; // BLM
    TTF_Font *Font = TTF_OpenFont("resource/fonts/OpenSans-Regular.ttf", 26);
    SDL_Surface *msg = TTF_RenderText_Solid(Font, "Deaths:", black);
    SDL_Texture *msgTexture = SDL_CreateTextureFromSurface(rend, msg);
    SDL_Rect msgRect = {15, 7, msg->w, msg->h};
    SDL_Rect bkForText = {10, 7, msg->w + 80, msg->h + 3};

    SDL_Surface *pauseMsg = TTF_RenderText_Solid(Font, "Press q to pause", black);
    SDL_Texture *pauseMsgTexture = SDL_CreateTextureFromSurface(rend, pauseMsg);
    SDL_Rect pauseMsgRect = {1080, 7, pauseMsg->w, pauseMsg->h};
    SDL_Rect bkForPause = {1075, 7, pauseMsg->w + 10, pauseMsg->h + 3};

    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);

    while (run != 0) {
        Entity **Wlist = mx_get_level(rend, lvl);

        if (Wlist == NULL) {
            run = mx_outro(rend);
            lvl = 1;
            deathsCount = 0;
            Wlist = mx_get_level(rend, lvl);
            Mix_HaltMusic();
            if (run != 0){
                run = mx_menu(rend, e, run);
                Mix_PlayMusic(backgroundSound, 0);
            }          
        }
        if (run == 0) break;
        int len = 0;
        while(Wlist[len] != NULL) len++; 
        Entity *bk = Wlist[len + 1];
        Entity *john = Wlist[len + 2];

        bool on_ground = false;
        run = 1;

        int start_x = Wlist[len + 2]->rect.x;
        int start_y = Wlist[len + 2]->rect.y;

        int x = start_x;
        int y = start_y;
        int d_y = 0;
        clock_t clstart = 0;

        if (bk->index == 9) {
            clstart = clock();
        }

        while (run == 1) {
            while(SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    run = 0;
                }
            }

            if( ( keystate[ SDL_SCANCODE_UP ] || keystate[ SDL_SCANCODE_SPACE ] ) && on_ground && y > 0) {
            	if (firstTime) {
            	    Mix_PlayChannel(-1, jump, 0);
            	    firstTime = false;
            	}
                d_y = 100;
                on_ground = false;
            }
            else if( (keystate[ SDL_SCANCODE_LEFT ] || keystate[ SDL_SCANCODE_A ]) && x > 0) {
                if (on_ground) x += -4;
                else x += -2;
            }
            else if( ( keystate[ SDL_SCANCODE_RIGHT ] || keystate[ SDL_SCANCODE_D ] ) && x + john->rect.w < SCREEN_WIDTH) {
                if (on_ground) x += 4;
                else x += 2;
            }

            if(  keystate[ SDL_SCANCODE_Q ] ) {
                Mix_HaltMusic();           
                run = mx_menu(rend, e, run);
                Mix_PlayMusic(backgroundSound, 0);
            }

            //gravity
            if (d_y == 0 && !on_ground) { 
            	y += 2;
            	firstTime = true;
            }
            if (d_y != 0) {
                y -= 2;
                d_y -= 2;
            }

            int c = mx_iscolisions(x, y, john->rect.w, john->rect.h, Wlist); 
            if (c >= 0) {
                if (Wlist[c]->index == SPIKE) {
                    x = start_x;
                    y = start_y;
                    deathsCount++;
                }
                else if (Wlist[c]->index == ISPIKE) {
                    x = start_x;
                    y = start_y;
                    deathsCount++;
                }
                else if (Wlist[c]->index == CHECKPOINT) {
                    start_x = Wlist[c]->rect.x + Wlist[c]->rect.w / 2 - john->rect.w / 2;
                    start_y = Wlist[c]->rect.y + Wlist[c]->rect.h / 2 - john->rect.h / 2; 
                    Wlist[c]->index = -1;
                }
                else if (Wlist[c]->index == EXIT) {
                    run = 2;
                    lvl++;
                    break;
                }
                else if (Wlist[c]->index == SECRET) {
                    run = 2;
                    lvl = -1;
                    break;
                }
                else if (Wlist[c]->index == SECRET_EXIT) {
                    run = 2;
                    lvl = 5;
                    break;
                }
                else {
                    x = john->rect.x;
                    y = john->rect.y;
                    on_ground = true;
                    d_y = 0;
                }
            }
            else on_ground = false;

            if (john->rect.y + john->rect.h == SCREEN_HEIGHT) {
                x = start_x;
                y = start_y;
                deathsCount++;
            }

            john->rect.x = x;
            john->rect.y = y;

            if (bk->index == 9) {
                time_t clend = clock();
                if (clend - clstart > 2500000) {
                    run = 0;
                    break;  
                }
            }
            
            SDL_RenderClear(rend);
            SDL_RenderCopy(rend, bk->tex, NULL, &bk->rect);
            mx_draw_list(rend, Wlist);
            SDL_RenderCopy(rend, john->tex, NULL, &john->rect);
            SDL_RenderFillRect(rend, &bkForText);
            mx_drawDeaths(rend, deathsCount, Font, black);
            SDL_RenderCopy(rend, msgTexture, NULL, &msgRect);
            SDL_RenderFillRect(rend, &bkForPause);
            SDL_RenderCopy(rend, pauseMsgTexture, NULL, &pauseMsgRect);
            SDL_RenderPresent(rend);
            SDL_Delay(1000/120);
        }
        mx_del_lvl(Wlist);
    }

    SDL_DestroyTexture(msgTexture);
    SDL_DestroyTexture(pauseMsgTexture);
    Mix_FreeChunk(jump);
    Mix_FreeMusic(backgroundSound);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    Mix_CloseAudio();
    atexit(TTF_Quit);
    SDL_Quit();

    return 0;
}

