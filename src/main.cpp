# include <game.hpp>
# include <entity.hpp>

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 450

int main(int argc, char* argv[])
{
    Game game(
        "SDL2 Window",
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC    
    );

    game.AddEntity(0, 0, "assets/img/bup.jpg");
    
    while (game.IsRunning())
    {
        game.Run();
    }

    return 0;
}