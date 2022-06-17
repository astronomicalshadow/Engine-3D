#include "VertexArray.h"

sf::VertexArray* getGraph()
{
	static sf::VertexArray Graph(sf::LinesStrip, 8);
	return &Graph;
}
