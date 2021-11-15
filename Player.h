#pragma once
#include "SDLGameObject.h"
#include "Tile.h"

class Player : public SDLGameObject
{
public:
  Player(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();
  void handleInput();
  bool checkCollision(SDL_Rect a, SDL_Rect b);
private:
  SDL_Rect m_Coll;
};