/*
A touhou like game
*/

#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>

int main(){
	sf::RenderWindow wnd(sf::VideoMode(800,600), "GAME");
	wnd.setFramerateLimit(60);

	sf::CircleShape ball(50);
	ball.setFillColor(sf::Color(100,100,255));

	while(wnd.isOpen()){
		sf::Event event;
		while(wnd.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				wnd.close();
		}
		wnd.clear();
		wnd.draw(ball);
		wnd.display();
	}

	return 0;
}
