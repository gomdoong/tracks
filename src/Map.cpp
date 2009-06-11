/**
 * @file Map.cpp
 * Map 클래스 구현
 *
 * @author walker(jeonyb@gmail.com)
 */
#include <stdlib.h>
#include <stdexcept>

#include "Cell.h"
#include "Map.h"

Map::Map(const int aWidth, const int aHeight, const float aAirResist)
: width(aWidth), height(aHeight), airResist(aAirResist)
{
	if(width <= 0) {
		throw std::invalid_argument("width");
	} else if(height <= 0) {
		throw std::invalid_argument("height");
	}

	cells = new Cell[width * height];

	for(int x=0; x<width; x++) {
		for(int y=0; y<height; y++) {
			getCell(x, y).setAdjacentCells(
				y == 0          ? NULL : &getCell(x, y-1),
				y == height - 1 ? NULL : &getCell(x, y+1),
				x == width - 1  ? NULL : &getCell(x+1, y),
				x == 0          ? NULL : &getCell(x-1, y)
			);
		}
	}
}

Map::~Map()
{
	delete[] cells;
}

Cell& Map::getCell(const int x, const int y)
{
	if(x < 0 || x >= width) {
		throw std::out_of_range("x");
	} else if(y < 0 || y >= height) {
		throw std::out_of_range("y");
	}
	return cells[x + width*y];
}

