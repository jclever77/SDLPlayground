# include <Game.hpp>

Game::Game(const char title[], int w, int h, Uint32 renderFlags)
: _isRunning(true)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "'SDL_INIT' failed. ERROR: " << SDL_GetError() << std::endl;
    }
    
    int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
    if (IMG_Init(imgFlags) != imgFlags)
    {
        std::cout << "'IMG_INIT' failed. ERROR: " << SDL_GetError() << std::endl;
    }
    
    _window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        w, h,
        0
    );

    if (!_window)
    {
        std::cout << "'CreateWindow' failed. ERROR: " << SDL_GetError() << std::endl;
    }

    _renderer = SDL_CreateRenderer(
        _window,
        -1,
        renderFlags
    );

    if (!_renderer)
    {
        std::cout << "'CreateRenderer' failed. ERROR: " << SDL_GetError << std::endl;
    }
}

Game::~Game()
{
    for (auto &entity : _entities)
    {
        SDL_DestroyTexture(entity.GetTexture());
    }
    
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture* Game::LoadTexture(const char filepath[])
{
    SDL_Texture* texture = IMG_LoadTexture(_renderer, filepath);

    if (!texture)
    {
        std::cout << "'LoadTexture' failed. ERROR: " << SDL_GetError() << std::endl;
    }

    return texture;
}

void Game::RenderAll()
{
    for (auto entity : _entities)
    {
        SDL_Rect source = entity.GetCurrentFrame();
        SDL_Rect dest = {
            (int) entity.GetPosition().x,
            (int) entity.GetPosition().y,
            source.w / 10,
            source.h / 10
        };

        SDL_RenderCopy(_renderer, entity.GetTexture(), &source, &dest);
    }
}

void Game::AddEntity(float x, float y, SDL_Texture* texture)
{
    _entities.push_back({ x, y, texture });
}

void Game::Clear() { SDL_RenderClear(_renderer); }

void Game::Display() { SDL_RenderPresent(_renderer); }

bool Game::IsRunning() { return _isRunning; };

void Game::stopGame() { _isRunning = false; }