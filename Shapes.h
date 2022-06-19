#pragma once
#ifndef SHAPES_H
#define SHAPES_H

#include <vector>
#include <array>

namespace Shape
{
	//void Cuboid(const float center[3], float length, float width);
	std::vector< std::array<double, 3>> Cuboid(const std::array<float, 3> center, float scale = 1);
};

#endif