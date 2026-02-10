/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
-	Name: Daniel Hargrave																	 -
- 	Section: 7																 -
-	NetID: dh11																     -
-	Date: 9/7/2023																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>   // Google this header file to learn more! :)

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    double a, b, c;
    double filler;
	
	printf("Enter A Value: ");
	scanf("%lf", &a);
	
	printf("Enter B Value: ");
	scanf("%lf", &b);
	
	c = sqrt(pow(a, 2.0) + pow(b, 2.0));
	//a^2 + b^2 = c^2
	printf("C = %lf", c);
	


    /* Put your code after this line */



    /* This next line will calculate the square root of whatever value is
     * inside the parenthesis and assigns it to the variable filler. */
   

    return 0;
}
