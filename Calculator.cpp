#include "Calculator.h"
#include <math.h>

Calculator::Calculator() : result(0.0) //Lista inicjalizacyjna
{
}
Calculator::~Calculator()
{
}

void Calculator::Add(const double a, const double b)
{
	result = a + b;
}

Calculator::Error Calculator::Substract(const double x, const double y)
{
	result = x - y;
	return Calculator::Error::SUCCESS;
}

Calculator::Error Calculator::Multiply(const double x, const double y)
{
	result = x * y;
	return Calculator::Error::SUCCESS;
}

Calculator::Error Calculator::Divide(const double a, const double b)
{
	Calculator::Error error = Calculator::Error::SUCCESS;

	if (b == 0)
	{
		error = Calculator::Error::DIVISION_BY_ZERO;
	}
	else
	{
		result = a / b;
	}

	return error;
}


double Calculator::GetResult() const
{
	return result; 
}

void Calculator::ResetValue(double x)
{
	x = 0;
}

void Calculator::ResetReferencedValue(double &x)
{
	x = 0;
}

Calculator::Error Calculator::Roots(const double a, const double b, const double c, double &x0, double &x1)
{
	Calculator::Error error = Calculator::Error::SUCCESS;

	if (a == 0) 
	{
		error = Calculator::Error::INVALID_PARAMETER;
	}
	else
	{
		double delta = b * b - (4 * a * c);
		if (delta < 0)
		{
			error = Calculator::Error::NO_ROOTS;
		}
		else
		{
			if (delta == 0)
			{
				error = Calculator::Error::SINGLE_ROOT;
				x0 = -(b / (2 * a));
				x1 = x0;
			}
			else
			{
				error = Calculator::Error::TWO_ROOTS;
				delta = sqrt(delta);
				x0 = (-b - delta) / (2 * a);
				x1 = (-b + delta) / (2 * a);
			}
		}
	}
	return error;
}
