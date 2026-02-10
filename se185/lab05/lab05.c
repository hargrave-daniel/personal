/*----------------------------------------------------------------------------
-		         SE 185: Lab 05 - Conditionals (What's up?)	    	         -
-	Name: Daniel Hargrave																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
double magnitude(double x, double y, double z);
int close_to(double tolerance, double point, double value);
int orientation(double u, double v, double w);
/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab05.c -o lab05
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -a -g -b | ./lab05

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int triangle, circle, x_button, square;
    double ax, ay, az, gx, gy, gz;
	int same = 0;

    while (1)
    {
        scanf("%lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d",
              &ax, &ay, &az, &gx, &gy, &gz, &triangle, &circle, &x_button, &square);

        /* printf for observing values scanned in from ds4rd.exe,
         * be sure to comment or remove in final program */
        printf("Echoing output: %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n",
               ax, ay, az, gx, gy, gz, triangle, circle, x_button, square);
		printf("Magnitude = %lf\n", magnitude(ax, ay, az));*/
		//printf("Orientation = %d\n", orientation(gx, gy, gz));
		if ((same > orientation(gx, gy, gz)) || (same < orientation(gx, gy, gz))){
			if (close_to(.05, magnitude(ax, ay, az), 0) == 1){
				if (orientation(gx, gy, gz) == 1) {
					printf("LEFT\n");
					same = orientation(gx, gy, gz);
				}
				if (orientation(gx, gy, gz) == 2) {
					printf("RIGHT\n");
					same = orientation(gx, gy, gz);
				}
				if (orientation(gx, gy, gz) == 3) {
					printf("TOP\n");
					same = orientation(gx, gy, gz);
				}
				if (orientation(gx, gy, gz) == 4) {
					printf("BOTTOM\n");
					same = orientation(gx, gy, gz);
				}
				if (orientation(gx, gy, gz) == 5) {
					printf("BACK\n");
					same = orientation(gx, gy, gz);
				}
				if (orientation(gx, gy, gz) == 6) {
					printf("FRONT\n");
					same = orientation(gx, gy, gz);
				} 
			}
		}
		
		if(triangle == 1) {
			break;
		}
	}
    return 0;
}
/* Put your functions here, and be sure to put prototypes above. */
double magnitude(double x, double y, double z)
{
    double mgn = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	return mgn;
}

int close_to(double tolerance, double point, double value)
{
	if(((point - tolerance) <= value) && ((point + tolerance) >= value)) {
		return 1;
	}
	else {
		return 0;
	}
}
int orientation(double u, double v, double w)
{
	if(close_to(.06, u, 1) == 1) {
		return 1; //left
	}
	if(close_to(.06, u, -1) == 1) {
		return 2; //right
	}
	if(close_to(.06, v, 1) == 1) {
		return 3; //top
	}
	if(close_to(.06, v, -1) == 1) {
		return 4; //bottom
	}
	if(close_to(.06, w, 1) == 1) {
		return 5; //back
	}
	if(close_to(.06, w, -1) == 1) {
		return 6; //front
	}
	else {
		return 0;
	}
}

	