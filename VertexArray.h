#pragma once
#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include <SFML/Graphics.hpp>

class Graph
{
	sf::VertexArray m_graph;
public:
	Graph(sf::PrimitiveType type, int amount);

	sf::VertexArray* getGraph();
};


#endif