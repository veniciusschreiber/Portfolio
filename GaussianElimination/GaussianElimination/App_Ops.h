#pragma once

#include <iostream>



class MatrixOps
{
private:
	float AMatrix[3][3]{};

public:
	
	MatrixOps()
	{}
	~MatrixOps()
	{}

	//encaps

	float* getAMatrix();
	void setAMatrix(int setMatrixParam, int rowParam, int columnParam);

	//behavior

	int gaussianElimination();
	int formMatrixUp();
	int printMatrixOut();

};
