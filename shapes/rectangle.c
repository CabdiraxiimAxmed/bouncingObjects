#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <math.h>
#include "../functions.h"

#define FPS 60
#define RECT_WIDTH 10
#define RECT_HEIGHT 10
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

double checkIfInsideCircle(struct Vector pos, struct Vector circlePos ) {
  double distX = square((pos.x - circlePos.x));
  double distY = square((pos.y - circlePos.y));
  double dist = distX + distY;
  double distance = sqrt(dist);
  if(distance > 200 ) {
    return false;
  }
  return true;
}

void update(struct Vector *pos, struct Vector circlePos ) {
  if(!checkIfInsideCircle(*pos, circlePos)) {
    /*double distX = square((pos -> x - circlePos.x));*/
    /*double distY = square((pos -> y - circlePos.y));*/
    /*double theta = SDL_atan2(distY, distX);*/
    /*pos -> x = 200 + cos(theta);*/
    /*pos -> y = 200 + sin(theta);*/
    dx *= -1;
    /*dy *= -1;*/
  }
  int nx = pos -> x + dx * SPEED * DELTA;
  /*int ny = pos -> y + dy * SPEED * DELTA;*/
  pos -> x = nx;
  /*pos -> y = ny;*/
}

bool createRect(SDL_Renderer *renderer, struct Vector *pos, int color) {
  if(!renderer) return false;
  int limit = 0;
  setColor(renderer, color);
  SDL_FRect rect = {pos -> x - RECT_WIDTH, pos -> y - RECT_HEIGHT, RECT_WIDTH, RECT_HEIGHT};
  SDL_RenderFillRect(renderer, &rect);
  return true;
}
