#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "base.h"

struct GameEngine {
  SDL_Window *win;
  SDL_Renderer *ren;
};
typedef struct GameEngine GameEngine;

void programeInit(GameEngine *e);

void programeExit(GameEngine *e);

GameEngine* createEngine();

#endif
