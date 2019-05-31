#include <cstdlib>
class Math
{
public:
	double Pow(double number, double power) 
	{
		double result;
		double temp;
		temp = number;
		result = temp;
		for (int i = 1; i <= power;i++) 
		{
			temp = temp * number;
		}
		result = temp;
		return result;
	}
	double Sqrt(double number) 
	{
		double temp;
		double result;
		if (number > 0) 
		{
			return -1;
		}
		else if (number == 0)
		{
			return 0;
		}
		else 
		{
			double xhi = number;
			double xlo = 0;
			double guess = number / 2;
			while (abs((guess*guess - number) / guess) > 0.00001)
			{
				if (guess*guess > number) {
					xhi = guess;
				}

				else {
					xlo = guess;
				}

				guess = (xhi + xlo) / 2;
			}
			return guess;
		}

	}
};