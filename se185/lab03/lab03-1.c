/*----------------------------------------------------------------------------
-		    SE 185: Lab 03 - Introduction to the DS4 and Functions	    	 -
-	Name: Daniel Hargrave																	 -
- 	Section: 7																 -
-	NetID: dh11																     -
-	Date: 9/20																	 -
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
int minutes(int ms);
int seconds(int ms);
int milliseconds(int ms);
/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab03-1.c -o lab03-1
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -a | ./lab03-1

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int t;
    double ax, ay, az;
	



    while (1)
    {
        scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);

  
        printf("Echoing output: %8.3lf, %7.4lf, %7.4lf, %7.4lf\n", t/1000.0, ax, ay, az);


        printf("At %d ms, the acceleration's magnitude was: %lf\n", t, magnitude(ax, ay, az));
		


        
       
            printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n",
            minutes(t), seconds(t), milliseconds(t), magnitude(ax, ay, az));
       
    }

    return 0;
}

/* Put your functions here */
  int minutes(int ms)
{
	int mn = ms / 60000;
	return mn;
}
int seconds(int ms)
{
	int sc = (ms / 1000) % 60;
	return sc;
}
int milliseconds(int ms)
{
	int mls = ms % 1000;
	return mls;
}
/*
 * Calculates and returns the magnitude of three given values.
 *
  @param x - The x-axis scanned values from the DS4 controller.
  @param y - The y-axis scanned values from the DS4 controller.
  @param z - The z-axis scanned values from the DS4 controller.
  @return - The magnitude of the given values.
 */
double magnitude(double x, double y, double z)
{
    double mgn = sqrt(pow(x, 2) + pow(y,2) + pow(z, 2));
	return mgn;
	
}

