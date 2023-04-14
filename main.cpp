
#include <iostream>
#include "Calculator.h"


int main() {
	Calculator cal1, cal2, cal3;
	//test odejmowania i mnozenia;

	std::cout << cal1.Substract(2, 5) << "\n";
	std::cout << cal2.Multiply(2, 6) << "\n";
	std::cout << cal1.GetResult() << ", " << cal2.GetResult() << "\n";

	double x0, x1; 
	std::cout << cal3.Roots(0, 2, 4, x0, x1);
	std::cout << "x0: " << x0 << ", x1: " << x1 << "\n";
	

	

}