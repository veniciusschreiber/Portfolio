#include <iostream>

#include "Matrices_Ops.h"

int main()
{
	EigenStuff eigenOps;

	eigenOps.fillEverythingUp();

	eigenOps.printMatrixA();

	eigenOps.multiplyLambdaTimesId();

	eigenOps.subtractAminusResult();

	eigenOps.rowReduceA();

	eigenOps.checkLambdaIsEigenValue();

	return 0;
}