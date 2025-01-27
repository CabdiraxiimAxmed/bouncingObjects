#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include "../functions.h"
#include <stdio.h>
#include <stdlib.h>

#define FPS 60
#define DELTA 1.0
int dx = 1;
int dy = 1;

double square(double numb) {
  return numb * numb;
}

Color getColor() {
  Color colors[10] = {
    {208, 31, 31},
    {60, 164, 209},
    {80, 209, 60},
    {255, 0, 255},
    {0, 255, 255},
    {255, 255, 255},
    {10, 10, 10},
    {128, 128, 0},
    {0, 0, 128},
    {0, 102, 204},
  };
  return colors[rand()%10 -1];
}

void createNewBouncingObject(SDL_FRect *rect, Direction *direction, int speed, SDL_FRect arenaRect, BouncingObject (*bouncingObjects)[], int *used, int size) {
  int x = rect->x;
  int y = rect->y;
  BouncingObject bouncingObject = {
    { x, y, 10, 10},
    getColor(),
    { direction->dx * -1, direction->dy* -1},
    1,
  };
  (*bouncingObjects)[*used] = bouncingObject;
  *used = *used + 1;
  printf("used: %d\n", *used);
}

void update(SDL_FRect *rect, Direction *direction, int speed, SDL_FRect arenaRect, BouncingObject (*bouncingObjects)[], int *used, int size) {
  int nx = rect -> x + direction->dx * speed * DELTA;
  int ny = rect -> y + direction->dy * speed * DELTA;
  if(*used > size)
    printf("We got an error");

  if(nx + rect->w > arenaRect.x + arenaRect.w || nx < arenaRect.x) {
    if(size > *used)
      createNewBouncingObject(rect, direction, speed, arenaRect, bouncingObjects, used, size);
    direction->dx *= -1;
  }

  if(ny + rect->h > arenaRect.y + arenaRect.h || ny < arenaRect.y) {
    if(size > *used)
      createNewBouncingObject(rect, direction, speed, arenaRect, bouncingObjects, used, size);
    direction->dy *= -1;
  }
  rect->x = nx;
  rect->y = ny;
}

bool createRect(SDL_Renderer *renderer, BouncingObject bouncingObject) {
  if(!renderer) return false;
  int limit = 0;
  SDL_SetRenderDrawColor(renderer, bouncingObject.color.r, bouncingObject.color.g, bouncingObject.color.b, 255 );
  SDL_RenderFillRect(renderer, &bouncingObject.rect);
  return true;
}
