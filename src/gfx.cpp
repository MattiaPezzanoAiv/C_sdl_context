#include <gfxcpp>

void ctx::update()
{
    SDL_RenderPresent(this->renderer);
}
void ctx::clear()
{
    SDL_SetRenderDrawColor(this->renderer,0,0,0,255);
    SDL_RenderClear(this->renderer);
}
void ctx::put_pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_SetRenderDrawColor(this->renderer,r,g,b,a);
    SDL_RenderDrawPoint(this->renderer,x,y);
}