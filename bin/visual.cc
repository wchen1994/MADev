#include <SFML/Graphics.hpp>
#include <unistd.h>

int main(){
	sf::RenderWindow window(sf::VideoMode(640,480), "WaveVisual");

	while(window.isOpen()){

		sf::Event even;
		while(window.pollEvent(even)){
			if(even.type == sf::Event::Closed){
				window.close();
			}
		}

		window.clear(sf::Color::Black);
		window.display();
	}

	return 0;
}
