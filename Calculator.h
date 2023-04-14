#pragma once
class Calculator
{
private:
	double result;

public:
	//Konstuktor
	Calculator();
	//Destruktor
	~Calculator();

	enum Error
	{
		SUCCESS,
		NO_ROOTS,
		SINGLE_ROOT,
		TWO_ROOTS,
		INVALID_PARAMETER,
		DIVISION_BY_ZERO,
	};
	void Add(const double x, const double y);
	Error Substract(const double x, const double y);
	Error Multiply(const double x, const double y);

	Error Divide(const double, const double);
	double GetResult() const;

	void ResetValue(double);
	void ResetReferencedValue(double&);

	Error Roots(const double, const double, const double, double&, double&);
};

