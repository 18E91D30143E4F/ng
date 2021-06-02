/*
	����� ������� ��������
*/

#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

double GetFunctionValue(double x)
{
	return (log(x) - 5 * pow(sin(x), 2));
}

double f(double x)
{
	return (1. / (5. * sin(2. * x)));
}

#define MAX_I 100000

int chord_method(double (*f)(double), double a, double b, double eps, double* x);
double f(double x);

static int count = 0;

int chord_method(double (*f)(double), double a, double b, double eps, double* x)
{
	double fa, fb;
	int i;
	for (i = 0; i < MAX_I; i++)
	{
		if (fabs(b - a) < eps) break;
		fa = f(a); fb = f(b);
		a = b - (b - a) * fb / (fb - fa);
		b = a - (a - b) * fa / (fa - fb);
	}
	if (i < MAX_I)
	{
		*x = b;
		return count;
	}
	return -1;
}

int main(void)
{
	double a, b, eps, x = INT_MAX, predValue;
	int iter;

	printf("Input a: "); scanf_s("%lf", &a);
	printf("Input b: "); scanf_s("%lf", &b);
	printf("Input eps: "); scanf_s("%lf", &eps);

	while (a < b)
	{
		predValue = x;
		iter = chord_method(GetFunctionValue, a, a + 1, eps, &x);
		if (iter > 0 && fabs(predValue - x) > 0.0001)
			printf("Root: %lf\n", x);
		a++;
	}

	getch();
	return 0;
}