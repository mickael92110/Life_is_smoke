#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <iostream>
#include <cstdlib>
#include "window.hh"

#ifndef GAME
#define GAME

class Game{
  public:
    Game();
    ~Game();
    void HandleInput();
    void Update();
    void Render();
    Window* GetWindow();

  private:
    void MoveButterfly();
    Window m_window;
    sf::Texture m_ButterflyTexture;
    sf::Sprite m_Butterfly;
    sf::Vector2i m_increment;
};



#endif
