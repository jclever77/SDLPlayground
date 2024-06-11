# pragma once

# include <Common.hpp>
# include <Entity.hpp>

class Game
{
public:
    Game(const char title[], int w, int h, Uint32 renderFlags);
    ~Game();
    SDL_Texture* LoadTexture(const char filepath[]);
    void RenderAll();
    void AddEntity(float x, float y, SDL_Texture* texture);
    void Clear();
    void Display();

    bool IsRunning();
    void stopGame();

private:
    std::vector<Entity> _entities;
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    bool _isRunning;
};