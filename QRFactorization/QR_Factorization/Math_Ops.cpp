#include <vector>
#include "Math_Ops.h"
#include "Constant.h"

//Encaps
float* QRFac::getAMatrix()
{
	return { *AMatrix };
}

void QRFac::setAMatrix(float setAMatrixParam, int rowParam, int columnParam)
{
	this->AMatrix[rowParam][columnParam] = setAMatrixParam;
}

float* QRFac::getQMatrix()
{
	return { *QMatrix };
}

float* QRFac::getRMatrix()
{
	return { *RMatrix };
}

//Behavior
int QRFac::formMatrixUp()
{
	unsigned int a;

	for (int i = 0; i <= MATRIX_M_AMOUNT; i++)
	{
		for (int j = 0; j <= MATRIX_N_AMOUNT; j++)
		{
			std::cout << "Type the " << j + 1 << " component of " << i + 1 << " row: ";
			std::cin >> a;

			setAMatrix( a, i, j );
		}
	}

	return 0;
}

int QRFac::printAMatrix()
{
	std::cout << "\n";

	std::cout << "A = " << std::endl;

	for(int i = 0; i <= MATRIX_ELEMENTS_AMOUNT; i++)
	{
		std::cout << *( getAMatrix() + i ) << ", ";
		
		if (i == 2 || i == 5 || i == MATRIX_ELEMENTS_AMOUNT )
		{
			std::cout << std::endl;
		}
	}
	return 0;
}

int QRFac::printQMatrix()
{
	std::cout << "\n";

	std::cout << "Q = " << std::endl;

	for (int i = 0; i <= MATRIX_ELEMENTS_AMOUNT; i++)
	{
		std::cout << *(getQMatrix() + i) << ", ";

		if (i == 2 || i == 5 || i == MATRIX_ELEMENTS_AMOUNT)
		{
			std::cout << std::endl;
		}
	}

	return 0;
}

int QRFac::printRMatrix()
{
	std::cout << "\n";

	std::cout << "R = " << std::endl;

	for (int i = 0; i <= MATRIX_ELEMENTS_AMOUNT; i++)
	{
		
		std::cout << std::to_string( *(getRMatrix() + i) ) << ", ";

		if (i == 2 || i == 5 || i == MATRIX_ELEMENTS_AMOUNT)
		{
			std::cout << std::endl;
		}
	}

	return 0;
}

//R

int QRFac::computeRMatrix()
{
	std::vector<int> contador = { 0,1,2 };
	
	for (int i = 0; i <= 2; i++)
	{
		for (int j : contador)
		{
			RMatrix[i][j] = computeAQ(j, i);
		}
		
		std::cout << std::endl;

		contador.erase(contador.begin());
	}
	return 0;
}

float QRFac::computeAQ(int colAParam, int colQParam)
{
	float linearCombination = 0.0f;

	for(int i = 0; i <= 2; i++)
	{
		linearCombination = linearCombination + (AMatrix[i][colAParam] * QMatrix[i][colQParam]);
	}
	return linearCombination;
}

//Q

int QRFac::computeQMatrix()
{
	std::vector<float> columnVector;

	for (int i = 0; i <= 2; i++)//n
	{
		if(i==0)
		{
			for(int a = 0; a <= 2; a++)
			{
				QMatrix[a][i] = AMatrix[a][i];
			}
		}

		for(int t = 1; t <= i; t++)//how many times will compute "an - (an.qn)qn"
		{
			columnVector = { computeVectorQHat(i) };
		}

		if(i != 0)//to store qn-hat temporaly on QMatrix
		{
			for (int t = 0; t <= 2; t++)
			{
				QMatrix[t][i] = columnVector.at(t);
			}
		}
		
		columnVector = calculateVectorNorm(i);

		for(int j = 0; j <= 2 ; j++)//m
		{
			QMatrix[j][i] = columnVector.at(j);
		}

		columnVector.clear();
	}

	return 0;
}

std::vector<float> QRFac::computeVectorQHat(int colParam)
{
	std::vector<float> q_hat;

	//formulae to compute "an - (an.qn)qn"

	//result = (anqn)
	for(int j = 0; j < colParam; j++)
	{
		for (int i = 0; i <= 2; i++)
		{
			q_hat.push_back(AMatrix[i][colParam] * QMatrix[i][j]);
		}

		//(result)qn
		
		for (int i = 0; i <= 2; i++)
		{
			q_hat.at(i) = q_hat.at(i) * QMatrix[i][j];
		}

		//an - result
		for (int i = 0; i <= 2; i++)
		{
			q_hat.at(i) = AMatrix[i][colParam] - q_hat.at(i);
		}
	}
	
	return q_hat;
}

std::vector<float> QRFac::calculateVectorNorm(int colParam)
{
	std::vector<float> vectorColumn;
	float result;

	if (colParam == 0)
	{
		result = (pow(AMatrix[0][colParam], 2)
			+ pow(AMatrix[1][colParam], 2)
			+ pow(AMatrix[2][colParam], 2));
	}
	else
	{
		result = (pow(QMatrix[0][colParam], 2)
			+ pow(QMatrix[1][colParam], 2)
			+ pow(QMatrix[2][colParam], 2));
	}

	result = sqrt(result);

	for(int i = 0; i <= 2; i++)
	{
		vectorColumn.push_back( QMatrix[i][colParam] / result);
	}
	
	return vectorColumn;
}
