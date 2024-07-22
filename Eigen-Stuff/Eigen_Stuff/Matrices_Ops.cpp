#include <iostream>
#include <string>

#include "Matrices_Ops.h"

//Encaps

int EigenStuff::getLambda()
{
	return lambda;
}

void EigenStuff::setLambda(int lambdaParam)
{
	this->lambda = lambdaParam;
}

float* EigenStuff::getMatrixA()
{
	return { *matrixA };
}

void EigenStuff::setMatrixA(float matrixAParam, int colParam, int rowParam)
{
	matrixA[colParam][rowParam] = matrixAParam;
}

int* EigenStuff::getMatrixId()
{
	return { *matrixID };
}

//Behavior

int EigenStuff::fillEverythingUp()
{
	int userValue = 0;

	for (int i = 0; i <= 1; i++)//m
	{
		for (int j = 0; j <= 1; j++)//n
		{
			std::cout << "Type the " << (j + 1) << " value for the " << (i + 1) << " row: ";

			std::cin >> userValue;

			setMatrixA(userValue, i, j);
		}
	}

	std::cout << "\n";

	std::cout << "Type the value to be checked as eigenvalue of A: ";

	std::cin >> lambda;

	return 0;
}

int EigenStuff::printMatrixA()
{
	
	std::cout << "\n";

	std::cout << "A = " << std::endl;

	for(int i = 0; i <= 1; i++)//m
	{
		for(int j = 0; j <= 1; j++)//n
		{
			if (i == 1 && j == 0) { std::cout << std::endl; }

			std::cout << matrixA[i][j] << ", ";
		}
	}

	std::cout << "\n";

	return 0;
}

int EigenStuff::multiplyLambdaTimesId()
{
	
	for(int i= 0 ; i <= 1; i++)//m
	{
		for(int j = 0; j <= 1; j++)
		{
			matrixID[i][j] = lambda * matrixID[i][j];
		}
	}

	return 0;
}

int EigenStuff::subtractAminusResult()
{
	for (int i = 0; i <= 1; i++)//m
	{
		for (int j = 0; j <= 1; j++)//n
		{
			matrixA[i][j] = matrixA[i][j] - matrixID[i][j];
		}
	}

	return 0;
}

int EigenStuff::rowReduceA()
{
	float result = 0;

	int i = 1;
	
	for (int j = 0; j <= 1; j++)//n
	{
		//divide
		if (j == 0)
		{
			result = matrixA[1][0] / matrixA[0][0];
		}
		
		//multiplica e subtrai
		matrixA[i][j] = matrixA[i][j] - (matrixA[i - 1][j] * result);
	}
	
	return 0;
}

int EigenStuff::checkLambdaIsEigenValue()
{
	std::cout << "\n";

	matrixA[1][1] == 0 ? std::cout << lambda << " is a eigenvalue of A"
					   : std::cout << lambda << " is NOT a eigenvalue of A";

	std::cout << "\n";

	return 0;
}

