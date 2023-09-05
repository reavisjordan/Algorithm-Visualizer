#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <string>

sf::RectangleShape plot(float height, int x, int y) { //Height of line, x position, y position
	sf::RectangleShape line(sf::Vector2f(height, 1));
	line.setPosition(x, y);
	line.rotate(90);

	return line;
}

int main()
{
	//Create an array of lines (rectangles)
	std::vector<sf::RectangleShape> lineVector;

	//Window
	sf::RenderWindow window(sf::VideoMode(640, 480), "Algorithm Visualizer", sf::Style::Default);
	sf::Event event;

	//Event loop
	while (window.isOpen()) {


		//Event polling
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
				break;
			}
		}
				
		//Render
		sf::RectangleShape line = plot(150.f, 100, 100);
		window.draw(line);
		
		//Draw your display
		window.display(); //Tell app that window is done drawing
	}

	//End of application

	return 0;
}
