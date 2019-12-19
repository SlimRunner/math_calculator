#include <iostream>
#include "Complex.h"

int main()
{
	slmath::Complex myNum(2, 3);
	slmath::Complex myNum2(4, 7);
	slmath::Complex myNum3 = myNum2 / myNum;
	myNum3 = myNum3 * myNum3;
	myNum = myNum.get_conjugate();
	int userInput;

	std::cout << "Entry point..." << std::endl;
	std::cout << "Re: " << myNum3.real() << ", Im: " << myNum3.imaginary() << std::endl;
	std::cout << "Abs: " << myNum3.absolute() << ", Arg: " << myNum3.argument() << std::endl;
	std::cin >> userInput;
	std::cout << userInput;

	return EXIT_SUCCESS;
}