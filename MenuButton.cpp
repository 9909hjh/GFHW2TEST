#include "SDLGameObject.h"
#include "MenuButton.h"
#include "InputHandler.h"

MenuButton::MenuButton(const LoaderParams* pParams, void(*callback)()) : SDLGameObject(pParams), m_callback(callback)
{

}

void MenuButton::draw()
{
  SDLGameObject::draw();
}

void MenuButton::clean()
{
  SDLGameObject::clean();
}

void MenuButton::update()
{
  Vector2D* pMousePos =
		TheInputHandler::Instance()->getMousePosition();
	if (pMousePos->getX() < (m_position.getX() + m_width)
		&& pMousePos->getX() > m_position.getX()
		&& pMousePos->getY() < (m_position.getY() + m_height)
		&& pMousePos->getY() > m_position.getY())
	{
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)
			&& m_bReleased)
		{
			m_currentFrame = CLICKED;
			m_callback(); // call our callback function
			m_bReleased = false;
		}
		else if (!TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_bReleased = true;
			m_currentFrame = MOUSE_OVER;
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}
}

//#include "SDLGameObject.h"

// class LoaderParams;

// class MenuButton : public SDLGameObject
// {
//   public:
//     MenuButton(const LoaderParams* pParams);
//     virtual void drawFrame();
//     virtual void draw(); 
//     virtual void update() {};
//     virtual void clean();  
// };

// enum button_state
// {
//   MOUSE_OUT = 0,
//   MOUSE_OVER = 1,
//   CLICKED = 2
// };//