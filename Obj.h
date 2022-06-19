#pragma once
#ifndef OBJ_H
#define OBJ_H

#include "Shapes.h"
#include "Window.h"
#include <iostream>

class Obj
{
private:
	sf::RenderWindow* window;

	std::vector< std::array<double, 3>> m_3D_Coordinates;

	std::vector< std::array<double, 3>> m_2D_ProjectedCoordinates;

public:
	Obj();

	void set_3D_Coordinates(std::vector< std::array<double, 3>> Coordinates_3D);

	void set_2D_Coordinates(std::vector< std::array<double, 3>> Coordinates_2D);

	std::vector< std::array<double, 3>> get_3D_Coordinates();

	std::vector< std::array<double, 3>> get_2D_ProjectedCoordinates();

	void DrawCuboid();
};

#endif


