#ifndef __BOARD_H_
#define __BOARD_H_

#include "GameObject.hpp"
#include <set>
#include <vector>

class Board{
private:
	int gridsize;
	int width;
	int height;
	std::vector< std::vector< std::set<GameObject*> > > grid;

public:
	Board(int wndWidth, int wndHeight, int gridsize);
	int getGridSize(){ return gridsize; }
	void setGridSize(int size){ gridsize = size; }

	void insert(int row, int col, GameObject *pObject);
	void remove(int row, int col, GameObject *pObject);
	void processCollision();
	void clear();
};

static Board board(800, 600, 50);

#endif
