# include <game.hpp>
# include <entity.hpp>

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 450

void checkBounds(Entity &entity, Vector2f &movement)
{
    int w = entity.GetCurrentFrame().w / 50;
    int h = entity.GetCurrentFrame().h / 50;
    Vector2f &position = entity.GetPosition();

    if (position.x < 0.0f)
    {
        position.x = 0.0f;
        movement.x *= -1.0f;
    }
    else if (position.x + w > SCREEN_WIDTH)
    {
        position.x = (float) SCREEN_WIDTH - w;
        movement.x *= -1.0f;
    }

    if (position.y < 0.0f)
    {
        position.y = 0.0f;
        movement.y *= -1.0f;
    }
    else if (position.y + h > SCREEN_HEIGHT)
    {
        position.y = (float) SCREEN_HEIGHT - h;
        movement.y *= -1.0f;
    }
}

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