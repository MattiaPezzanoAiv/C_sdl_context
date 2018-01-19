#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif


typedef struct ctx 
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event* event;

    int opened;                             //is window opened
}ctx_t;


ctx_t* ctx_init();
void ctx_tick(ctx_t*);
void ctx_put_pixel(ctx_t*, int,int, uint8_t,uint8_t,uint8_t,uint8_t);  //ctx, x,y, r,g,b,a
void ctx_clear(ctx_t*);                                                 //simple clear, set default black color
void ctx_clear_color(ctx_t*,uint8_t,uint8_t,uint8_t,uint8_t);           //complex clear, can set clear color
void ctx_destroy(ctx_t*);