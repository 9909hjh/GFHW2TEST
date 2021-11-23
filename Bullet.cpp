#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void Bullet::drawFrame()
{
  if(setFire)
  {
    //bulflipDir();
    setFire = false;
  }
  SDLGameObject::drawFrame();
}

void Bullet::update()
{
  m_acceleration.setY(0);
  BulletCollision();
  Destory();

  if(TheGame::Instance()->getisfilp())
  {
    m_velocity.setX(5);
    
  }
  if(!TheGame::Instance()->getisfilp())
  {
    m_velocity.setX(-5);
  }
  SDLGameObject::update();
}

void Bullet::BulletCollision()
{
  std::vector<GameObject*> wallcoll = TheGame::Instance()->getTile();

  int bulLeft = m_position.getX();
  int bulRight = bulLeft + m_width;
  int bulTop = m_position.getY();
  int bulBottom = bulTop + m_height;

  for(int i = 0; i < wallcoll.size(); i++)
  {
    int objectLeft = dynamic_cast<SDLGameObject*>(wallcoll[i])->GetPos().getX();
    int objectRight = objectLeft + dynamic_cast<SDLGameObject*>(wallcoll[i])->GetWidth();
    int objectTop = dynamic_cast<SDLGameObject*>(wallcoll[i])->GetPos().getY();
    int objectBottom = objectTop + dynamic_cast<SDLGameObject*>(wallcoll[i])->GetHeight();

    if(bulLeft <= objectRight && bulRight >= objectLeft && bulTop <= objectBottom && bulBottom >= objectTop)
    {
      //아래방향
      if(m_velocity.getY() > 0 && bulBottom >= objectTop && bulBottom < objectBottom && bulLeft != objectRight && bulRight != objectLeft)
      {
        m_position.setY(objectTop - m_height);
        bulTop = m_position.getY();
        bulBottom = bulTop + m_height;

        // m_velocity.setY(0);
        // m_acceleration.setY(0.0);
      } //윗방향
      else if(m_velocity.getY() < 0 && bulTop <= objectBottom && bulTop > objectTop && bulLeft != objectRight && bulRight != objectLeft)
      {
        m_position.setY(objectBottom);
        bulTop = m_position.getY();
        bulBottom = bulTop + m_height;

        //m_velocity.setY(0);
      }

      if(m_velocity.getX() < 0 && bulLeft <= objectRight && bulLeft > objectLeft && bulTop != objectBottom && bulBottom != objectTop)
      {
        m_position.setX(objectRight);
        m_velocity.setX(0);
        TheGame::Instance()->BulletDestory();
        setFire = true;
      }
      else if(m_velocity.getX() > 0 && bulRight >= objectLeft && bulRight < objectRight && bulTop != objectBottom && bulBottom != objectTop)
      {
        m_position.setX(objectLeft - m_width);
        m_velocity.setX(0);
        TheGame::Instance()->BulletDestory();
        setFire = true;
      }
    }
    
  }
}
//총알 삭제.
void Bullet::Destory()
{
  if(m_position.getX() < 0 || m_position.getX() > 720)
  {
    TheGame::Instance()->BulletDestory();
  }
  setFire = true;
}