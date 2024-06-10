# pragma once

# include <Common.hpp>
# include <Math.hpp>

class Entity
{
public:
    Entity(float x, float y, SDL_Texture* texture);
    Vector2f &GetPosition();
    SDL_Texture* GetTexture();
    SDL_Rect GetCurrentFrame();

private:
    Vector2f _position;
    SDL_Rect _currentFrame;
    SDL_Texture* _texture;
};