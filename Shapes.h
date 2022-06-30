#pragma once
#ifndef SHAPES_H
#define SHAPES_H

#include <vector>
#include <array>

namespace Shape
{
	std::vector< std::array<double, 3>> createCuboid(const std::array<float, 3> size, float scale = 1);
};

#endif