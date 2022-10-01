#include "Engine.h"
#include "Window.h"
#include "Shapes.h"

int main()
{
    // create window
    sf::RenderWindow* window = getWindow({1280, 720}, "MyWindow"); // this is a horrible implementation, need to fix

    // framerate cap, affects speed of rotation
    window->setFramerateLimit(60);

    // view 
    sf::View Camera(sf::Vector2f(0, 0), sf::Vector2f(89, 50)); // 1.7777:1 ratio (1280/720 = 1.7777)
    window->setView(Camera);

    // math engine
    Engine::E3D E3D(60 /*FOV*/);

    // Object list, every new object gets a unique pointer for their coordinates
    std::unique_ptr<Obj> Cube1(new Obj);

    std::unique_ptr<Obj> Cube2(new Obj);

    // initalization of Obj
    Cube1->set_3D_Coordinates(Shape::createCuboid({ 2, 2, 2 }));

    Cube2->set_3D_Coordinates(Shape::createCuboid({ 2, 2, 2 }));

	E3D.translate({ 0, 0, 0 }); // this method makes everything rotate around the center, added a fix now they fly off into space
    Cube1->translate({ 1, 2, 0 }); // this method fixes x, y translation but z translation broken

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

        Cube2->set_3D_Coordinates(E3D.rotationCalculation(Cube2, { 1, 1, 1 }));

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
