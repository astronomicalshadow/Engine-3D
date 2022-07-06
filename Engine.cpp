#include "Engine.h"


Engine::E3D::E3D(int FOV)
{

	window = getWindow();

	m_Resolution =
	{
		window->getSize().y,
		window->getSize().x
	};

	m_FOV = FOV;

	m_Z0 = (std::get<1>(m_Resolution) / 2.0) / tan((m_FOV / 2.0) * 3.14159265 / 180);

}

void Engine::E3D::translate(std::unique_ptr<Obj>& Object, std::array<float, 3> Translation)
{
	std::vector< std::array<double, 3>> Translated;

	for (auto& iter : Object->get_3D_Coordinates())
	{
		std::array<double,3> coordinates
		{
				std::get<0>(iter) + Translation[0],
				std::get<1>(iter) - Translation[1],
				std::get<2>(iter) + Translation[2]
		};
		Translated.push_back(coordinates);
	}
	Object->set_3D_Coordinates(Translated);
}

std::vector< std::array<double, 3>> Engine::E3D::rotationCalculation(std::unique_ptr<Obj>& Object, std::array<float, 3> DegreeRotation)
{
	// Degrees into Radian
	double radian[3]
	{
		DegreeRotation[0] * 3.14159265 / 180, // x axis rotation
		DegreeRotation[1] * 3.14159265 / 180, // y axis rotation
		DegreeRotation[2] * 3.14159265 / 180  // z axis rotation
	};

	std::vector< std::array<double, 3>> coordinates;

	for (auto& iter : Object->get_3D_Coordinates()) // fix this -> this will not get the desired result
	{

		// apply rotation matrix 
		// iter = [Obj_Pos.x, Obj_Pos.y, Obj_Pos.z]
		std::array<double, 3> tuple
		{
			// x axis	
			std::get<0>(iter) * cos(radian[2]) * cos(radian[1]) +
			std::get<1>(iter) * (cos(radian[2]) * sin(radian[1]) * sin(radian[0]) - sin(radian[2]) * cos(radian[0])) +
			std::get<2>(iter) * (cos(radian[2]) * sin(radian[1]) * cos(radian[0]) + sin(radian[2]) * sin(radian[0])),

			// y axis
			std::get<0>(iter) * sin(radian[2]) * cos(radian[1]) +
			std::get<1>(iter) * (sin(radian[2]) * sin(radian[1]) * sin(radian[0]) + cos(radian[2]) * cos(radian[0])) +
			std::get<2>(iter) * (sin(radian[2]) * sin(radian[1]) * cos(radian[0]) - cos(radian[2]) * sin(radian[0])),

			// z axis
			std::get<0>(iter) * -sin(radian[1]) +
			std::get<1>(iter) * cos(radian[1]) * sin(radian[0]) +
			std::get<2>(iter) * cos(radian[1]) * cos(radian[0])
		};

		coordinates.push_back(tuple);
	}

	return coordinates;
}

std::vector< std::array<double, 3>> Engine::E3D::applyPerspective(std::unique_ptr<Obj>& Object)
{
	 std::vector< std::array<double, 3>> PerspectivePosition;

	 for (auto& iter : Object->get_3D_Coordinates())
	 {
		 std::array<double, 3> tuple
		 {
			 std::get<0>(iter) * m_Z0 / (m_Z0 + std::get<2>(iter)),

			 std::get<1>(iter) * m_Z0 / (m_Z0 + std::get<2>(iter)),

			 std::get<2>(iter)
		 };

		 PerspectivePosition.push_back(tuple);
	 }

	return PerspectivePosition;
}

