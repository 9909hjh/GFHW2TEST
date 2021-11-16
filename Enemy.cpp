#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void Enemy::draw()
{
  SDLGameObject::drawFrame();
}

void Enemy::update()
{
  // m_velocity.setX(2);
  // m_velocity.setY(2);
  // m_currentFrame = ((SDL_GetTicks() / 100) % 6);
}

void Enemy::clean()
{
  
}