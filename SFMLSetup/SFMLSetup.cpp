#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <string>

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
		int xPos = 100;
		float lineHeight = 100;

		window.clear(sf::Color::Black); //Clear old frame

		for (int i = 0; i < 10; i++) {
			sf::RectangleShape line(sf::Vector2f(lineHeight, 1));
			line.setPosition(xPos, 100);
			line.rotate(90);
			window.draw(line);
			xPos += 2;
			lineHeight += 25;
		}
		
		//Draw your display
		window.display(); //Tell app that window is done drawing
	}

	//End of application

	return 0;
}
