#pragma once
// #include "SDL.h"
// #include <iostream>
#include "LoaderParams.h"

class GameObject{
public:
  virtual void draw() = 0; //순수 가상함수 선언.
  virtual void update() = 0;
  virtual void clean() = 0;
  virtual ~GameObject() {} //가상 소멸자의 선언.

protected:
  GameObject(const LoaderParams* pParams) {}
};