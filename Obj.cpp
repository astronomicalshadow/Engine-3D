#include "Obj.h"

void Obj::set_3D_Coordinates(std::vector< std::array<double, 3>> Coordinates_3D)
{
	m_3D_Coordinates.clear();

	for (auto& iter : Coordinates_3D)
	{
		m_3D_Coordinates.push_back(iter);
	}
}

void Obj::set_2D_Coordinates(std::vector< std::array<double, 3>> Coordinates_2D)
{
	m_2D_ProjectedCoordinates.clear();

	for (auto& iter : Coordinates_2D)
	{
		m_2D_ProjectedCoordinates.push_back(iter);
	}

}

std::vector< std::array<double, 3>> Obj::get_3D_Coordinates()
{
	return m_3D_Coordinates;
}

std::vector< std::array<double, 3>> Obj::get_2D_ProjectedCoordinates()
{
	return m_2D_ProjectedCoordinates;
}

//std::vector< std::tuple<float, float, float>> Shape::Cuboid(const float center[3], float length, float width)
//{
//	// height 
//
//	// width 
//
//	return std::vector< std::tuple<float, float, float>>();
//}