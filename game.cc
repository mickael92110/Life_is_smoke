#include "game.hh"

Game::Game(): m_window("Chapter 2", sf::Vector2u(800,600)){
  // Setting up class members.
  m_ButterflyTexture.loadFromFile("icon.jpeg");
  m_Butterfly.setTexture(m_ButterflyTexture);
  m_increment = sf::Vector2i(4,4);
}

Game::~Game(){}

void Game::Update(){
  m_window.Update(); // Update window events.
  MoveButterfly();
}

void Game::MoveButterfly(){
  sf::Vector2u l_windSize = m_window.GetWindowSize();
  sf::Vector2u l_textSize = m_ButterflyTexture.getSize();
  if((m_Butterfly.getPosition().x >
  l_windSize.x - l_textSize.x&&m_increment.x> 0) ||
  (m_Butterfly.getPosition().x < 0 &&m_increment.x< 0)){
  m_increment.x = -m_increment.x;
  }
  if((m_Butterfly.getPosition().y >
  l_windSize.y - l_textSize.y&&m_increment.y> 0) ||
  (m_Butterfly.getPosition().y < 0 &&m_increment.y< 0)){
  m_increment.y = -m_increment.y;
  }
  m_Butterfly.setPosition(
  m_Butterfly.getPosition().x + m_increment.x,
  m_Butterfly.getPosition().y + m_increment.y);
}

void Game::Render(){
  m_window.BeginDraw(); // Clear.
  m_window.Draw(m_Butterfly);
  m_window.EndDraw(); // Display.
}

Window* Game::GetWindow(){
  return &m_window;
}
