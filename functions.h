#include <SDL3/SDL_render.h>


#define SCREEN_WIDTH   600
#define SCREEN_HEIGHT  500
#define ARENA_WIDTH 300
#define ARENA_HEIGHT 200

struct Vector {
  float x;
  float y;
};

typedef struct Color {
  int r;
  int g;
  int b;
} Color;

typedef struct Direction {
  int dx;
  int dy;
} Direction;

typedef struct BouncingObject {
  SDL_FRect rect;
  Color color;
  Direction direction;
  float speed;
} BouncingObject;

extern bool createRect(SDL_Renderer *renderer, BouncingObject bouncingObject);
extern void update(SDL_FRect *rect, Direction *direction, int speed, SDL_FRect arenaRect, BouncingObject (*bouncingObjects)[], int *used, int size);
extern void setColor(SDL_Renderer *renderer, int color);
extern bool renderCircle(SDL_Renderer *renderer, struct Vector pos, int radius, int color);

