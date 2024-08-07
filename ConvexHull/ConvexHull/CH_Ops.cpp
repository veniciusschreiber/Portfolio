#include "CH_Ops.h"

//Behavior
int ConvexHull::computeConvexHull()
{
	unsigned int xTemp;

	std::sort(std::begin(points), std::end(points));

	convexHullIndex.push(points.front()); //store the leftmost vector

	xTemp = points[0].at(0);

	for (int i = 1; i < ARRAY_VECTOR_SET_SIZE; i++)
	{
		//find the lowest vector for each x until the end of the list
		if (xTemp != points[i].at(0))
		{
			convexHullIndex.push(points[i]);

			xTemp = points[i].at(0);
		}
	}

	xTemp = points[0].at(0); // forcing x be diff than the last vector on the list

	for (int j = (ARRAY_VECTOR_SET_SIZE - 1); j >= 1; j--)
	{
		//find the highest vector for each x until the begin of the list
		if (xTemp != points[j].at(0))
		{
			convexHullIndex.push(points[j]);

			xTemp = points[j].at(0);
		}
	}

	return 0;
}

int ConvexHull::fillUpVectorSet()
{
	
	unsigned int userInput;

	for(int i = 0; i < ARRAY_VECTOR_SET_SIZE ; i++)
	{
		for(int j = 0; j <= 1; j++)
		{
			std::cout << "Enter " << (j + 1)  << " value for the " << (i + 1) << " out of 12 vector" << std::endl;

			std::cin >> userInput;

			points[i][j] = userInput;
		}
	}

	return 0;
}

int ConvexHull::printOutConvexHull()
{
	
	std::cout << "convex hull is equal to " << std::endl;

	for(int i = 0; i < ARRAY_VECTOR_SET_SIZE; i++)
	{
		std::cout << "(" << convexHullIndex.front().at(0) << ", "
			<< convexHullIndex.front().at(1) << ")";

		convexHullIndex.push(convexHullIndex.front());

		convexHullIndex.pop();
	}
	
	return 0;
}