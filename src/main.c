
#include <gfx.h>

int main(int args_count, char** args)
{
    ctx_t* ctx = ctx_init();
    if(ctx == NULL)
        goto END;

    SDL_Event event;

    rect_obj_t* player = new_rect_object(50,50,COLOR_GREEN);
    player->rect->x = 100;
    player->rect->y = 200;
    player->fill = 1;

    while(ctx->opened)
    {
        while(SDL_PollEvent(&event) != 0)                    //manage close window event
        {
            if(event.type == SDL_QUIT)
                ctx->opened = 0;
            }

        ctx_clear(ctx);

        ctx_put_pixel(ctx,10,10,COLOR_GREEN);
        ctx_draw_rect_object(ctx,player);
        ctx_tick(ctx);
        
        fprintf(stdout,"%f\n",ctx->delta_time);
    }


    END:
    ctx_destroy(ctx);
}