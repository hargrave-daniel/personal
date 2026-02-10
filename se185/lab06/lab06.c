/*----------------------------------------------------------------------------
-		                    SE 185: Lab 06 - Bop-It!	    	             -
-	Name:																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
-	                            Notes                                        -
-----------------------------------------------------------------------------*/
// Compile with gcc lab06.c -o lab06
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -b | ./lab06

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
	int t, triangle, circle, cross, square;
	int start = 0;
	int startTime;
	int endTime;
	int roundTime;
	int randomButton;
	int round = 0;
	int userButton = 0;
	int randVal;
	
    srand(time(NULL)); /* This will ensure a random game each time. */
	
	 while (1)
    {
		printf("This is a Bop-It Game! \nClick the circle button to start!\n");
		while (start == 0) {
			scanf("%d, %d, %d, %d, %d",&t, &triangle, &circle, &cross, &square);
			if(circle == 1){
				start = 1;
			}
		}
		while (start == 1) {
			scanf("%d, %d, %d, %d, %d",&t, &triangle, &circle, &cross, &square);
			roundTime = 2500 - (round * 100);
			randVal = rand() % 4;
			if (randVal == 0){
				randomButton = 1;
				printf("Press the circle button\n");
			}
			if (randVal == 1){
				randomButton = 2;
				printf("Press the triangle button\n");
			}
			if (randVal == 2){
				randomButton = 3;
				printf("Press the square button\n");
			}
			if (randVal == 3){
				randomButton = 4;
				printf("Press the cross button\n");
			}
			while((triangle == 1) || (circle == 1) || (cross == 1) || (square == 1)) {
				scanf("%d, %d, %d, %d, %d",&t, &triangle, &circle, &cross, &square);
			}
			printf("You have %d milliseconds to respond!\n", roundTime);
			startTime = t;
			endTime = startTime + roundTime;
			while ((t >= startTime) && (t < endTime)) {
				scanf("%d, %d, %d, %d, %d",&t, &triangle, &circle, &cross, &square);
				start = 0;
				if (circle == 1){
					userButton = 1;
				}
				if (triangle == 1){
					userButton = 2;
				}
				if (square == 1){
					userButton = 3;
				}
				if (cross == 1){
					userButton = 4;
				}
				if (userButton != 0) {
					if (userButton == randomButton) {
						start = 1;
						round = round + 1;
						userButton = 0;
						break;
					}
					if (userButton != randomButton) {
						start = 2;
						break;
					}
				}
			}
		}
		if (start == 0) {
			printf("You ran out of time. :( \n");
			printf("Thanks for playing!\n");
			printf("You made it through %d rounds!", round);
			break;
		}
		if (start == 2) {
			printf("Wrong button! :( \n");
			printf("You lose!\n");
			printf("You made it through %d rounds!", round);
			break;
		}
			
	}
    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */

