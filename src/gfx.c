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
    SDL_SetRenderDrawColor(ctx->renderer,0,0,0,1);    
    SDL_RenderClear(ctx->renderer);
}
void ctx_clear_color(ctx_t* ctx,uint8_t r, uint8_t g, uint8_t b,uint8_t a)
{
    SDL_SetRenderDrawColor(ctx->renderer,r,g,b,a);    
    SDL_RenderClear(ctx->renderer);
}

void ctx_tick(ctx_t* ctx)
{
    SDL_RenderPresent(ctx->renderer);
}