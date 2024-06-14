# pragma once

# include <Common.hpp>
# include <Entity.hpp>

class Game
{
public:
    Game(const char title[], int w, int h, Uint32 renderFlags);
    ~Game();

    void Run();
    void RenderAll();
    void AddEntity(float x, float y, const char filepath[]);
    void Clear();
    void Display();

    bool IsRunning();

private:
    std::vector<Entity> _entities;
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    bool _isRunning = true;
};