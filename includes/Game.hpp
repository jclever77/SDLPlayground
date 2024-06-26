# pragma once

# include <string>
# include <vector>
# include <entity.hpp>

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
    float fps = 0.0f;
    int frameCount;
    bool _isRunning = true;
};