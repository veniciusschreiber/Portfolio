#pragma once

#include <iostream>
#include <vector>
#include <string>

class QRFac
{
private:
	float AMatrix[3][3] = {};
	float QMatrix[3][3] = {};
	float RMatrix[3][3] = {};

public:

	QRFac()
	{}

	~QRFac()
	{}
	
	//Encaps
	float* getAMatrix();
	void setAMatrix(float setAMatrixParam, int rowParam, int columnParam);

	float* getQMatrix();
	float* getRMatrix();

	//Behavior
	int formMatrixUp();

	int printAMatrix();

	int printQMatrix();

	int printRMatrix();

	//R

	int computeRMatrix();

	float computeAQ(int colAParam, int colQParam);
	
	//Q

	int computeQMatrix();

	std::vector<float> computeVectorQHat(int colParam);

	std::vector<float> calculateVectorNorm(int colParam);

};
