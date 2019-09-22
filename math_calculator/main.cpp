#include <iostream>
#include "Complex.h"

int main()
{
	slmath::Complex<int> myNum(2, 3);
	slmath::Complex<int> myNum2(4, 7);
	slmath::Complex<int> myNum3 = myNum + myNum2;
	myNum = myNum.conjugate();
	int userInput;

	std::cout << "Entry point..." << std::endl;
	std::cout << "Abs: " << myNum3.real() << ", Arg: " << myNum3.imaginary() << std::endl;
	std::cout << "Abs: " << myNum3.absolute() << ", Arg: " << myNum3.argument() << std::endl;
	std::cin >> userInput;
	std::cout << userInput;

	return EXIT_SUCCESS;
}