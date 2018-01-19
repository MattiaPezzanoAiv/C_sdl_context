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
    float delta_time;       
    
}ctx_t;
typedef struct rect_object
{
    SDL_Rect* rect;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    int fill;                               //if is 1 fill
}rect_obj_t;


ctx_t* ctx_init();
void ctx_tick(ctx_t*);
void ctx_put_pixel(ctx_t*, int,int, uint8_t,uint8_t,uint8_t,uint8_t);  //ctx, x,y, r,g,b,a
void ctx_clear(ctx_t*);                                                 //simple clear, set default black color
void ctx_clear_color(ctx_t*,uint8_t,uint8_t,uint8_t,uint8_t);           //complex clear, can set clear color
void ctx_destroy(ctx_t*);

rect_obj_t* new_rect_object(int,int,uint8_t,uint8_t,uint8_t,uint8_t);   //w,h
void ctx_draw_rect_object(ctx_t*,rect_obj_t*);







//COLORS
#define COLOR_BLACK 0,0,0,0
#define COLOR_RED 255,0,0,255
#define COLOR_GREEN 0,255,0,255
#define COLOR_BLUE 0,0,255,255
