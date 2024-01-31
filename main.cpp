#include "src\camera.cpp"
#include "src\tile.cpp"
#include "src\player.cpp"
#include "src\blueFlower.cpp"

#define WINDOW_WIDHT 1366
#define WINDOW_HEIGHT 768

sf::Event event;
sf::View view;
sf::Clock gameClock;

float deltaTime;
const float gravity = 600.f;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDHT, WINDOW_HEIGHT), "wizard nolep", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    gameClock.restart();

    // TILES
    Tile ground1(sf::Vector2f(WINDOW_WIDHT / 2, WINDOW_HEIGHT - 200));

    // PLAYER
    Player player(sf::Vector2f(ground1.getPosition().x, ground1.getPosition().y - 1380.f));

    // BLUE FLOWER
    BlueFlower blueFlower1(sf::Vector2f(ground1.getPosition().x + 50.f, ground1.getPosition().y - 260.f));

    // view.setViewport(sf::FloatRect(0.f, 0., 1.f, 1.f));


    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                window.close();
                break;
            }

            player.controller(event);
        }

        deltaTime = gameClock.restart().asSeconds();

        player.update(gravity, deltaTime, ground1);
        blueFlower1.update();

        view.setCenter(player.getPosition().x + 70.f, player.getPosition().y - 200.f);

        window.setView(view);

        window.clear();
        window.draw(player);
        window.draw(blueFlower1);
        window.draw(ground1);
        window.display();
    }

    return EXIT_SUCCESS;
}
