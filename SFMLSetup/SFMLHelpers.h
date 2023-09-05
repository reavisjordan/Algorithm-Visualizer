#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <string>

sf::RectangleShape plot(int height, int x, int y) { //Height of line, x position, y position
	sf::RectangleShape line(sf::Vector2f(height, 1));
	line.setPosition(x, y);
	line.rotate(90);

	return line;
}