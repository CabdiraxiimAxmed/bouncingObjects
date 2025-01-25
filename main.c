#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_scancode.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>
#include <stdio.h>
#include "functions.h"

#define FPS 60
#define BALL_COLOR 0xFF30FF30
#define CIRCLE_COLOR 0xFF3030FF

void arena(SDL_Renderer *renderer, SDL_FRect *rect) {
  setColor(renderer, CIRCLE_COLOR);
  SDL_RenderRect(renderer, rect);
}

int main() {
  SDL_Event event;
  SDL_Window *window = NULL;
  SDL_Surface *windSurface = NULL;
  bool quit = false;

  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("ping-ball", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);

  if(!window) {
    const char *error = SDL_GetError();
    printf("Error on creating window: %s\n",error);
    return 1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
  if(!renderer) {
    printf("Error on creating renderer: %s", SDL_GetError());
  }

  struct Vector circlePos = {(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2};
  BouncingObject bouncingObject = {
    { (float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2, 10, 10},
    0xFF30FF30,
  };

  while(!quit) {
    SDL_PumpEvents();
    while(SDL_PollEvent(&event)) {
      if(event.key.scancode == 20) {
        quit = true;
      }
    }
    setColor(renderer, 0xFFFFFFFF );
    SDL_RenderClear(renderer);

    SDL_FRect arenaRect = { (float)(SCREEN_WIDTH - ARENA_WIDTH) / 2, (float) (SCREEN_HEIGHT - ARENA_HEIGHT) / 2, ARENA_WIDTH, ARENA_HEIGHT};
    arena(renderer, &arenaRect);
    /*renderCircle(renderer, circlePos, 200, 0xFF3030FF);*/
    update(&bouncingObject.rect, arenaRect);
    createRect(renderer, bouncingObject);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000/FPS);
  }

  SDL_Quit();
  return 0;
}
