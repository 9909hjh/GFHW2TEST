#pragma once
#include "SDL.h"
#include "Vector2D.h"
#include "vector"

enum mouse_buttons {
  LEFT = 0,
  MIDDLE = 1,
  RIGHT = 2
};

class InputHandler {
public:
  InputHandler();
  ~InputHandler() {}
  static InputHandler* Instance() {
    if(s_pInstance == 0){
      s_pInstance = new InputHandler();
    }
    return s_pInstance;
  }
  bool isKeyDown(SDL_Scancode key);
  void update();
  void clean() {}
 
  // 키입력 을 위한 함수
  void onMouseMove(SDL_Event event);
  void onMouseButtonDown(SDL_Event event);
  void onMouseButtonUp(SDL_Event event);
  void onKeyDown();
  void onKeyUP();

  // 마우스 움직임을 위한 함수
  bool getMouseButtonState(int buttonNumber);
  Vector2D* getMousePosition(); // 마우스 부분

private:
  
  static InputHandler* s_pInstance;
  const Uint8* m_keystates;

  std::vector<bool> m_mouseButtonStates; 
  Vector2D* m_mousePosition; // 마우스 부분
};
typedef InputHandler TheInputHandler;