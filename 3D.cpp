#include "Engine.h"
#include "Window.h"
#include "Shapes.h"

int main()
{
    // sf::RenderWindow window(sf::VideoMode(1280, 720), "3D render");
    sf::RenderWindow* window = getWindow();

    window->setFramerateLimit(60);

    sf::View Camera(sf::Vector2f(0, 0), sf::Vector2f(30, 20));
    window->setView(Camera);

    Engine::E3D E3D;

    E3D.set_3D_Coordinates(Shape::Cube({0, 0, 0}, 10));

    while (window->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window->close();
            } 

        }

        window->clear(sf::Color::White);

        E3D.update();

        window->display();
        
    }
    return 0;
}
