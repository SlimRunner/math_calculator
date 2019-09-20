#include <iostream>
#include "Complex.h"

int main()
{
	slmath::Complex<int> myNum(2, 3);
	myNum = myNum.conjugate();
	int userInput;

	std::cout << "Entry point..." << std::endl;
	std::cout << "Abs: " << myNum.absolute() << ", Arg: " << myNum.argument() << std::endl;
	std::cin >> userInput;
	std::cout << userInput;

	return EXIT_SUCCESS;
}