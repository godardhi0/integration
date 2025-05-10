#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846


typedef struct integration
{
	double width,dx;
	double area_left;
	double area_right;
	char *message;

}Rieman_over;

double _linear_function(double varaible, const double angular, const double constant)
{
	return angular * varaible  + constant;	
}

/*
double _sin_function(double varaible, const double constant)
{
	return tan(varaible);
}

double _non_linear_function(char *expresssion)
{

}
*/
double _abs(double a, double b)
{
	double abs_ab = a - b;
	return fabs(abs_ab);
}

void _constant_dx(Rieman_over *_linear, Rieman_over *_non_linear,const double angular, const double constant, const double a, const double b, const int dx)
{

	_linear->width = (b - a) / dx;
	_non_linear->width = (b - a) / dx;

	_linear->dx = dx;
	_non_linear->dx = dx;

	_linear->area_left = 0.0;
	_non_linear->area_left = 0.0;

	_linear->area_right = 0.0;
	_non_linear->area_right = 0.0;

	 // Left Riemann sum
	 for (int i = 0; i < dx; i++) {
        double x = a + i * _linear->width;
        _linear->area_left += _linear_function(x, angular, constant) * _linear->width;
		/*_non_linear->area_left += _sin_function(x) * _non_linear->width; */
    }

	

    // Right Riemann sum
    for (int i = 1; i <= dx; i++) {
		double x = a + i * _linear->width;
		_linear->area_right += _linear_function(x, angular, constant) * _linear->width;
		/*_non_linear->area_right += _sin_function(x) * _non_linear->width;*/
    }

	
}

int main(void)
{
	Rieman_over *_linear = (Rieman_over *)malloc(sizeof(Rieman_over));
	Rieman_over *_non_linear = (Rieman_over *)malloc(sizeof(Rieman_over));

	_constant_dx(_linear,_non_linear,2,2,0.0, PI/2, 10);

	printf("linear function:|%f-%f|=%.6f\n", _linear->area_left, _linear->area_right, _abs(_linear->area_left,_linear->area_right));
	//printf("non-linear function:|%f-%f|=%.6f\n", _non_linear->area_left, _non_linear->area_right, _abs(_non_linear->area_left,_non_linear->area_right));
	
	free(_linear);
	free(_non_linear);
	return 0;
}
