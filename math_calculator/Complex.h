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

		//allow default move semantics
		//~Complex() noexcept {};

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
			imag_m = static_cast<T>(abs * sin(arg));
		}

		void negate()
		{
			real_m *= -1;
			imag_m *= -1;
		}

		void conjugate()
		{
			imag_m *= -1;
		}

		/********** METHODS ***********/

		Complex<T> get_conjugate()
		{
			Complex<T> conj(real_m, -imag_m);
			return conj;
		}

		/********* OPERATORS **********/

		//addition
		Complex<T> operator + (const Complex<T> rhs) const
		{
			Complex<T> temp(*this);
			temp.real_m += rhs.real_m;
			temp.imag_m += rhs.imag_m;
			return temp;
		}

		template <class Op>
		Complex<T> operator + (Op rhs) const
		{
			Complex<T> temp(*this);
			temp.real_m += rhs;
			return temp;
		}

		template <class Op>
		friend Complex<T> operator + (Op lhs, const Complex<T>& rhs)
		{
			Complex<T> temp(rhs);
			temp.real_m += lhs;
			return temp;
		}

		//subtraction
		Complex<T> operator - (const Complex<T> rhs) const
		{
			Complex<T> temp(*this);
			temp.real_m -= rhs.real_m;
			temp.imag_m -= rhs.imag_m;
			return temp;
		}

		template <class Op>
		Complex<T> operator - (Op rhs) const
		{
			Complex<T> temp(*this);
			temp.real_m -= rhs;
			return temp;
		}

		template <class Op>
		friend Complex<T> operator - (Op lhs, const Complex<T>& rhs)
		{
			Complex<T> temp(rhs);
			temp.negate();
			temp.real_m += lhs;
			return temp;
		}

		//multiplication
		Complex<T> operator * (const Complex<T> rhs) const
		{
			Complex<T> temp;
			temp.real_m = real_m * rhs.real_m - imag_m * rhs.imag_m;
			temp.imag_m = real_m * rhs.imag_m + imag_m * rhs.real_m;
			return temp;
		}

		template <class Op>
		Complex<T> operator * (Op rhs) const
		{
			Complex<T> temp(*this);
			temp.real_m *= rhs;
			temp.imag_m *= rhs;
			return temp;
		}

		template <class Op>
		friend Complex<T> operator * (Op lhs, const Complex<T>& rhs)
		{
			Complex<T> temp(rhs);
			temp.real_m *= lhs;
			temp.imag_m *= lhs;
			return temp;
		}

		//division
		Complex<T> operator / (const Complex<T> rhs) const
		{
			Complex<T> temp;
			double denom = rhs.real_m * rhs.real_m + rhs.imag_m * rhs.imag_m;
			temp.real_m = (real_m * rhs.real_m + imag_m * rhs.imag_m) / denom;
			temp.imag_m = (imag_m * rhs.real_m - real_m * rhs.imag_m) / denom;
			return temp;
		}

		template <class Op>
		Complex<T> operator / (Op rhs) const
		{
			Complex<T> temp(*this);
			temp.real_m /= rhs;
			temp.imag_m /= rhs;
			return temp;
		}

		template <class Op>
		friend Complex<T> operator / (Op lhs, const Complex<T>& rhs)
		{
			Complex<T> temp;
			double denom = rhs.real_m * rhs.real_m + rhs.imag_m * rhs.imag_m;
			temp.real_m = (lhs * rhs.real_m) / denom;
			temp.imag_m = (lhs * rhs.imag_m) / -denom;
			return temp;
		}

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