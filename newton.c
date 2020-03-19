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
	printf ("%.4f" , res);
	return 0;
}

double newton(fder_t f , double x)
{
	double x_new = x;
	double x_old = 2;
	while (1 != 0)
	{
		if (fabs(x_old - x_new) <  0.000000001)
			return x_new;
		struct func_deriv func_need = f(x_old);
		x_old = x_new;
		x_new = x_old - func_need.func / func_need.der;
	};
	return 0;
};

struct func_deriv fder_ttt (double x)
{
	double a =  x * x + exp(x) - 0.827185;
	double b =  2 * x + exp(x);
	struct func_deriv res;
	res.func = a;
	res.der = b;
	return res;
};
