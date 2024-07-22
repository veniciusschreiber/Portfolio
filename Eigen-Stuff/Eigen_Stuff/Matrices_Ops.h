#pragma once


class EigenStuff
{
private:

	int lambda;
	float matrixA[2][2] = {};
	int matrixID[2][2] = {
		{1,0},
		{0,1}
	};

public:
	EigenStuff() :lambda(0)
	{}

	~EigenStuff()
	{}

	//Encaps

	int getLambda();

	void setLambda( int lambdaParam);

	float* getMatrixA();

	void setMatrixA(float matrixAParam, int colParam, int rowParam);

	int* getMatrixId();

	//Behavior

	int fillEverythingUp();

	int printMatrixA();

	int multiplyLambdaTimesId();

	int subtractAminusResult();

	int rowReduceA();

	int checkLambdaIsEigenValue();
};
