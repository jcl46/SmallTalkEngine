class Math
{
public:
	double Pow(double number, double power) 
	{
		double result;
		double temp;
		temp = number;
		result = temp;
		for (int i = 1; i <= power) 
		{
			temp = temp * number;
		}
		return result;
	}
};