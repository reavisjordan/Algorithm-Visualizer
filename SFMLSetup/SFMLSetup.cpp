#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main()
{
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

		//Update
		
		//Render
		window.clear(sf::Color::Blue); //Clear old frame

		//Draw your display

		window.display(); //Tell app that window is done drawing
	}

	//End of application

	return 0;
}
