#include <stdio.h>
#include <math.h>


typedef struct integration
{
	double a,b,dx;
	double area;
}Rieman_over;

double _sin_function(double x)
{
	return sin(x);
}

Rieman_over _constant_dx(double a, double b, double dx)
{

	Rieman_over func;

	func.a = a;
	func.b = b;
	func.dx = dx;
	func.area = 0.0f;
	for(double i=func.a; i<=func.b ; i+=func.dx)
	{
		func.area += _sin_function(i)*func.dx;
	}	

	return func;
}

int main(void)
{
	Rieman_over _sin = _constant_dx(0.0f, 3.0f, 0.1f);

	printf("%f\n", _sin.area);
	
	return 0;
}
