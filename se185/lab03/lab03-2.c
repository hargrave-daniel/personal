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
int totalButtons(int w, int x, int y, int z);

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab03-2.c -o lab03-2
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -b | ./lab03-2

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
int a;
int b;
int c;
int d;

    while (1)
    {
		scanf("%d, %d, %d, %d", &a, &b, &c, &d);
		printf("Echoing output: %d, %d, %d, %d\n", a, b, c, d);
		printf("There are %d buttons being pressed.\n", totalButtons(a, b, c, d));
		fflush(stdout);
    }

    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */
int totalButtons(int w, int x, int y, int z)
{
	int sum = w + x + y + z;
	return sum;
}

