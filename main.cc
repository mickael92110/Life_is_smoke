#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(960, 540), "Life is Smoke");

    sf::Image icon;
    icon.loadFromFile("icon.jpeg"); // File/Image/Pixel

    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("back2.jpeg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("Amatic-Bold.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Life is Smoke", font, 200);
    text.setPosition(200,300);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("15 Jonathan Morali _ Golden Hour.ogg"))
        return EXIT_FAILURE;
    // Play the music
    music.play();
    music.setLoop(true);
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::Resized)
            {
                std::cout << "new width: " << event.size.width << std::endl;
                std::cout << "new height: " << event.size.height << std::endl;
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                    sf::Text text("Life is Mimi", font, 200);
                    text.setPosition(100,300);
                    if (!music.openFromFile("Obstacles.ogg"))
                        return EXIT_FAILURE;
                    music.play();
                    music.setLoop(true);

                    if (!texture.loadFromFile("tornade.png"))
                        return EXIT_FAILURE;

                    sf::Sprite sprite(texture);
                    sprite.setScale(0.5,0.5);

                    while (window.isOpen())
                    {
                      while (window.pollEvent(event))
                      {
                          // Close window: exit
                          if (event.type == sf::Event::Closed)
                              window.close();
                    // Clear screen
                    window.clear();
                    // Draw the sprite
                    window.draw(sprite);
                    // Draw the string
                    window.draw(text);
                    // Update the window
                    window.display();
                  }
                }
                }
            }
        }
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(sprite);
        // Draw the string
        window.draw(text);
        // Update the window
        window.display();
    }
    // Game game;
    // game.run();
    return EXIT_SUCCESS;
}
