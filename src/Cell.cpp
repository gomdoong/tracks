/**
 * @file Cell.cpp
 * Cell 클래스 구현
 *
 * @author walker(jeonyb@gmail.com)
 */
#include <stdlib.h>
#include <stdexcept>

#include "NSEW.h"
#include "Cell.h"

Cell::Cell()
: pTrack(NULL), northern(NULL), southern(NULL), eastern(NULL), western(NULL)
{
}

Cell::~Cell()
{
}

void Cell::setTrack(const Track& track)
{
	pTrack = &track;
}

const Track& Cell::getTrack()
{
	if(pTrack == NULL) throw std::bad_exception();
	return *pTrack;
}

bool Cell::hasTrack()
{
	return pTrack;
}

void Cell::removeTrack()
{
	pTrack = NULL;
}

void Cell::setAdjacentCells(const Cell* const aNorthern,
                            const Cell* const aSouthern,
                            const Cell* const aEastern,
                            const Cell* const aWestern)
{
	northern = aNorthern;
	southern = aSouthern;
	eastern = aEastern;
	western = aWestern;
}

const Cell* Cell::getAdjacentCell(const NSEW& where)
{
	switch(where.getValue()) {
	case NSEW::VALUE_NORTH: return northern;
	case NSEW::VALUE_SOUTH: return southern;
	case NSEW::VALUE_EAST: return eastern;
	case NSEW::VALUE_WEST: default: return western;
	}
}
