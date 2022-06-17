#pragma once
#ifndef OBJ_H
#define OBJ_H

#include "Shapes.h"
#include "Window.h"

class Obj
{
protected:
	std::vector< std::array<double, 3>> m_3D_Coordinates;

	std::vector< std::array<double, 3>> m_2D_ProjectedCoordinates;

public:
	void set_3D_Coordinates(std::vector< std::array<double, 3>> Coordinates_3D);

	void set_2D_Coordinates(std::vector< std::array<double, 3>> Coordinates_2D);

	std::vector< std::array<double, 3>> get_3D_Coordinates();

	std::vector< std::array<double, 3>> get_2D_ProjectedCoordinates();

	//void Cuboid(const float center[3], float length, float width);

	// std::vector<std::tuple<float, float, float>> Cube(const float center[3] = {0, 0, 0}, const float scale = 1.f);
};

#endif


