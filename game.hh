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
    void changeBackground(std::string img);
    Window m_window;
    sf::Texture backgroundTexture;
    sf::Sprite background;
    
};



#endif
