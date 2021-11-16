#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams)
  : GameObject(pParams), m_position(pParams->getX(), pParams->getY()), m_velocity(0, 0), m_acceleration(0, 0) {
  // m_x = pParams->getX();
  // m_y = pParams->getY();
  m_width = pParams->getWidth();
  m_height = pParams->getHeight();
  m_textureID = pParams->getTextureID();
  m_rotationAngle = 0;
  m_currentRow = 0;
  m_currentFrame = 0;
}
//m_rotationAngle 추가.
void SDLGameObject::drawFrame() 
{
  if(m_velocity.getX() < 0){
  TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_rotationAngle, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL); // 플립부분
  }
  else
  {
    TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_rotationAngle, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
  }
}

void SDLGameObject::draw() 
{
  if(m_velocity.getX() > 0)
  TextureManager::Instance()->draw(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_rotationAngle, TheGame::Instance()->getRenderer());
}

void SDLGameObject::update()
{
  // m_position.setX(m_position.getX() + 1);
  // m_position.setY(m_position.getY() + 1);
  m_velocity += m_acceleration;
  m_position += m_velocity;
}


// void SDLGameObject::draw() {
//   TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
// }