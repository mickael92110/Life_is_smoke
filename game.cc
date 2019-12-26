#include "game.hh"

Game::Game(): m_window("Life is Smoke", sf::Vector2u(960,540)){
  // Setting up class members.
  backgroundTexture.loadFromFile("back2.jpeg");
  background.setTexture(backgroundTexture);

}

Game::~Game(){}

void Game::Update(){
  m_window.Update(); // Update window events.
  //MoveButterfly();
}

void Game::changeBackground(std::string img){
  backgroundTexture.loadFromFile(img);
  background.setTexture(backgroundTexture);
}

void Game::Render(){
  m_window.BeginDraw(); // Clear.
  m_window.Draw(background);
  m_window.EndDraw(); // Display.
}

Window* Game::GetWindow(){
  return &m_window;
}
