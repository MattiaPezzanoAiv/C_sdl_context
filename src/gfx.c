#include <gfx.h>


ctx_t* ctx_init()
{
    ctx_t* ctx = malloc(sizeof(ctx_t));                                     //alloc memory for context
    if(!ctx)
    {
        fprintf(stderr,"Unable to allocate memory for context\n");
        return NULL;
    }

    ctx = memset(ctx,0,sizeof(ctx_t));                                      //clear memory
    ctx->opened = 1;                                                        //default is opened

    if(SDL_Init(SDL_INIT_VIDEO) != 0)                                       //try init sdl video
    {
        const char* error = SDL_GetError();                                       //get error string
        fprintf(stderr,"Unable to initialize sdl: %s\n", error); 
        return NULL;              
    }                                

    if(SDL_CreateWindowAndRenderer(600,600,0,&ctx->window,&ctx->renderer) != 0)//try create window and renderer
    {
        const char* error = SDL_GetError();                                      
        fprintf(stderr,"Unable to create window or renderer: %s\n",error);        
        return NULL;
    }

    return ctx;
}

void ctx_destroy(ctx_t* ctx)
{
    SDL_DestroyRenderer(ctx->renderer);
    SDL_DestroyWindow(ctx->window);
    SDL_Quit();
    free(ctx);
}

void ctx_put_pixel(ctx_t* ctx,int x, int y, uint8_t r, uint8_t g, uint8_t b,uint8_t a)
{
    SDL_SetRenderDrawColor(ctx->renderer,r,g,b,a);                          //set color for renderer
    SDL_RenderDrawPoint(ctx->renderer,x,y);                                 //draw pixel on renderer
}

void ctx_clear(ctx_t* ctx)
{
    SDL_SetRenderDrawColor(ctx->renderer,COLOR_BLACK);    
    SDL_RenderClear(ctx->renderer);
}
void ctx_clear_color(ctx_t* ctx,uint8_t r, uint8_t g, uint8_t b,uint8_t a)
{
    SDL_SetRenderDrawColor(ctx->renderer,r,g,b,a);    
    SDL_RenderClear(ctx->renderer);
}

void ctx_tick(ctx_t* ctx)
{
    float now, last, delta_time;
    last = SDL_GetPerformanceCounter();

    SDL_RenderPresent(ctx->renderer);

    now = SDL_GetPerformanceCounter();
    ctx->delta_time = (now - last) / (double)SDL_GetPerformanceFrequency();
}


rect_obj_t* new_rect_object(int w, int h,uint8_t r,uint8_t g, uint8_t b,uint8_t a)
{
    rect_obj_t* obj = malloc(sizeof(rect_obj_t));
    if(!obj)
    {
        fprintf(stderr,"Unable to instance rect object");
        return NULL;
    }
    obj = memset(obj,0,sizeof(rect_obj_t));
    obj->r = r;
    obj->g = g;
    obj->b = b;
    obj->a = a;

    obj->rect = malloc(sizeof(SDL_Rect));
    obj->rect = memset(obj->rect,0,sizeof(SDL_Rect));
    obj->rect->w = w;
    obj->rect->h = h;
    return obj;
}

void ctx_draw_rect_object(ctx_t* ctx,rect_obj_t* actor)
{
    SDL_SetRenderDrawColor(ctx->renderer,actor->r,actor->g,actor->b, actor->a);
    if(!actor->fill)
        SDL_RenderDrawRect(ctx->renderer,actor->rect);
    else
        SDL_RenderFillRect(ctx->renderer,actor->rect);
}

