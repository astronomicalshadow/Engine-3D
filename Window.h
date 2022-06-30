#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <array>

//class window
//{
//	std::shared_ptr<sf::RenderWindow> m_window;
//public:
//	window(std::array<int, 2> screensize, std::string title = "");
//	sf::RenderWindow* getWindow(std::array<int, 2> screensize, std::string title = "");
//};

sf::RenderWindow* getWindow(std::array<int, 2> screensize = {1280, 720}, std::string title = "");

#endif
