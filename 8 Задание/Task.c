#include <stdio.h>
#include <math.h>
#include <Windows.h>

double GetFuncValue(double x)
{
	return (log(x) - 5 * pow(sin(x), 2));
}

double GaussianMethod(double a, double b)
{
	int m = 100;
	double Res = 0.;
	double xI, xI1, XI2, h = (b - a) / m;;

	for (int i = 1; i <= m; i++)
	{
		xI = a + (i - 1 + 0.5) * h;
		xI1 = xI - h / 2 * 0.7745966692;
		XI2 = xI + h / 2 * 0.7745966692;

		Res += (5. / 9. * GetFuncValue(xI1) + 8. / 9. * GetFuncValue(xI) + 5. / 9. * GetFuncValue(XI2));
	}

	Res *= h / 2;

	return Res;
}

double SpecifiedAccuracyMethod(double a, double b, double eps)
{
	double I = eps + 1, I1 = 0;
	for (int N = 2; (N <= 4) || (fabs(I1 - I) > eps); N *= 2)
	{
		double h, sum2 = 0, sum4 = 0, sum = 0;
		h = (b - a) / (2 * N);
		for (int i = 1; i <= 2 * N - 1; i += 2)
		{
			sum4 += GetFuncValue(a + h * i);
			sum2 += GetFuncValue(a + h * (i + 1));
		}
		sum = GetFuncValue(a) + 4 * sum4 + 2 * sum2 - GetFuncValue(b);
		I = I1;
		I1 = (h / 3) * sum;
	}

	return I1;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Метод Гаусса 3 : %lf\nВариант с заданной точностью (0.0001): %lf", GaussianMethod(3, 6), SpecifiedAccuracyMethod(3, 6, 0.0001));

	getch();

	return 0;
}