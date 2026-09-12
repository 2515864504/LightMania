#include "GameEngine.h"
#include "SDL3/SDL_log.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_surface.h"
#include "include/base.h"
#include "GameLoop.h"
#include <SDL3_ttf/SDL_ttf.h>
#include <stdio.h>

void everyDivisionTime(GameEngine*e,float bpm,int division);

void gameLoop(GameEngine* e){
    float bpm;
    int division = 4;
    printf("Input bpm:");
    scanf("%f",&bpm);
    everyDivisionTime(e,bpm,division);
    return;
}

void everyDivisionTime(GameEngine* e,float bpm,int division){
    float timeOfBeat = 60.0000f/bpm;
    float timeOfDivision = timeOfBeat/division;
    e->font = TTF_OpenFont("arail.ttf", 24.0f);
    SDL_Color fg = {255,255,255,255};
    SDL_Surface *surface = TTF_RenderText_Blended(e->font, "Test", 0, fg);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(e->ren,surface);
    SDL_DestroySurface(surface);
    SDL_FRect dst = { 100.0f,100.0f,(float)texture->w,(float)texture->h};
    SDL_RenderTexture(e->ren,texture,NULL,&dst);
//    SDL_Log("Beat per ms:%.2fms\n",timeOfBeat);
//    SDL_Log("division per ms:%.4fms",timeOfDivision);
//    SDL_Log("Amount of beat per second:%.1f",bpm/60.0f);
    return;
}
