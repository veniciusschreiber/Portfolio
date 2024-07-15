#include <iostream>

#include "App_Ops.h"

int main()
{
	MatrixOps matrixOPS;

	matrixOPS.formMatrixUp();

	matrixOPS.gaussianElimination();

	matrixOPS.printMatrixOut();

	return 0;
}