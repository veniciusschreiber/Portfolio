#include <iostream>

#include "CH_Ops.h"

int main()
{

	ConvexHull newConvexHull;

	newConvexHull.fillUpVectorSet();

	newConvexHull.computeConvexHull();

	newConvexHull.printOutConvexHull();

	return 0;
}