#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include "../functions.h"

/* https://www.gatevidyalay.com/mid-point-circle-drawing-algorithm/
This formula finds the boundary condition
p is the pixel (x,y)
NOTE: F(p) = x2 + y2 – r2 
if f(p) < 0 the point is inside the circle.
if f(p) > 0 the point is out the perimeter 
if f(p) = 0 the point is on the circle 

https://medium.com/@dillihangrae/mid-point-circle-algorithm-84f5971dcd08
This is the equation of a circle at the center.
(x — a) ^2 + (y — b) ^2 = r²
Use this formula if the circle is at the center (0, 0).
x² + y ^2 = r²

A circle consists of eight octants.

These are the steps to follow.

get the initial point (x, y).
(x, r) replace the y axis to the given radius.
Get the initial decision parameter which p = 1 - r;

Now we are going to step 2
if p < 0
  (Xk, Yk) = (X +1, Y).
  Pk = p + 2X + 3.
else if p < 0
  (Xk, Yk) = (X + 1, Y - 1)
  Pk = P + 2(X - Y) + 5

*/

bool drawPoint(SDL_Renderer *renderer, int x, int y, int color) {
  SDL_SetRenderDrawColor(renderer, 45, 57, 84, 255 );
  bool renderPoint = SDL_RenderPoint(renderer, x, y);
  return true;
}

bool renderCircle(SDL_Renderer *renderer, struct Vector pos, int radius, int color) {
  struct Vector initPoints = {pos.x, pos.y};
  pos.x = 0;
  pos.y = radius;
  int P = 1 - radius;
  while(pos.x <= pos.y) {
    if(P < 0) {
      pos.x = pos.x + 1;
      P = P + 2 * pos.x + 1;
    } else if (P >= 0) {
      pos.x = pos.x + 1;
      pos.y = pos.y - 1;
      P = P + 2 * (pos.x -pos.y) + 1;
    }
    drawPoint(renderer, initPoints.x + pos.x, initPoints.y + pos.y, color);
    drawPoint(renderer, initPoints.x + pos.x, initPoints.y - pos.y, color);
    drawPoint(renderer, initPoints.x + pos.y, initPoints.y - pos.x, color);
    drawPoint(renderer, initPoints.x - pos.y, initPoints.y - pos.x, color);
    drawPoint(renderer, initPoints.x - pos.x, initPoints.y - pos.y, color);
    drawPoint(renderer, initPoints.x - pos.x, initPoints.y + pos.y, color);
    drawPoint(renderer, initPoints.x - pos.y, initPoints.y + pos.x, color);
    drawPoint(renderer, initPoints.x + pos.y, initPoints.y + pos.x, color);
  }
  return true;
}


