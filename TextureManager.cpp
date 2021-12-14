#include "TextureManager.h"
#include "Camera.h"
#include "SDL_image.h"

TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
  SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
  if(pTempSurface == 0)
  {
    return false;
  }
  SDL_Texture* pTextrue = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
  SDL_FreeSurface(pTempSurface);
  if(pTextrue != 0)
  {
    m_textureMap[id] = pTextrue;
    return true;
  }
  return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, float rotationAngle,
SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  //카메라 부분
  destRect.x = x - TheCamera::Instance()->getCameraRect().x;
  destRect.y = y - TheCamera::Instance()->getCameraRect().y;

  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, rotationAngle, NULL, flip);
}
//rotationAngle 추가.
void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, float rotationAngle, int currentRow, int currentFrame, 
SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = width * currentFrame;
  srcRect.y = height * currentRow;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  // 카메라 부분
  destRect.x = x - TheCamera::Instance()->getCameraRect().x;
  destRect.y = y - TheCamera::Instance()->getCameraRect().y;

  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, rotationAngle, NULL, flip);
}

// 문자 출력 부분.
int TextureManager::TTF_drawFont(const char* id, int x, int y, int width, int height, SDL_Renderer* pRenderer)
{
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = x;
  destRect.y = y;

  if (TTF_Init() < 0) { printf("오류: 폰트를 초기화할 수 없습니다. (%s)\n", TTF_GetError()); return false; }
  TTF_Font* font = TTF_OpenFont("res/cocogoose.ttf", 16);
  if (font == NULL)
  {
      printf("Could not open font! (%s)\n", TTF_GetError());
      return -1;
  }

  SDL_Color color = { 255, 255, 255 };
  SDL_Surface* surface = TTF_RenderText_Blended(font, id, color);
  SDL_Texture* texture = SDL_CreateTextureFromSurface(pRenderer, surface);

  SDL_FreeSurface(surface);

  SDL_RenderCopy(pRenderer, texture, &srcRect, &destRect);

  return 0;
}