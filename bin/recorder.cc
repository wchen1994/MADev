#include "Recorder.h"

int main(){
	Recorder recorder;
	recorder.SetSaveDir("save.wav");
	recorder.Record();
	
	std::cout << "Press q to quit." << std::endl;
	char cmd;
	std::cin >> cmd;
	while(cmd != 'q'){
		std::cin >> cmd;
	}

	recorder.Stop();
	recorder.Save();

	return 0;
}
