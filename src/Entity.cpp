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

void Entity::Update(const Uint8* keystate)
{
    if (keystate[SDL_SCANCODE_A]) { _velocity.x = -5.0f; }
    if (keystate[SDL_SCANCODE_D]) { _velocity.x = 5.0f; }
    if (!keystate[SDL_SCANCODE_A] && !keystate[SDL_SCANCODE_D]) { _velocity.x = 0.0f; }
    if (_grounded && keystate[SDL_SCANCODE_SPACE])
    {
        _velocity += { 0.0f, -40.0f };
        _grounded = false;
    }

    _velocity += _gravity;
    _position += _velocity;
    CheckBounds();
}

void Entity::CheckBounds()
{
    int w = _sourceFrame.w / 10;
    int h = _sourceFrame.h / 10;

    if (_position.x < 0.0f)
    {
        _position.x = 0.0f;
    }
    else if (_position.x + w > 800.0f)
    {
        _position.x = 800.0f - w;
    }

    if (_position.y < 0.0f)
    {
        _position.y = 0.0f;
    }
    else if (_position.y + h > 450.0f)
    {
        _position.y = 450.0f - h;
        _velocity.y = 0.0f;
        _grounded = true;
    }
}

Vector2f &Entity::GetPosition() { return _position; }

SDL_Texture* Entity::GetTexture() { return _texture; }

SDL_Rect Entity::GetCurrentFrame() { return _sourceFrame; }