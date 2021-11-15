#include "Tile.h"
#include <iostream>

Tile::Tile(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Tile::draw()
{
  SDLGameObject::draw();
}

void Tile::update()
{
  //std::cout << m_position.getX() << "\n";
}
void Tile::clean() {}