#include "Complex.h"
#include <math.h>

using namespace slmath;

double Complex::absolute() const
{
	return sqrt(real_m * real_m + imag_m * imag_m);
}

double Complex::argument() const
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

void Complex::set_rectangular(double real, double imag)
{
	real_m = real;
	imag_m = imag;
}

void Complex::set_polar(double abs, double arg)
{
	real_m = static_cast<double>(abs * cos(arg));
	imag_m = static_cast<double>(abs * sin(arg));
}

void Complex::negate()
{
	real_m *= -1;
	imag_m *= -1;
}

void Complex::conjugate()
{
	imag_m *= -1;
}

Complex Complex::get_conjugate()
{
	Complex conj(real_m, -imag_m);
	return conj;
}

Complex Complex::operator + (const Complex rhs) const
{
	Complex temp(*this);
	temp.real_m += rhs.real_m;
	temp.imag_m += rhs.imag_m;
	return temp;
}

Complex Complex::operator - (const Complex rhs) const
{
	Complex temp(*this);
	temp.real_m -= rhs.real_m;
	temp.imag_m -= rhs.imag_m;
	return temp;
}

Complex Complex::operator * (const Complex rhs) const
{
	Complex temp;
	temp.real_m = real_m * rhs.real_m - imag_m * rhs.imag_m;
	temp.imag_m = real_m * rhs.imag_m + imag_m * rhs.real_m;
	return temp;
}

Complex Complex::operator / (const Complex rhs) const
{
	Complex temp;
	double denom = rhs.real_m * rhs.real_m + rhs.imag_m * rhs.imag_m;
	temp.real_m = (real_m * rhs.real_m + imag_m * rhs.imag_m) / denom;
	temp.imag_m = (imag_m * rhs.real_m - real_m * rhs.imag_m) / denom;
	return temp;
}