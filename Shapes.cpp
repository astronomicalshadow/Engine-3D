#include "Shapes.h"

//std::vector< std::tuple<float, float, float>> Shape::Cuboid(const float center[3], float length, float width)
//{
//	// height 
//
//	// width 
//
//	return std::vector< std::tuple<float, float, float>>();
//}

std::vector< std::array<double, 3>> Shape::Cube(const std::array<float, 3> center, float scale)
{
	// center = x, y, z
	std::vector< std::array<double, 3>> CubeCoordinates
	{
		// tuple = x, y, z
		// top half of cube
		{(std::get<0>(center) + 0.5) * scale, (std::get<1>(center) + 0.5) * scale, (std::get<2>(center) + 0.5) * scale},
		{-(std::get<0>(center) + 0.5) * scale, (std::get<1>(center) + 0.5) * scale, (std::get<2>(center) + 0.5) * scale},
		{-(std::get<0>(center) + 0.5) * scale, (std::get<1>(center) + 0.5) * scale, -(std::get<2>(center) + 0.5) * scale},
		{(std::get<0>(center) + 0.5) * scale, (std::get<1>(center) + 0.5) * scale, -(std::get<2>(center) + 0.5) * scale},

		// bottom half
		{(std::get<0>(center) + 0.5) * scale, -(std::get<1>(center) + 0.5) * scale, (std::get<2>(center) + 0.5) * scale},
		{-(std::get<0>(center) + 0.5) * scale, -(std::get<1>(center) + 0.5) * scale, (std::get<2>(center) + 0.5) * scale},
		{-(std::get<0>(center) + 0.5) * scale, -(std::get<1>(center) + 0.5) * scale, -(std::get<2>(center) + 0.5) * scale},
		{(std::get<0>(center) + 0.5) * scale, -(std::get<1>(center) + 0.5) * scale, -(std::get<2>(center) + 0.5) * scale},
	};
	return CubeCoordinates;
}
