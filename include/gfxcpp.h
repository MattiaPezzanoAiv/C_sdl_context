#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include <iostream>


struct ctx 
{
    SDL_Window* window;
    SDL_Renderer* renderer;

    int opened;                             //is window opened
    float delta_time;   
    
    void update();
    void clear();
    void put_pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

};

struct ctx_safe
{
    ctx* context;

    ctx_safe()
    {
        context = new ctx();
        if(!context) delete context;

        if(SDL_Init(SDL_WINDOW_OPENGL) != 0)
            delete context;

        if(SDL_CreateWindowAndRenderer(600,600,0,&context->window,&context->renderer) != 0)//try create window and renderer
        {
            const char* error = SDL_GetError();
            std::cout << "Unable to create window and renderer: "<< error;                                     
            delete context;
        }
    }

    ~ctx_safe()
    {
        if(!context->window) SDL_DestroyWindow(context->window);
        if(!context->renderer) SDL_DestroyRenderer(context->renderer);
        
        SDL_Quit();
    }
};





