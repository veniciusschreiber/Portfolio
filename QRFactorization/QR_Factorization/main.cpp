#include <iostream>
#include "Math_Ops.h"

int main()
{
	QRFac matrices;

	matrices.formMatrixUp(); //Get A
	
	matrices.computeQMatrix(); //Get Q
	
	matrices.computeRMatrix(); //Get R

	std::cout << "A = QR" << std::endl;

	matrices.printAMatrix(); //Print A

	matrices.printQMatrix(); //Print Q

	matrices.printRMatrix(); //Print R


	return 0;
}