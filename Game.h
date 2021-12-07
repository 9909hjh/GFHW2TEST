#ifndef __Game__
#define __Game__

#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Tile.h"
#include "Bullet.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"
#include "vector"

class GameStateMachine;

class Game {
  public:
  Game() : isfilp(true){}
  ~Game() {}

  bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
  void render();
  void update();
  bool running();
  void handleEvents();
  void clean();
  void quit() {m_bRunning = false;}

  GameStateMachine* getStateMachine()
	{
		return m_pGameStateMachine;
	}

  std::vector<GameObject*> getTile() const { return m_tile; } // 타일 오브젝트 coll
  //std::vector<GameObject*> getbullet() const { return m_bullet; } //총알오브젝트 coll
  // template <class Bult>
  // void getBul(Bult* bult)
  // {
  //   m_bullet.push_back(bult);
  // }
  
  // bool getFire() {return Fire;} // 총알 발사
  // void Firecheck(bool a) {Fire = a;} // 총알이 발사됬는지.

  bool getisfilp() {return isfilp;} // 플립이 되었는지
  void isfilpcheck(bool a) {isfilp = a;} // 플립확인.

  //void BulletDestory();

  static Game* Instance() {
    if(s_pInstance == 0) {
      s_pInstance = new Game();
      return s_pInstance;
    }
    return s_pInstance;
  }
  SDL_Renderer* getRenderer() const {return m_pRenderer; } 
  
private:
  
  static Game* s_pInstance;
  
  std::vector<GameObject*> m_gameObjects;
  
  std::vector<GameObject*> m_tile;
  // std::vector<GameObject*> m_bullet;

  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;
  int m_currentFrame;

  bool isfilp; // 총알방향
  // bool Fire;

  GameStateMachine* m_pGameStateMachine;
};

typedef Game TheGame;

#endif