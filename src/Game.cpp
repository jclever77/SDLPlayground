# include <Game.hpp>

Game::Game(const char title[], int w, int h, Uint32 renderFlags)
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

void Game::Run()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                _isRunning = false;
                break;

            case SDL_MOUSEBUTTONDOWN:
                switch (event.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        std::cout << "Left-mouse click" << std::endl;
                        break;
                    case SDL_BUTTON_RIGHT:
                        std::cout << "Right-mouse click" << std::endl;
                        break;
                    case SDL_BUTTON_MIDDLE:
                        std::cout << "Middle-mouse click" << std::endl;
                        break;
                }
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_w:
                        _entities[0].Update({ 0.0f, -3.0f });
                        break;
                    case SDLK_a:
                        _entities[0].Update({ -3.0f, 0.0f });
                        break;
                    case SDLK_s:
                        _entities[0].Update({ 0.0f, 3.0f });
                        break;
                    case SDLK_d:
                        _entities[0].GetVelocity() = { 3.0f, 0.0f };
                        break;
                }
                break;
        }
    }

    for (auto &entity : _entities)
    {
        entity.GetPosition() += entity.GetVelocity();
    }

    Clear();
    RenderAll();
    Display();
}

void Game::RenderAll()
{
    for (auto &entity : _entities)
    {
        entity.Render(_renderer);
    }
}

void Game::AddEntity(float x, float y, const char filepath[])
{
    _entities.push_back({_renderer, x, y, filepath });
}

void Game::Clear() { SDL_RenderClear(_renderer); }

void Game::Display() { SDL_RenderPresent(_renderer); }

bool Game::IsRunning() { return _isRunning; };