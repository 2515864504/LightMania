#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <malloc.h>

struct GameEngine {
  SDL_Window *win;
  SDL_Renderer *ren;
};
typedef struct GameEngine GameEngine;

void programInit(GameEngine *e) {
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

GameEngine *createEngine() { return (GameEngine *)malloc(sizeof(GameEngine)); }

void ProgramExit(GameEngine* e){
    SDL_DestroyRenderer(e->ren);
    SDL_DestroyWindow(e->win);
    SDL_Quit();
}

int main() {
  GameEngine *e = createEngine();
  if (!e) {
    SDL_Log("Err happens when Programe Init!\n");
    return -1;
  }
    programInit(e);
  
    SDL_Delay(10000);
  
    ProgramExit(e);
    return 0;
}
