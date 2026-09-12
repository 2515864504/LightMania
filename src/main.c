#include "GameLoop.h"
#include "include/base.h"

int main() {
  GameEngine *e = createEngine();
  if (!e) {
    SDL_Log("Error happens when Programe Init!\n");
    return -1;
  }
    programeInit(e);
 
    gameLoop(e);
     
    programeExit(e);
    return 0;
}
