#include <SDL3/SDL_render.h>


#define SCREEN_WIDTH   600
#define SCREEN_HEIGHT  500
#define ARENA_WIDTH 300
#define ARENA_HEIGHT 200


struct Vector {
  float x;
  float y;
};

extern bool createRect(SDL_Renderer *renderer, struct Vector *pos, int color);
extern void update(struct Vector *pos, SDL_FRect rect );
extern void setColor(SDL_Renderer *renderer, int color);
extern bool renderCircle(SDL_Renderer *renderer, struct Vector pos, int radius, int color);

