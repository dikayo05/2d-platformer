#include "src\player.cpp"

#define WINDOW_WIDHT 800
#define WINDOW_HEIGHT 600

sf::Event event;
sf::View view;
sf::Clock gameClock;
float deltaTime;
const float gravity = 600.f;

// map
sf::Texture bgTexture;
sf::Sprite bg(bgTexture);

// anu
sf::RectangleShape obs(sf::Vector2f(120.f, 60.f));

// text
sf::Font font;
sf::Text text;

int8_t setGame();

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDHT, WINDOW_HEIGHT), "wizard nolep");
    window.setFramerateLimit(60);

    if (setGame() == EXIT_FAILURE)
        return EXIT_FAILURE;

    gameClock.restart();

    Player player(sf::Vector2f(WINDOW_WIDHT / 2, WINDOW_HEIGHT / 2));
    view.setViewport(sf::FloatRect(0.f, 0., 1.f, 1.f));

    bgTexture.loadFromFile("rsc\\envrironment\\map\\pixel-city.jpg");

    obs.setFillColor(sf::Color::Blue);
    obs.setPosition(WINDOW_WIDHT / 2, WINDOW_HEIGHT / 2);

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

        player.update(gravity, deltaTime);
        // blueFlower1Animation(blueFlower1AnimationDelay);

        view.setCenter(player.getPosition().x, 0);
        window.setView(view);

        window.clear();
        window.draw(bg);
        window.draw(player);
        window.draw(obs);
        // window.draw(blueFlower1);
        window.display();
    }

    return EXIT_SUCCESS;
}

int8_t setGame()
{
    // text
    // font.loadFromFile("res\\font\\tuffy.ttf");
    // text.setFont(font);
    // text.setString("Loading..");
    // text.setPosition(WINDOW_WIDHT / 2, WINDOW_HEIGHT / 2);

    return EXIT_SUCCESS;
}