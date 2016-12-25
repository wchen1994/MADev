#include <SFML/Audio.hpp>
#include <iostream>

int main(){
	std::string filename;
	sf::Music player;
	std::cout << "Please input file to play." << std::endl;
	std::cin >> filename;
	int rc = player.openFromFile(filename);
	if (rc){
		player.play();
		while(player.Playing){
			sf::sleep(sf::milliseconds(10));
		}
	}

	return 0;
}
