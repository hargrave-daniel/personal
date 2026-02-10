/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
-	Name: 																	 -
- 	Section: 																 -
-	NetID: 																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int integer_result;
    double decimal_result;

    integer_result = 77 / 5;
    printf("The value of 77/5 is %d, using integer math.\n", integer_result);
	//I changed %lf to %d because it is an integer and not a double.

    integer_result = 2 + 3;
    printf("The value of 2+3 is %d.\n", integer_result);
	//I added the comma and integer_result because it needs to know what integer is being called.
	
    decimal_result = 1.0 / 22.0;
    printf("The value 1.0/22.0 is %lf.\n", decimal_result);
	//I changed %d to %lf because it is a double and not an integer.

    return 0;
}
