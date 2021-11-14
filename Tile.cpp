#include "Tile.h"

Tile::Tile(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Tile::draw()
{
  SDLGameObject::draw();
}

void Tile::update() {}
void Tile::clean() {}