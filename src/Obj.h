#pragma once
#ifndef OBJ_H
#define OBJ_H

#include "Shapes.h"
#include "Window.h"
#include <stdexcept>

class Obj
{
private:
	sf::RenderWindow* m_window;

	std::vector<std::array<double, 3>> m_3D_Coordinates;

	std::vector<std::array<double, 3>> m_2D_ProjectedCoordinates;
	
	std::array<double, 3> m_translation{ 0, 0, 0 };

public:
	Obj();

	void set_3D_Coordinates(const std::vector<std::array<double, 3>>& Coordinates_3D);

	void set_2D_Coordinates(const std::vector<std::array<double, 3>>& Coordinates_2D);

	void translate(std::array<double, 3> translate);

	std::vector<std::array<double, 3>> get_3D_Coordinates();

	std::vector<std::array<double, 3>> get_2D_ProjectedCoordinates();

	void DrawCuboid();
};

#endif


