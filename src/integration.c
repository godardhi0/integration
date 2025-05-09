#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846


typedef struct integration
{
	double width,dx;
	double area_left;
	double area_right;

}Rieman_over;

double _sin_function(double x)
{
	return sin(x);
}

double _linear_function(double x)
{
	return (x+1);
}

Rieman_over _constant_dx(double a, double b, double dx)
{

	Rieman_over func;

	func.width = (b - a) / dx;
	func.dx = dx;
	func.area_left = 0.0;
	func.area_right = 0.0;

	 // Left Riemann sum
	 for (int i = 0; i < func.dx; i++) {
        double x = a + i * func.width;
        func.area_left += _linear_function(x) * func.width;
    }

    // Right Riemann sum
    for (int i = 1; i <= func.dx; i++) {
        double x = a + i * func.width;
        func.area_right += _linear_function(x) * func.width;
    }

	return func;
}

int main(void)
{
	Rieman_over _linear = _constant_dx(0.0, 3.0, 1000000.0);

	printf("%f,%f\n", _linear.area_left, _linear.area_right);
	
	return 0;
}
