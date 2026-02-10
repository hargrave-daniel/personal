#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int a = 6427 + 1725;

	printf("%d\n", a);
	
	int b = (6971 * 3925) - 95;
	printf("%d\n", b);
	
	double c = 79 + 12 / 5;
	printf("%.2lf\n", c);
	
	double d = 3640.0 / 107.9;
	printf("%.2lf\n", d);
	
	int e = (22 / 3) * 3;
	printf("%d\n", e);
	
	int f = 22 / (3 * 3);
	printf("%d\n", f);
	
	double g = 22 / (3 * 3);
	printf("%.2lf\n", g);
	
	double h = 22 / 3 * 3;
	printf("%.2lf\n", h);
	
	double i = (22.0 / 3) * 3.0;
	printf("%.2lf\n", i);
	
	int j = 22.0 / (3 * 3.0);
	printf("%d\n", j);
	
	double k = 22.0 / 3.0 * 3.0;
	printf("%.2lf\n", k);
	
	double radius_squared = pow((23.567 / (2 * M_PI)), 2);
	// The circumference divided by 2 pi equals the radius. Take the aquare of that to get radius squared.
	double area = radius_squared * M_PI;
	// pi * r^2 = Area
	printf("A circle with a circumference of 23.567 has an area of %.2lf\n", area);
	
	double meters = 14 * 0.3048;
	// ft * 0.3048 = m
	printf("14 ft. = %.2lf m\n", meters);
	
	double celsius = (76 - 32) / 1.8;
	// C = (F -32) / 1.8
	printf("76 degrees F = %.2lf degrees C\n", celsius);
	
    return 0;
}
