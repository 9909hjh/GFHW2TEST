#include "MenuState.h"
#include <iostream>
#include "MenuButton.h"
#include "TextureManager.h"
#include "Game.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
  for(int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->draw();
  }
}

void MenuState::render()
{
  for(int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->draw();
  }
}

bool MenuState::onEnter()
{
  if(!TheTextureManager::Instance()->load("Asset/button.png","playbutton", TheGame::Instance()->getRenderer()))
  {
    return false;
  }
  if( !TheTextureManager::Instance()->load("Assets/exit.png", "exitbutton", TheGame::Instance()->getRenderer())){
     return false;
  }

  GameObject* button1 = new MenuButton(new LoaderParams(100, 100, 400, 100, "playbutton"), s_menuToPlay);

  GameObject* button2 = new MenuButton(new LoaderParams(100, 300, 400, 100, "exitbutton"), s_exitFromMenu);

  m_gameObjects.push_back(button1);
  m_gameObjects.push_back(button2);
  
  return true;
}

bool MenuState::onExit()
{
  std::cout << "MEonExit MenuState" << std::endl;
	return true;
}

void MenuState::s_menuToPlay()
{
	std::cout << "Play button clicked\n";
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu()
{
	std::cout << "Exit button clicked\n";
	TheGame::Instance()->quit();
}