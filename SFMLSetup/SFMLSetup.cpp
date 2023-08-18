#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main()
{
	//Window
	sf::RenderWindow window(sf::VideoMode(640, 480), "Algorithm Visualizer", sf::Style::Titlebar | sf::Style::Close);
	sf::Event ev;

	sf::Clock clock;

	sf::Time elapsed = clock.getElapsedTime();

	//Game loop
	while (window.isOpen()) {


		//Event polling
		while (window.pollEvent(ev)) {
			switch (ev.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::Escape)
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

	std::cout << "Total time: " << elapsed.asSeconds() << std::endl;

	//End of application

	return 0;
}
