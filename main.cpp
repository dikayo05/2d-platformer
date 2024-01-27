#include <SFML/Graphics.hpp>
#include <string>
#include <map>

#define WINDOW_WIDHT 800
#define WINDOW_HEIGHT 600

sf::Event event;
sf::Clock gameClock;
float deltaTime;
std::map<std::string, int> animationSpeed{std::pair("player", 4),
                                          std::pair("plants", 2)};

// player
sf::Texture playerTexture[20];
sf::Sprite player;
sf::Vector2f playerPixelSize(512.f, 512.f),
    playerScale(0.3f, 0.3f);
int8_t playerAnimationCount = 0;
int8_t playerAnimationSpeedCount = 0;

float playerMoveSpeed = 250.f;

// blue flower1
sf::Texture blueFlower1Texture[60];
sf::Sprite blueFlower1;
sf::Vector2f blueFlower1PixelSize(768.f, 768.f);
sf::Vector2f blueFlower1Scale(0.25f, 0.25f);
int8_t blueFlower1AnimationCount = 0;
int8_t blueFlower1AnimationSpeedCount = 0;

int8_t setGame();
void playerController();
void playerAnimation(uint8_t);
void blueFlower1Animation(uint8_t);

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDHT, WINDOW_HEIGHT), "entahlah");
    window.setFramerateLimit(60);

    if (setGame() == EXIT_FAILURE)
        return EXIT_FAILURE;

    gameClock.restart();

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                window.close();
                break;
            }

            if (event.type == sf::Event::Resized)
            {
                sf::View view;
                view.setSize(WINDOW_WIDHT, WINDOW_HEIGHT);
                view.setCenter(WINDOW_WIDHT / 2.f, WINDOW_HEIGHT / 2.f);
                window.setView(view);
            }
        }

        deltaTime = gameClock.restart().asSeconds();

        playerController();
        playerAnimation(animationSpeed["player"]);
        blueFlower1Animation(animationSpeed["plants"]);

        window.clear();
        window.draw(player);
        window.draw(blueFlower1);
        window.display();
    }

    return EXIT_SUCCESS;
}

int8_t setGame()
{
    // player
    for (int8_t i = 0; i < 20; i++)
    {
        if (!playerTexture[i].loadFromFile("res\\player\\blue wizard\\" + std::to_string(i) + ".png"))
            return EXIT_FAILURE;
    }

    player.setScale(playerScale);
    player.setOrigin(playerPixelSize.x / 2, playerPixelSize.y / 2);
    player.setPosition(WINDOW_WIDHT / 2, WINDOW_HEIGHT / 2);

    // blue flower1
    for (int8_t i = 0; i < 60; i++)
    {
        if (!blueFlower1Texture[i].loadFromFile("res\\environment\\plants\\blue flower 1\\" + std::to_string(i) + ".png"))
            return EXIT_FAILURE;
    }

    blueFlower1.setScale(blueFlower1Scale);
    blueFlower1.setOrigin(blueFlower1PixelSize.x / 2, blueFlower1PixelSize.y / 2);
    blueFlower1.setPosition(WINDOW_WIDHT / 2, WINDOW_HEIGHT / 2);

    return EXIT_SUCCESS;
}

void playerController()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player.move(0.f, -playerMoveSpeed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player.move(0.f, playerMoveSpeed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        player.move(-playerMoveSpeed * deltaTime, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player.move(playerMoveSpeed * deltaTime, 0.f);
    }
}

void playerAnimation(uint8_t animationSpeed = 5)
{
    if (playerAnimationSpeedCount < animationSpeed)
    {
        playerAnimationSpeedCount++;
    }
    else
    {
        playerAnimationCount < 19 ? playerAnimationCount++ : playerAnimationCount = 0;
        player.setTexture(playerTexture[playerAnimationCount]);
        playerAnimationSpeedCount = 0;
    }
}

void blueFlower1Animation(uint8_t animationSpeed = 5)
{
    if (blueFlower1AnimationSpeedCount < animationSpeed)
    {
        blueFlower1AnimationSpeedCount++;
    }
    else
    {
        blueFlower1AnimationCount < 59 ? blueFlower1AnimationCount++ : blueFlower1AnimationCount = 0;
        blueFlower1.setTexture(blueFlower1Texture[blueFlower1AnimationCount]);
        blueFlower1AnimationSpeedCount = 0;
    }
}