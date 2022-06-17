#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <cmath>
#include "Obj.h"

namespace Engine
{
	class E3D : public Obj
	{
		sf::RenderWindow* window;

		int m_FOV;

		double m_Z0;

		std::array<unsigned int, 2> m_Resolution;
	
		/*sf::Clock m_Clock;*/

	public:

		E3D(int FOV = 90);

		void translate(const std::array<float, 3> Translation);
	
		std::vector< std::array<double, 3>> rotationCalculation(std::array<float, 3> DegreeRotation);
	
		std::vector< std::array<double, 3>> applyPerspective();

		void update();
	};
}

#endif