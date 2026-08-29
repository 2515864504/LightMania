#include "include/base.h"
#include "include/GameEngine.h"

GameEngine *createEngine() { 
    return (GameEngine *)malloc(sizeof(GameEngine)); 
}

void programeInit(GameEngine *e) {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("err:%s\n", SDL_GetError());
    return;
  }
  e->win = SDL_CreateWindow("Hello", 800, 600,0);
  if (!e->win) {
    SDL_Log("err:%s\n", SDL_GetError());
    return;
  }
  e->ren = SDL_CreateRenderer(e->win, NULL);

  if (!e->ren) {
    SDL_Log("err:%s\n", SDL_GetError());
    return;
  }
}

void programeExit(GameEngine* e){
    SDL_DestroyRenderer(e->ren);
    SDL_DestroyWindow(e->win);
    SDL_Quit();
}


