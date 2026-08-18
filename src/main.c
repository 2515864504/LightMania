#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>

int main(){
    if(!SDL_Init(SDL_INIT_VIDEO)){
        SDL_Log("err:%s\n",SDL_GetError());
        return -1;
    }
    SDL_Window* win = SDL_CreateWindow("Hello",800,600,0);
    if(!win){
        SDL_Log("err:%s\n",SDL_GetError());
        return -1;
    }
    SDL_Renderer* ren = SDL_CreateRenderer(win, NULL);
    SDL_SetRenderDrawColor(ren, 100, 100, 100, 100);
    SDL_RenderPresent(ren);
    SDL_Delay(10000);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}