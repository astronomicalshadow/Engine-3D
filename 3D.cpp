#include "Engine.h"
#include "Window.h"
#include "Shapes.h"

int main()
{
    // create window
    static sf::RenderWindow* window = getWindow();

    // framerate cap, affects speed of rotation
    window->setFramerateLimit(60);

    //// view 
    sf::View Camera(sf::Vector2f(0, 0), sf::Vector2f(50, 40));
    window->setView(Camera);

    // math engine
    Engine::E3D E3D(60);

    // Object list, every new object gets a unique pointer for their coordinates
    std::unique_ptr<Obj> Cube1(new Obj);
    std::unique_ptr<Obj> Cube2(new Obj);

    // initalization of Obj
    Cube1->set_3D_Coordinates(Shape::Cuboid({5, 1, 0}, 2));
    Cube2->set_3D_Coordinates(Shape::Cuboid({ 3, 0, 2 }, 3));

    E3D.translate(Cube1, { 5, 2, 0 }); // still broken

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
        Cube1->set_3D_Coordinates(E3D.rotationCalculation(Cube1, { 1, 1, 1 }));

        Cube1->set_2D_Coordinates(E3D.applyPerspective(Cube1));

        Cube2->set_3D_Coordinates(E3D.rotationCalculation(Cube2, { 1, 1, -1 }));

        Cube2->set_2D_Coordinates(E3D.applyPerspective(Cube2));

        // clear screen for update
        window->clear(sf::Color::White);

        // draw
        Cube1->DrawCuboid();
        Cube2->DrawCuboid();

        // display everything
        window->display();
    }

    return 0;
}
