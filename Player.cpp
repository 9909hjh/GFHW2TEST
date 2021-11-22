#include "Player.h"
#include "Game.h"
#include "InputHandler.h"
#include "vector"
#include <iostream>

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{
  SDLGameObject::drawFrame();
}

//void Player::

void Player::update()
{
  handleInput();
  checkColl();
  m_acceleration.setY(0.98);
  m_currentFrame = ((SDL_GetTicks() / 100) % 6);
  SDLGameObject::update();
}

void Player::clean() {}

void Player::handleInput()
{
  m_velocity.setX(0);
  if(m_position.getX() < 0 || m_position.getX() + 128 >= 720)
  {
    //std::cout <<"화면 밖으로 나감" << "\n";
    if(m_position.getX() < 0) // 화면 밖으로 나가도 움직이게 하는 코드
      m_velocity.setX(5);
    else if(m_position.getX() + 128 >= 720)
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
    if(isGround)
    {
      m_velocity.setY(-20);
      m_acceleration.setY(0.1);
      isGround = false;
    }
  }
}

void Player::checkColl()
{
  std::vector<GameObject*> wallcoll = TheGame::Instance()->getTile();

  int plrLeft = m_position.getX();
  int plrRight = plrLeft + m_width;
  int plrTop = m_position.getY();
  int plrBottom = plrTop + m_height;

  for(int i = 0; i < wallcoll.size(); i++)
  {
    int objectLeft = dynamic_cast<SDLGameObject*>(wallcoll[i])->GetPos().getX();
    int objectRight = objectLeft + dynamic_cast<SDLGameObject*>(wallcoll[i])->GetWidth();
    int objectTop = dynamic_cast<SDLGameObject*>(wallcoll[i])->GetPos().getY();
    int objectBottom = objectTop + dynamic_cast<SDLGameObject*>(wallcoll[i])->GetHeight();

    if(plrLeft <= objectRight && plrRight >= objectLeft && plrTop <= objectBottom && plrBottom >= objectTop)
    {
      //아래방향
      if(m_velocity.getY() > 0 && plrBottom >= objectTop && plrBottom < objectBottom && plrLeft != objectRight && plrRight != objectLeft)
      {
        m_position.setY(objectTop - m_height);
        plrTop = m_position.getY();
        plrBottom = plrTop + m_height;

        m_velocity.setY(0);
        m_acceleration.setY(0.0);
        isGround = true;
      } //윗방향
      else if(m_velocity.getY() < 0 && plrTop <= objectBottom && plrTop > objectTop && plrLeft != objectRight && plrRight != objectLeft)
      {
        m_position.setY(objectBottom);
        plrTop = m_position.getY();
        plrBottom = plrTop + m_height;

        m_velocity.setY(0);
      }

      if(m_velocity.getX() < 0 && plrLeft <= objectRight && plrLeft > objectLeft && plrTop != objectBottom && plrBottom != objectTop)
      {
        m_position.setX(objectRight);

        m_velocity.setX(0);
      }
      else if(m_velocity.getX() > 0 && plrRight >= objectLeft && plrRight < objectRight && plrTop != objectBottom && plrBottom != objectTop)
      {
        m_position.setX(objectRight - m_width);

        m_velocity.setX(0);
      }
    }
  }
}