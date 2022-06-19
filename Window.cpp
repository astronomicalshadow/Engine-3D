#include "Window.h"

sf::RenderWindow* getWindow()
{
    static sf::RenderWindow window(sf::VideoMode(1600, 900), "3D render");
    return &window;
}
