#include "App_Ops.h"
#include "Constant.h"

//encaps
float* MatrixOps::getAMatrix()
{
	return { *this->AMatrix };
}

void MatrixOps::setAMatrix(int setMatrixParam, int rowParam, int columnParam)
{
	AMatrix[ rowParam ][ columnParam ] = setMatrixParam;
}

//behavior
int MatrixOps::gaussianElimination()
{
	float divisor = 0.0f;
	unsigned int rowA;
	unsigned int rowB;
	unsigned int column;

	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (j == 0) 
			{
				rowA = i == 2 ? 2 : i + 1;
				rowB = i - 1 == -1 ? 0 : i - 1;
				column = i == 2 ? 1 : 0;

				divisor = AMatrix[rowA][column] / AMatrix[rowB][column];
			} 
			AMatrix[rowA][j] = AMatrix[rowA][j] - (AMatrix[rowB][j] * divisor);
		}
	}
	return 0;
}

int MatrixOps::formMatrixUp()
{
	int a;

	for (int i = 0; i <= MATRIX_M_ENTRIES; i++)
	{
		for (int j = 0; j <= MATRIX_N_ENTRIES; j++)
		{
			std::cout << "Enter the " << j + 1 << " number for the " << i + 1 << " row ";

			std::cin >> a;

			setAMatrix(a, i, j);
		}
	}
	return 0;
}

int MatrixOps::printMatrixOut()
{
	std::cout << "\n" << "The Row Echelon Form of A is :" << std::endl;

	for (int i = 0; i <= MATRIX_NUMBER_OF_ENTRIES; i++)
	{
		std::cout << *(getAMatrix() + i) << ",";

		if (i == 2 || i == 5 || i == MATRIX_NUMBER_OF_ENTRIES)
		{
			std::cout << std::endl;
		}
	}

	return 0;
}