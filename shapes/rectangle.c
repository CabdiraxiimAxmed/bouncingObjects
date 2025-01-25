#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include "../functions.h"
#include <stdio.h>

#define FPS 60
#define SPEED 1.0
#define DELTA 1.0
int dx = 1;
int dy = 1;

void setColor(SDL_Renderer *renderer, int color) {
  int r = ((color >> (0 * 8)) & 0xFF);  // Extract the RR byte
  int g = ((color >> (1 * 8)) & 0xFF);   // Extract the GG byte
  int b = ((color >> (2 * 8)) & 0xFF);   // Extract the GG byte
  int a = ((color >> (3 * 8)) & 0xFF);   // Extract the GG byte
  SDL_SetRenderDrawColor(renderer, r, g, b, 255 );
}

double square(double numb) {
  return numb * numb;
}


void update(SDL_FRect *rect, SDL_FRect arenaRect) {
  int nx = rect -> x + dx * SPEED * DELTA;
  int ny = rect -> y + dy * SPEED * DELTA;
  if(nx + rect->w > arenaRect.x + arenaRect.w || nx < arenaRect.x) {
    dx *= -1;
  }
  if(ny + rect->h > arenaRect.y + arenaRect.h || ny < arenaRect.y) {
    dy *= -1;
  }

  rect->x = nx;
  rect->y = ny;
}

bool createRect(SDL_Renderer *renderer, BouncingObject bouncingObject) {
  if(!renderer) return false;
  int limit = 0;
  setColor(renderer, bouncingObject.color);
  SDL_RenderFillRect(renderer, &bouncingObject.rect);
  return true;
}
