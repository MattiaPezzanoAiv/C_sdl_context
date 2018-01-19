
#include <gfx.h>

int main(int args_count, char** args)
{
    ctx_t* ctx = ctx_init();
    if(ctx == NULL)
        goto END;

    SDL_Event event;

    while(ctx->opened)
    {
        while(SDL_PollEvent(&event) != 0)                    //manage close window event
        {
            if(event.type == SDL_QUIT)
                ctx->opened = 0;
        }
        ctx_clear(ctx);

        ctx_put_pixel(ctx,10,10,255,0,0,255);

        ctx_tick(ctx);
    }


    END:
    ctx_destroy(ctx);
}