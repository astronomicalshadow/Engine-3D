#include "VertexArray.h"

Graph::Graph(sf::PrimitiveType type, int amount)
{
	m_graph = sf::VertexArray(type, amount);
}

sf::VertexArray* Graph::getGraph()
{
	return &m_graph;
}
