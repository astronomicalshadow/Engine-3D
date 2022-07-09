#include "Obj.h"

Obj::Obj()
{
	m_window = getWindow();
}

void Obj::set_3D_Coordinates(const std::vector< std::array<double, 3>>& Coordinates_3D)
{
	m_3D_Coordinates.clear();

	for (auto& iter : Coordinates_3D)
	{
		m_3D_Coordinates.push_back(iter);
	}
}

void Obj::set_2D_Coordinates(const std::vector< std::array<double, 3>>& Coordinates_2D)
{
	m_2D_ProjectedCoordinates.clear();

	for (auto& iter : Coordinates_2D)
	{
		m_2D_ProjectedCoordinates.push_back(iter);
	}

}

void Obj::translate(std::array<double, 3> translate)
{
	m_translation = translate;
}

std::vector< std::array<double, 3>> Obj::get_3D_Coordinates()
{
	return m_3D_Coordinates;
}

std::vector< std::array<double, 3>> Obj::get_2D_ProjectedCoordinates()
{
	return m_2D_ProjectedCoordinates;
}

void Obj::DrawCuboid()
{
	// make sure its a cuboid before drawing
	if (m_2D_ProjectedCoordinates.size() != 8)
	{
		throw std::invalid_argument("Cubiod object does not have 8 vertices");
	}
	// drawing
	sf::Vertex Cuboid[]
	{
		// top
		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[0][0] + m_translation[0], m_2D_ProjectedCoordinates[0][1] + m_translation[1]), sf::Color::Black),
		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[1][0] + m_translation[0], m_2D_ProjectedCoordinates[1][1] + m_translation[1]), sf::Color::Black),

		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[1][0] + m_translation[0], m_2D_ProjectedCoordinates[1][1] + m_translation[1]), sf::Color::Black),
		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[2][0] + m_translation[0], m_2D_ProjectedCoordinates[2][1] + m_translation[1]), sf::Color::Black),

		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[2][0] + m_translation[0], m_2D_ProjectedCoordinates[2][1] + m_translation[1]), sf::Color::Black),
		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[3][0] + m_translation[0], m_2D_ProjectedCoordinates[3][1] + m_translation[1]), sf::Color::Black),

		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[3][0] + m_translation[0], m_2D_ProjectedCoordinates[3][1] + m_translation[1]), sf::Color::Black),
		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[0][0] + m_translation[0], m_2D_ProjectedCoordinates[0][1] + m_translation[1]), sf::Color::Black),

		// bottom
		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[4][0] + m_translation[0], m_2D_ProjectedCoordinates[4][1] + m_translation[1]), sf::Color::Black),
		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[5][0] + m_translation[0], m_2D_ProjectedCoordinates[5][1] + m_translation[1]), sf::Color::Black),

		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[5][0] + m_translation[0], m_2D_ProjectedCoordinates[5][1] + m_translation[1]), sf::Color::Black),
		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[6][0] + m_translation[0], m_2D_ProjectedCoordinates[6][1] + m_translation[1]), sf::Color::Black),

		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[6][0] + m_translation[0], m_2D_ProjectedCoordinates[6][1] + m_translation[1]), sf::Color::Black),
		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[7][0] + m_translation[0], m_2D_ProjectedCoordinates[7][1] + m_translation[1]), sf::Color::Black),

		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[7][0] + m_translation[0], m_2D_ProjectedCoordinates[7][1] + m_translation[1]), sf::Color::Black),
		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[4][0] + m_translation[0], m_2D_ProjectedCoordinates[4][1] + m_translation[1]), sf::Color::Black),

		// connecting top + bottom
		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[0][0] + m_translation[0], m_2D_ProjectedCoordinates[0][1] + m_translation[1]), sf::Color::Black),
		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[4][0] + m_translation[0], m_2D_ProjectedCoordinates[4][1] + m_translation[1]), sf::Color::Black),

		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[1][0] + m_translation[0], m_2D_ProjectedCoordinates[1][1] + m_translation[1]), sf::Color::Black),
		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[5][0] + m_translation[0], m_2D_ProjectedCoordinates[5][1] + m_translation[1]), sf::Color::Black),

		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[2][0] + m_translation[0], m_2D_ProjectedCoordinates[2][1] + m_translation[1]), sf::Color::Black),
		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[6][0] + m_translation[0], m_2D_ProjectedCoordinates[6][1] + m_translation[1]), sf::Color::Black),

		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[3][0] + m_translation[0], m_2D_ProjectedCoordinates[3][1] + m_translation[1]), sf::Color::Black),
		sf::Vertex(sf::Vector2f(m_2D_ProjectedCoordinates[7][0] + m_translation[0], m_2D_ProjectedCoordinates[7][1] + m_translation[1]), sf::Color::Black),
	};

	m_window->draw(Cuboid, 24, sf::Lines);
}
