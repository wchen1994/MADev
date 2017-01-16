#ifndef __SCENE_H_
#define __SCENE_H_

#include "Essential.hpp"

class Scene{
public:
	Scene();
	virtual ~Scene();
	virtual Essential::GameState Run() = 0;
};

#endif
