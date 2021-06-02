#include <math.h>
#include <stdio.h>
#include <Windows.h>

double fn(double x) {
	return 7 * sin(x) * sin(x);
}

double GetValue(double a, double b, double eps)
{
	double
		x1, x2, xStar,
		y1, y2, yStar,
		delta = eps * 0.1;

	while ((b - a) > eps)
	{
		x1 = (b + a - delta) / 2.;
		x2 = (b + a + delta) / 2.;
		y1 = fn(x1);
		y2 = fn(x2);
		if (y1 <= y2)
		{
			b = x2;
		}
		else
		{
			a = x1;
		}
	}
	xStar = (a + b) / 2;

	return xStar;
}

double GetValueRec(double a, double b, double eps)
{
	double
		x1, x2, xStar,
		y1, y2, yStar,
		delta = eps * 0.1;

	x1 = (b + a - delta) / 2.;
	x2 = (b + a + delta) / 2.;
	y1 = fn(x1);
	y2 = fn(x2);
	if (y1 <= y2)
	{
		b = x2;
	}
	else
	{
		a = x1;
	}

	if ((b - a) < eps)
	{
		return (a + b) / 2;
	}
	else
	{
		return GetValueRec(a, b, eps);
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Минимум в : %lf", GetValue(2, 6, 0.001));
	printf("Минимум в : %lf (реккурсия)", GetValueRec(2, 6, 0.001));

	getch();

	return 0;

}