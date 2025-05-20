#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846
#define m 2
#define k 2
#define dx 1000000000 // precision =  0.0000000001

#define CREATE_coef_degre(...) (double[]){ __VA_ARGS__}

typedef struct integration
{
	double width,_dx;
	double area_left;
	double area_right;
	char *message;

}Rieman_over;

double _linear_function(double variable)
{
	return m * variable  + k;	
}

double _polynomial_function(const double *coef_degre, double variable, const int coef_degre_size)
{
	double _poly_sum=0.0;
	if(coef_degre!= NULL)
	{
		for(int j=0; j<coef_degre_size; j+=2)
		{  
			double _variable_power = 1.0;
			for(int i=0 ; i<coef_degre[j+1]; i++)
			{
				_variable_power *= variable;
			}

			_poly_sum += coef_degre[j] * _variable_power;
		}		
	}
	return _poly_sum;
}

double _abs(double a, double b)
{
	double abs_ab = a - b;
	return fabs(abs_ab);
}

void _constant_dx(Rieman_over *_linear, Rieman_over *_non_linear,const double *coef_degre, const int coef_degre_size,const double a, const double b)
{

	 double width = (b - a) / dx;
	_linear->width =  width;
	_non_linear->width =  width;

	_linear->_dx = dx;
	_non_linear->_dx= dx;

	_linear->area_left = 0.0;
	_non_linear->area_left = 0.0;

	_linear->area_right = 0.0;
	_non_linear->area_right = 0.0;

	 // Left Riemann sum
	 for (int i = 0; i < dx; i++) {
        double x = a + i * _linear->width;
        //_linear->area_left += _linear_function(x) * width;
		_non_linear->area_left += _polynomial_function(coef_degre,x,coef_degre_size) * width;
    }

	

    // Right Riemann sum
    for (int i = 1; i <= dx; i++) {
		double x = a + i * _linear->width;
		//_linear->area_right += _linear_function(x) * width;
		_non_linear->area_right += _polynomial_function(coef_degre,x,coef_degre_size) * width;
    }

	
}

int main(void)
{
	Rieman_over *_linear = (Rieman_over *)malloc(sizeof(Rieman_over));
	Rieman_over *_non_linear = (Rieman_over *)malloc(sizeof(Rieman_over));

	double *coef = CREATE_coef_degre(-1,3,4,2);
	
	_constant_dx(_linear,_non_linear,coef,4,0, 4);

	//printf("linear function:|%f-%f|=%.6f\n", _linear->area_left, _linear->area_right, _abs(_linear->area_left,_linear->area_right));
	printf("non-linear function:|%f-%f|=%.6f\n", _non_linear->area_left, _non_linear->area_right, _abs(_non_linear->area_left,_non_linear->area_right));
	
	free(_linear);
	free(_non_linear);
	return 0;
}
