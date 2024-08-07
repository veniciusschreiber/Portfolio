#pragma once

#include <queue>
#include <array>
#include <algorithm>
#include <iostream>

#include "Constant.h"

class ConvexHull
{
private:

	std::array<std::array<int, 2>, ARRAY_VECTOR_SET_SIZE> points =	{ {	} };

	std::queue< std::array<int, 2> > convexHullIndex;

public:

	ConvexHull()
	{}
	~ConvexHull()
	{}
	
	//Behavior
	int computeConvexHull();

	int fillUpVectorSet();

	int printOutConvexHull();
};


