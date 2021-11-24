//11월 22일 점프 && 콜라이더 수정 및 적용, 총알발사 완료
//화면 스크롤 / 화면 UI추가 실패.(카메라 완료했지만 지각해서 카메라 부분은 서브밋 하지 않았습니다.)
// 총알발사 까지의 UML : https://drive.google.com/file/d/17UtZQcIBaOQ0hM7k5xvGTHdsHxoOyGXD/view?usp=sharing


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