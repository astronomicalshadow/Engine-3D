#include "Window.h"

sf::RenderWindow* getWindow()
{
    static sf::RenderWindow window(sf::VideoMode(1280, 720), "3D render");
    return &window;
}
