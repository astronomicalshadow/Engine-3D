#include "Shapes.h"

std::vector< std::array<double, 3>> Shape::createCuboid(const std::array<float, 3> size, float scale)
{
	// size = x, y, z
	std::vector< std::array<double, 3>> CuboidCoordinates
	{
		// tuple = x, y, z
		// top half of cuboid
		{(std::get<0>(size) + 0.5) * scale, (std::get<1>(size) + 0.5) * scale, (std::get<2>(size) + 0.5) * scale},
		{-(std::get<0>(size) + 0.5) * scale, (std::get<1>(size) + 0.5) * scale, (std::get<2>(size) + 0.5) * scale},
		{-(std::get<0>(size) + 0.5) * scale, (std::get<1>(size) + 0.5) * scale, -(std::get<2>(size) + 0.5) * scale},
		{(std::get<0>(size) + 0.5) * scale, (std::get<1>(size) + 0.5) * scale, -(std::get<2>(size) + 0.5) * scale},

		// bottom half
		{(std::get<0>(size) + 0.5) * scale, -(std::get<1>(size) + 0.5) * scale, (std::get<2>(size) + 0.5) * scale},
		{-(std::get<0>(size) + 0.5) * scale, -(std::get<1>(size) + 0.5) * scale, (std::get<2>(size) + 0.5) * scale},
		{-(std::get<0>(size) + 0.5) * scale, -(std::get<1>(size) + 0.5) * scale, -(std::get<2>(size) + 0.5) * scale},
		{(std::get<0>(size) + 0.5) * scale, -(std::get<1>(size) + 0.5) * scale, -(std::get<2>(size) + 0.5) * scale},
	};
	return CuboidCoordinates;
}
