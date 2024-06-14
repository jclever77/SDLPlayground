# pragma once

# include <Common.hpp>
# include <Math.hpp>

class Entity
{
public:
    Entity(SDL_Renderer* renderer, float x, float y, const char filepath[]);

    void Render(SDL_Renderer* renderer);
    void Update(Vector2f updateAmount);
    Vector2f &GetPosition();
    Vector2f &GetVelocity();
    SDL_Texture* GetTexture();
    SDL_Rect GetCurrentFrame();

private:
    Vector2f _position;
    Vector2f _velocity;
    SDL_Rect _sourceFrame;
    SDL_Texture* _texture;
};