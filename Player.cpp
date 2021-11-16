#include "Player.h"
#include "InputHandler.h"
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
  m_currentFrame = ((SDL_GetTicks() / 100) % 6);
  SDLGameObject::update();
}

void Player::clean() {}

void Player::handleInput()
{
  SDL_Rect wall;
  wall.x = 520;
  wall.y = 620;
  wall.w = 100;
  wall.h = 100;

  m_Coll.x = m_position.getX();
  m_Coll.y = m_position.getY();
  

  m_velocity.setX(0);
  if(m_position.getX() < 0 || m_position.getX() + 128 >= 720 || checkCollision(m_Coll, wall))
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
  

  if(m_position.getY() >= GroundPos)
    isGround = true;
  else
    isGround = false;

  if(isGround || checkCollision(m_Coll, wall))
  {
    verticalVel = 0;
    m_position.setY(GroundPos);
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
    {
      verticalVel = -JumpForce;
    }
  }
  else if(!isGround)
  {
    verticalVel += 1; // 중력값
  }

  m_velocity.setY(verticalVel);
  
}

bool Player::checkCollision(SDL_Rect a, SDL_Rect b)
{
  int leftA, leftB;
  int rightA, rightB;
  int topA, topB;
  int bottomA, bottomB;

  leftA = a.x;
  rightA = a.x + a.w;
  topA = a.y;
  bottomA = a.y + a.h;

  leftB = b.x;
  rightB = b.x + b.w;
  topB = b.y;
  bottomB = b.y + b.h;

  if(bottomA <= topB) return false;
  if(topA >= leftB) return false;
  if(rightA <= leftB) return false;
  if(leftA >= rightB) return false;

  return true;
}