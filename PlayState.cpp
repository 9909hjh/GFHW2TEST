#include "PlayState.h"
#include <iostream>

const std::string PlayState::s_playID = "PlayState";

void PlayState::update()
{

}

void PlayState::render()
{

}

bool PlayState::onEnter()
{
  std::cout << "MEonEnter PlayState" << std::endl;
	return true;
}

bool PlayState::onExit()
{
  std::cout << "MEonExit PlayState" << std::endl;
	return true;
}