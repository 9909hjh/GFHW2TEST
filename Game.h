#ifndef __Game__
#define __Game__

#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Tile.h"
#include "InputHandler.h"
#include "vector"


class Game {
  public:
  ~Game() {}

  bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
  void render();
  void update();
  bool running();
  void handleEvents();
  void clean();
  void quit() {m_bRunning = false;}

  std::vector<GameObject*> getTile() const {return m_tile; }
  
  static Game* Instance() {
    if(s_pInstance == 0) {
      s_pInstance = new Game();
      return s_pInstance;
    }
    return s_pInstance;
  }
  SDL_Renderer* getRenderer() const {return m_pRenderer; } 
  
private:
  Game() {}
  static Game* s_pInstance;
  
  std::vector<GameObject*> m_gameObjects;
  
  std::vector<GameObject*> m_tile;

  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;
  int m_currentFrame; 
};

typedef Game TheGame;

#endif