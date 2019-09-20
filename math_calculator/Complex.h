#ifndef COMPLEX_H
#define COMPLEX_H

#include <math.h>

namespace slmath
{
	template <class T>
	class Complex
	{
	public: //---------------- P U B L I C ----------------//

		/***** EXCEPTION HANDLING *****/



		/******** CONSTRUCTORS ********/

		Complex() noexcept : real_m(0), imag_m(0) {};
		Complex(T real, T imag) noexcept : real_m(real), imag_m(imag) {};

		~Complex() noexcept {};

		/********* ACCESSORS **********/

		T real() const { return real_m; }
		T imaginary() const { return imag_m; }

		double absolute() const
		{
			return sqrt(real_m * real_m + imag_m * imag_m);
		}

		double argument() const
		{
			if (real_m > 0)
				return atan(static_cast<double>(imag_m) / real_m);
			else if (imag_m > 0)
				return H_PI - atan(static_cast<double>(real_m) / imag_m);
			else if (imag_m < 0)
				return -H_PI - atan(static_cast<double>(real_m) / imag_m);
			else if (real_m < 0)
				return atan(static_cast<double>(imag_m) / real_m) + PI;
			else
				return 0;
		}

		/********** MUTATORS **********/

		void set_rectangular(T real, T imag)
		{
			real_m = real;
			imag_m = imag;
		}
		
		void set_polar(double abs, double arg)
		{
			real_m = static_cast<T>(abs * cos(arg));
			real_m = static_cast<T>(abs * sin(arg));
		}

		/********** METHODS ***********/

		//conjugate

		/********* OPERATORS **********/

		//addition
		//subtraction
		//multiplication
		//division
		//pow 2
		//RE(sqrt)

	private: //--------------- P R I V A T E ---------------//

		/****** MEMBER VARIABLES ******/

		static constexpr double PI = 3.14159265358979323846264338327950288;
		static constexpr double H_PI = 1.57079632679489661923132169163975144;

		T real_m;
		T imag_m;

		/****** MEMBER FUNCTIONS ******/


	};
}

#endif // !COMPLEX_H