# include <Entity.hpp>

Entity::Entity(float x, float y, SDL_Texture* texture)
: _position({ x, y }), _texture(texture)
{
    int w, h;
    SDL_QueryTexture(_texture, NULL, NULL, &w, &h);
    _currentFrame = { 0, 0, w, h };
}

Vector2f &Entity::GetPosition() { return _position; }

SDL_Texture* Entity::GetTexture() { return _texture; }

SDL_Rect Entity::GetCurrentFrame() { return _currentFrame; }