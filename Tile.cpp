#include "Tile.h"

Tile::Tile(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Tile::draw()
{
  SDLGameObject::drawFrame();
}

void Tile::update() {}
void Tile::clean() {}