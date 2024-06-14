# include <entity.hpp>

Entity::Entity(SDL_Renderer* renderer, float x, float y, const char filepath[])
: _position({ x, y })
{
    _texture = IMG_LoadTexture(renderer, filepath);
    
    int w, h;
    SDL_QueryTexture(_texture, NULL, NULL, &w, &h);
    _sourceFrame = { 0, 0, w, h };
}

void Entity::Render(SDL_Renderer* renderer)
{
    SDL_Rect dest = {
        (int) _position.x,
        (int) _position.y,
        _sourceFrame.w / 10,
        _sourceFrame.h / 10
    };

    SDL_RenderCopy(renderer, _texture, &_sourceFrame, &dest);
}

void Entity::Update(Vector2f updateAmount)
{
    _velocity = updateAmount;
}

Vector2f &Entity::GetPosition() { return _position; }

Vector2f &Entity::GetVelocity() { return _velocity; }

SDL_Texture* Entity::GetTexture() { return _texture; }

SDL_Rect Entity::GetCurrentFrame() { return _sourceFrame; }