#include "Engine.h"
#include "Window.h"
#include "Shapes.h"

int main()
{
    // create window
    static sf::RenderWindow* window = getWindow();

    // framerate cap 
    window->setFramerateLimit(60);

    // view 
    sf::View Camera(sf::Vector2f(0, 0), sf::Vector2f(60, 50));
    window->setView(Camera);

    // math engine
    Engine::E3D E3D;

    // Object list, every new object gets a unique pointer for their coordinates
    std::unique_ptr<Obj> Cube1(new Obj);

    // initalization of Obj
    Cube1->set_3D_Coordinates(Shape::Cuboid({5, 1, 0}, 2));

    while (window->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        while (window->pollEvent(event))
        {
            // "close requested" event: close the window
            if (event.type == sf::Event::Closed)
            {
                window->close();
            } 

        }

        // calculation before clearing screen in case of blinking due to slow cpu
        Cube1->set_3D_Coordinates(E3D.rotationCalculation(Cube1, { 1, 0, 0 }));

        Cube1->set_2D_Coordinates(E3D.applyPerspective(Cube1));

        // clear screen for update
        window->clear(sf::Color::White);

        // everything else happens here
        Cube1->DrawCuboid();

        // display everything
        window->display();
    }

    return 0;
}
