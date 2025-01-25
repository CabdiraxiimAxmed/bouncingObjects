#include <SDL3/SDL_render.h>


#define SCREEN_WIDTH   600
#define SCREEN_HEIGHT  500
#define ARENA_WIDTH 200
#define ARENA_HEIGHT 200

struct Vector {
  float x;
  float y;
};

typedef struct BouncingObject {
  SDL_FRect rect;
  int color;
} BouncingObject;


extern bool createRect(SDL_Renderer *renderer, BouncingObject bouncingObject);
extern void update(SDL_FRect *rect, SDL_FRect arenaRect);
extern void setColor(SDL_Renderer *renderer, int color);
extern bool renderCircle(SDL_Renderer *renderer, struct Vector pos, int radius, int color);

