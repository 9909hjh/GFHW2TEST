#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
  Player(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();
  void handleInput();
  void checkColl();
private:
  bool isGround = true; //땅에 있는지 판별
  bool isJump = false; //점프가 가능한지 판별
  //int GroundPos = 620;
  float verticalVel;
  int JumpForce = 20; // 점프 높이.

  bool isFire;
  bool isfilp;
};