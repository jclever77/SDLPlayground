# pragma once

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <algorithm>
# include <math.hpp>

class Entity
{
public:
    Entity(SDL_Renderer* renderer, float x, float y, const char filepath[]);

    void Render(SDL_Renderer* renderer);
    void Update(const Uint8* keystate);
    void CheckBounds();
    Vector2f &GetPosition();
    SDL_Texture* GetTexture();
    SDL_Rect GetCurrentFrame();

private:
    Vector2f _position;
    Vector2f _velocity;
    Vector2f _gravity = { 0.0f, 3.0f };
    SDL_Rect _sourceFrame;
    SDL_Texture* _texture;
    bool _grounded;
};