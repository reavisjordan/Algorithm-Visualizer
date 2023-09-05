#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <string>
#include "SFMLHelpers.h"
#include <cstdlib>

int main()
{
	//Initialize window
	sf::RenderWindow window(sf::VideoMode(640, 480), "Algorithm Visualizer", sf::Style::Default);
	sf::Event event;


	//Create and populate line (rectangle) vector
	std::vector <sf::RectangleShape> lineVector;
	int xpos = 100;

	int N;
	std::cout << "Enter the size of the vector to be sorted: ";
	std::cin >> N;

	srand(time(0));

	for (int i = 1; i <= N; i++) {
		int randomNum = rand() % N + 1;
		sf::RectangleShape line = plot(randomNum, xpos, 200);
		lineVector.push_back(line);
		xpos += 5;
	}

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
		window.clear(sf::Color::Black);

		for (const sf::RectangleShape& itr : lineVector) {
			window.draw(itr);
		}
		

		
		//Draw your display
		window.display(); //Tell app that window is done drawing
	}

	//End of event loop

	std::cout << "Size of lineVector: " << lineVector.size() << std::endl;

	return 0;
}
