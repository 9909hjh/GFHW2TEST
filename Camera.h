#include "SDL.h"
#include <iostream>

class Camera {
public:
  static Camera* Instance()
  {
    if(s_pInstance == 0) s_pInstance = new Camera();
    return s_pInstance;
  }
  void init();

  SDL_Rect getCameraRect() {return cameraRect;}
  void getCameraRectX(int m_x) {cameraRect.x = m_x;}
  void getCameraRectY(int m_y) {cameraRect.y = m_y;}

private:
  Camera()
  {
    cameraRect.x = 0;
    cameraRect.y = 0;
    cameraRect.w = 720;
    cameraRect.h = 720;
  }
  static Camera* s_pInstance;
  SDL_Rect cameraRect;
};

typedef Camera TheCamera;