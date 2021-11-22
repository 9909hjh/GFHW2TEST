#include "Game.h"
#include "SDL_image.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0) 
  {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if(m_pWindow != 0) {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
      if(m_pWindow != 0)
      {
        SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
      } else {
        return false;
      }
    } else {
      return false;
    }
  } else {
    return false;
  }

  
  if( !TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer)){
     return false;
  }
  
  if( !TheTextureManager::Instance()->load("Assets/Wall.png", "Wall", m_pRenderer)){
     return false;
  }

  m_gameObjects.push_back( new Player( new LoaderParams(100, 300, 128, 82, "animate")));

  for(int posX = 0; posX <= 600; posX += 40)
  {
    m_tile.push_back( new Tile( new LoaderParams(posX, 680, 40, 40, "Wall")));
  }

  m_tile.push_back( new Tile( new LoaderParams(100, 500, 40, 40, "Wall")));
  m_tile.push_back( new Tile( new LoaderParams(150, 550, 40, 40, "Wall")));

  
  m_bRunning = true;
  
  return true;
}

void Game::update()
{

  for(int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i] -> update();
  }

  for(int i = 0; i< m_tile.size(); i++)
  {
    m_tile[i] -> update();
  }

}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);

  for(int i = 0; i != m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->draw();
  }

  for(int i = 0; i< m_tile.size(); i++)
  {
    m_tile[i] -> draw();
  }

  SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
  return m_bRunning;
}

void Game::handleEvents()
{
  TheInputHandler::Instance()->update();
}

void Game::clean()
{
  TheInputHandler::Instance()->clean(); // 수정 후 코드
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}