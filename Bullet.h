#pragma once
#include "SDLGameObject.h"
#include "Game.h"
#include "SDL.h"
#include <vector>

class Bullet : public SDLGameObject
{
public:
  Bullet(const LoaderParams* pParams);
  virtual void drawFrame();
  virtual void update();
  virtual void clean() {}
  void BulletCollision();
  //void Destory();
  //void bulflipDir();

  bool setFire;
};