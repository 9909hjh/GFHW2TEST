#pragma once
#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject {
public:
  SDLGameObject(const LoaderParams* pParams);
  virtual void drawFrame(); // drawFrame()함수 추가.
  virtual void draw(); //
  virtual void update();
  //virtual void update() {}에서 함수가 있으니 {}를 삭제.
  virtual void clean() {}
  
  virtual ~SDLGameObject() {}

protected:
  // int m_x;
  // int m_y;
  Vector2D m_position; // 위치

  Vector2D m_velocity;
  Vector2D m_acceleration;

  int m_width;
  int m_height;
  int m_rotationAngle; // 회전을 위한 추가
  int m_currentRow;
  int m_currentFrame;
  std::string m_textureID;
};