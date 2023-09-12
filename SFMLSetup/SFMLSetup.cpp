#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <ranges>
#include <ctime>
#include "SFMLHelpers.h"

int main()
{
	//Initialize window
	sf::RenderWindow window(sf::VideoMode(640, 480), "Algorithm Visualizer", sf::Style::Default);


	//Create the line (rectangle) vector
	std::vector <sf::RectangleShape> lineVector;
	
	//Defines the number of obj's to be sorted 
	int N;
	std::cout << "Enter the number of items to be sorted: ";
	std::cin >> N;


	//Populates and shuffles line vector in preparation for sorting
	int xpos = 100;
	for (int i = 0; i < N; i++) {
		sf::RectangleShape line = plot(i + 1, xpos + i * 5, 200);  
		lineVector.push_back(line);
	}
	

	//Event loop
	while (window.isOpen()) {
		sf::Event event;
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

		for (auto& itr : lineVector) {
			window.draw(itr);
		}
		
		//Draw your display
		window.display(); //Tell app that window is done drawing
	}

	//End of event loop
	return 0;
}
