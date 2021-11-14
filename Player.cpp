#include "Player.h"
#include "InputHandler.h"
#include <iostream>

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{
  SDLGameObject::drawFrame();
}

void Player::update()
{
  handleInput();
  m_currentFrame = ((SDL_GetTicks() / 100) % 6);
  SDLGameObject::update();
}

void Player::clean() {}

void Player::handleInput()
{
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
  {
    m_velocity.setX(2);
  }
  else if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
  {
    m_velocity.setX(-2);
  } 
  else 
  {
    m_velocity.setX(0);
  }

  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
  {
    m_acceleration.setY(-0.1);
  }
  else
  {
    //점프 구현
    if(m_position.getY() + 82 < 720)
      m_acceleration.setY(0.1);
    else{
      m_velocity.setY(0);
      m_acceleration.setY(0);
    }
  }
}
