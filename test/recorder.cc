#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;

int main(){
	SoundBuffer buffer;
	SoundBufferRecorder recorder;
	
	recorder.start(44100);
	std::cout << "Press q to quit." << std::endl;
	char cmd;
	std::cin >> cmd;
	while(cmd != 'q'){
		std::cin >> cmd;
	}

	recorder.stop();
	buffer = recorder.getBuffer();
	std::cout << "Samples: " <<  buffer.getSampleCount() << std::endl;
	buffer.saveToFile("save.wav");

	return 0;
}
