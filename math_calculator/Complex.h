#ifndef COMPLEX_H
#define COMPLEX_H

namespace slmath
{
	class Complex
	{
	public: //---------------- P U B L I C ----------------//

		/***** EXCEPTION HANDLING *****/



		/******** CONSTRUCTORS ********/

		Complex() noexcept : real_m(0), imag_m(0) {};
		Complex(double real, double imag) noexcept : real_m(real), imag_m(imag) {};

		//allow default move semantics
		//~Complex() noexcept {};

		/********* ACCESSORS **********/

		double real() const { return real_m; }
		double imaginary() const { return imag_m; }

		double absolute() const;

		double argument() const;

		/********** MUTATORS **********/

		void set_rectangular(double real, double imag);
		
		void set_polar(double abs, double arg);

		void negate();

		void conjugate();

		/********** METHODS ***********/

		Complex get_conjugate();

		Complex pow2();

		/********* OPERATORS **********/

		//addition
		Complex operator + (const Complex rhs) const;

		template <class Op>
		Complex operator + (Op rhs) const
		{
			Complex temp(*this);
			temp.real_m += rhs;
			return temp;
		}

		template <class Op>
		friend Complex operator + (Op lhs, const Complex& rhs)
		{
			Complex temp(rhs);
			temp.real_m += lhs;
			return temp;
		}

		//subtraction
		Complex operator - (const Complex rhs) const;

		template <class Op>
		Complex operator - (Op rhs) const
		{
			Complex temp(*this);
			temp.real_m -= rhs;
			return temp;
		}

		template <class Op>
		friend Complex operator - (Op lhs, const Complex& rhs)
		{
			Complex temp(rhs);
			temp.negate();
			temp.real_m += lhs;
			return temp;
		}

		//multiplication
		Complex operator * (const Complex rhs) const;

		template <class Op>
		Complex operator * (Op rhs) const
		{
			Complex temp(*this);
			temp.real_m *= rhs;
			temp.imag_m *= rhs;
			return temp;
		}

		template <class Op>
		friend Complex operator * (Op lhs, const Complex& rhs)
		{
			Complex temp(rhs);
			temp.real_m *= lhs;
			temp.imag_m *= lhs;
			return temp;
		}

		//division
		Complex operator / (const Complex rhs) const;

		template <class Op>
		Complex operator / (Op rhs) const
		{
			Complex temp(*this);
			temp.real_m /= rhs;
			temp.imag_m /= rhs;
			return temp;
		}

		template <class Op>
		friend Complex operator / (Op lhs, const Complex& rhs)
		{
			Complex temp;
			double denom = rhs.real_m * rhs.real_m + rhs.imag_m * rhs.imag_m;
			temp.real_m = (lhs * rhs.real_m) / denom;
			temp.imag_m = (lhs * rhs.imag_m) / -denom;
			return temp;
		}

		//RE(sqrt)

	private: //--------------- P R I V A double E ---------------//

		/****** MEMBER VARIABLES ******/

		static constexpr double PI = 3.14159265358979323846264338327950288;
		static constexpr double H_PI = 1.57079632679489661923132169163975144;

		double real_m;
		double imag_m;

		/****** MEMBER FUNCTIONS ******/


	};
}

#endif // !COMPLEX_H