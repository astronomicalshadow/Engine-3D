#include "Window.h"

//window::window(std::array<int, 2> screensize, std::string title)
//{
//    m_window -> &sf::RenderWindow(sf::VideoMode(screensize[0], screensize[1]), title);
//}
//
//sf::RenderWindow* window::getWindow(std::array<int, 2> screensize, std::string title)
//{
//    return &m_window;
//}

sf::RenderWindow* getWindow(std::array<int, 2> screensize, std::string title)
{
	static sf::RenderWindow window(sf::VideoMode(screensize[0], screensize[1]), title);
	return &window;
}
