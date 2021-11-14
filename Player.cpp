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
  m_velocity.setX(0);
  if(m_position.getX() < 0 || m_position.getX() + 82 >= 720)
  {
    //std::cout <<"화면 밖으로 나감" << "\n";
    if(m_position.getX() < 0) // 화면 밖으로 나가도 움직이게 하는 코드
      m_velocity.setX(5);
    else if(m_position.getX() + 82 >= 720)
      m_velocity.setX(-5); // 기존에는 if문 밖에 있는 m_velocity.setX(0);때문에 못 움직여졌음
    // if(m_position.getX() < 0)
    //   m_position.setX(5);
    // else
    //   m_position.setX(-5); // 이렇게만 쓰면 캐릭터가 화면안에서 루프되는것 처럼보인다.
  }
  else{
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
    {
      m_velocity.setX(5);
    }
    else if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
    {
      m_velocity.setX(-5);
    }
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
