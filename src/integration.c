#include <stdio.h>
#include <math.h>


typedef struct integration
{
	double a,b,dx;
	double area_left;
	double area_right;
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
	func.area_left = 0.0f;
	func.area_right = 0.0f;

	//left riemann sum 
	for(double i=func.a; i<=func.b ; i+=func.dx)
	{
		func.area_left+= _sin_function(i)*func.dx;
	}

	//right riemann sum 
	
	for(double i=func.b; i>=func.a ; i-=func.dx)
	{
		func.area_right+= _sin_function(i)*func.dx;
	}	

	return func;
}

int main(void)
{
	Rieman_over _sin = _constant_dx(0.0f, 3.0f, 0.1f);

	printf("%f,%f\n", _sin.area_left, _sin.area_right);
	
	return 0;
}
