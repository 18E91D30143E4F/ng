#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>

/*
	Выражение ln(x)-5sin(x)^2 в разрешенном виде 1/(5*sin(2*x))
*/

static int count = 0;

double GetValue(double x)
{
	count++;
	return log(x) - 5 * sin(x) * sin(x);
}

double GetValueConv(double x)
{
	count++;
	return 1. / (5 * sin(2 * x));
}

int SimpleMethod(double a, double b, double eps, double* x)
{
	double fa, fb;
	int i;
	for (i = 0; i < 100000; i++)
	{
		if (fabs(b - a) < eps)
			break;
		fa = GetValue(a);
		fb = GetValue(b);
		a = b - (b - a) * fb / (fb - fa);
		b = a - (a - b) * fa / (fa - fb);
	}
	if (i < 100000)
	{
		*x = b;
		return count;
	}
	return -1;
}

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double a, b, eps, x = INT_MAX, predValue;
	int iter;

	printf("Введите a: ");
	scanf_s("%lf", &a);
	printf("Введите b: ");
	scanf_s("%lf", &b);
	printf("Введите eps: ");
	scanf_s("%lf", &eps);

	while (a <= b - 1)
	{
		predValue = x;
		iter = SimpleMethod(a, a + 0.2, eps, &x);
		if (iter > 0 && fabs(predValue - x) > 0.0001)
			printf("Root: %lf\n", x);
		a++;
	}

	getch();
	return 0;
}