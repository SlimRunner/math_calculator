#ifndef COMPLEX_H
#define COMPLEX_H

namespace slmath
{
	class Complex
	{
	public: //---------------- P U B L I C ----------------//

		/***** EXCEPTION HANDLING *****/



		/******** CONSTRUCTORS ********/

		Complex() noexcept;
		Complex(double real, double imag) noexcept;
		Complex(double abs, double arg, int) noexcept;

		~Complex() noexcept;

		/********* ACCESSORS **********/

		double real() { return real_m; }
		double imaginary() { return imaginary_m; }

		/********** MUTATORS **********/



	private: //--------------- P R I V A T E ---------------//

		/****** MEMBER VARIABLES ******/

		double real_m;
		double imaginary_m;

		/****** MEMBER FUNCTIONS ******/


	};
}

#endif // !COMPLEX_H