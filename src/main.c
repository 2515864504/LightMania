#include "include/base.h"
#include "include/GameEngine.h"

int main() {
  GameEngine *e = createEngine();
  if (!e) {
    SDL_Log("Error happens when Programe Init!\n");
    return -1;
  }
    programeInit(e);
  
  
    programeExit(e);
    return 0;
}
