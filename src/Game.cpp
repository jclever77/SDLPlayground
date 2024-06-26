# include <game.hpp>

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
    Uint32 frameBegin = SDL_GetTicks();
    
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                _isRunning = false;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        _isRunning = false;
                        break;
                }
                break;
        }
    }

    _entities[0].Update(SDL_GetKeyboardState(NULL));

    Clear();
    RenderAll();
    Display();

    // Uint32 frameTime = SDL_GetTicks() - frameBegin;
    // if (frameTime < 1000 / 60) { SDL_Delay(1000 / 60 - frameTime); }

    fps += 1000.0f / (float) (SDL_GetTicks() - frameBegin);
    if (frameCount++ % 30 == 0)
    {
        std::string title = "SDL2 Window     FPS: " + std::to_string(fps / 30.0f);
        SDL_SetWindowTitle(_window, title.c_str());
        fps = 0.0f;
    }
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