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
#include <cstdlib>



sf::RectangleShape plot(int len, int x, int y) { //Returns a single drawn line
	sf::RectangleShape line(sf::Vector2f(len, 1));
	line.setPosition(x, y - len);
	line.rotate(90);
	
	return line;
}