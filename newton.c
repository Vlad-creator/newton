#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct func_deriv 
{
	double func;
	double der;
};

typedef struct func_deriv (*fder_t)(double x);

double newton(fder_t f , double x);
struct func_deriv fder_ttt (double x);

int main()
{
	fder_t f = &fder_ttt;
	double res = newton(f , 1);
	printf ("%f\n" , res);
	return 0;
}

double newton(fder_t f , double x)
{
	double x_new = 0;
	double x_old = x;
	int i = 0;
	while (fabs(x_old - x_new) >  __DBL_EPSILON__)
	{
		i++;
		struct func_deriv func_need = f(x_old);
		double per = x_old;
		x_old = x_new;
		x_new = per - func_need.func / func_need.der;
	};
	printf("newton - %d\n" , i);
	return x_new;
};

struct func_deriv fder_ttt (double x)
{
	double a =  x * x * sin(x) - 5 * x + 7;
	double b =  2 * x * sin(x) + x * x * cos(x) - 5;
	struct func_deriv res;
	res.func = a;
	res.der = b;
	return res;
};

