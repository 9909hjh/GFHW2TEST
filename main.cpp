//11월 13일 점프구현 완료
//장애물, 충돌 검사 / 총알발사 / 화면 스크롤 / 화면 UI추가 / UML 해야함.


#include "Game.h"
#include <iostream>

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
  if(TheGame::Instance()->init("Chapter 1", 0, 0, 720, 720, false))
  {
    Uint32 frameStart, frameTime;
    while (TheGame::Instance()->running())
  {
    frameStart = SDL_GetTicks();
    TheGame::Instance()->handleEvents();
    TheGame::Instance()->update();
    TheGame::Instance()->render();
    frameTime = SDL_GetTicks() - frameStart;
    if(frameTime < DELAY_TIME)
    {
      SDL_Delay((int)(DELAY_TIME - frameTime));
    }
  }
  } else {
    std::cout << "game init failure" << SDL_GetError() << "\n";
    return -1;
  }
  //TheInputHandler::Instance()->clean();
  TheGame::Instance()->clean(); // 수정 후 코드 
  return 0;
}