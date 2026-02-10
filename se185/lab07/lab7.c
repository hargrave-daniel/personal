/*-----------------------------------------------------------------------------
-					          SE 185 Lab 07 - The DS4 Equalizer
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name:
- 	Section:
-	NetID:
-	Date:
-
-   This file provides the outline for your program
-   Please implement the functions given by the prototypes below and
-   complete the main function to make the program complete.
-   You must implement the functions which are prototyped below exactly
-   as they are requested.
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-								Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <time.h>


/*-----------------------------------------------------------------------------
-								Defines
-----------------------------------------------------------------------------*/
#define PI 3.141592653589

/* NO GLOBAL VARIABLES ALLOWED */


/*-----------------------------------------------------------------------------
-								Prototypes
-----------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------
    PRE: Arguments must point to double variables or int variables as appropriate
    This function scans a line of DS4 data, and returns
    True when left button is pressed
    False Otherwise
    POST: it modifies its arguments to return values read from the input line.
------------------------------------------------------------------------------------*/
int read_input( int* time,
                double* g_x, double* g_y, double* g_z,
                int* button_T, int* button_C, int* button_X, int* button_S,
                int* l_joy_x, int* l_joy_y, int* r_joy_x, int* r_joy_y );

/*-----------------------------------------------------------------------------
    PRE: ~(-1.0) <= mag <= ~(1.0)
    This function scales the roll/pitch value to fit on the screen.
    Input should be capped at either -1.0 or 1.0 before the rest of your
    conversion.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleMagForScreen(double rad);

/*-----------------------------------------------------------------------------
    PRE: -128 <= mag <= 127
    This function scales the joystick value to fit on the screen.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleJoyForScreen(int rad);

/*----------------------------------------------------------------------------
    PRE: -39 <= number <= 39
    Uses print_chars to graph a number from -39 to 39 on the screen.
    You may assume that the screen is 80 characters wide.
----------------------------------------------------------------------------*/
int graph_line(int number);

/*-----------------------------------------------------------------------------
    PRE: num >= 0
    This function prints the character "use" to the screen "num" times
    This function is the ONLY place printf is allowed to be used
    POST: nothing is returned, but "use" has been printed "num" times
-----------------------------------------------------------------------------*/
void print_chars(int num, char use);


/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/
int main()
{
    double x, y, z;                     /* Values of x, y, and z axis*/
    int t; 								/* Variable to hold the time value */
    int b_Up, b_Down, b_Left, b_Right;  /* Variables to hold the button statuses */
    int j_LX, j_LY, j_RX, j_RY;         /* Variables to hold the joystick statuses */
    int scaled_pitch, scaled_roll; 	    /* Value of the roll/pitch adjusted to fit screen display */
    int scaled_joy;	/* Value of joystick adjusted to fit screen display */
	char letter;
	double radians_x;
	double radians_y;
	int mode = 1;
	int* time;
    double* g_x; double* g_y; double* g_z;
    int* button_T; int* button_C; int* button_X; int* button_S;
    int* l_joy_x; int* l_joy_y; int* r_joy_x; int* r_joy_y;
	
	time = &t; g_x = &x; g_y = &y; g_z = &z; 
	button_T = &b_Up; button_C = &b_Down; button_X = &b_Left; button_S = &b_Right;
	l_joy_x = &j_LX; l_joy_y = &j_LY; r_joy_x = &j_RX; r_joy_y = &j_RY;

    /* Put pre-loop preparation code here */

    while(1)
    {
        read_input(&t, &x, &y, &z, &b_Up, &b_Right, &b_Down, &b_Left, &j_LX, &j_LY, &j_RX, &j_RY); 
		radians_x = atan(z / x);
		radians_y = atan(z / y);

        scaled_pitch = scaleMagForScreen(radians_x);
		scaled_roll = scaleMagForScreen(radians_y);
		scaled_joy = scaleJoyForScreen(j_LX);

        if (b_Up == 1) {
			mode = 2;
			}
		if (b_Down == 1) {
			mode = 1;
		}
		if (b_Right == 1) {
			mode = 3;
		}
		if (b_Left == 1) {
			break;
		}
		
		if ((mode == 1) && (graph_line(scaled_pitch) == 1)) {
			letter = 'L';
			print_chars (scaled_pitch, letter);
		}
		if ((mode == 1) && (graph_line(scaled_pitch) == 2)) {
			letter = 'R';
			print_chars (scaled_pitch, letter);
		}
		if ((mode == 1) && (graph_line(scaled_pitch) == 0)) {
			letter = 'Z';
			print_chars (scaled_pitch, letter);
		}
		if ((mode == 2) && (graph_line(scaled_roll) == 1)) {
			letter = 'B';
			print_chars (scaled_roll, letter);
		}
		if ((mode == 2) && (graph_line(scaled_roll) == 2)) {
			letter = 'F';
			print_chars (scaled_roll, letter);
		}
		if ((mode == 2) && (graph_line(scaled_roll) == 0)) {
			letter = 'Z';
			print_chars (scaled_roll, letter);
		}
		if ((mode == 3) && (graph_line(scaled_joy) == 1)) {
			letter = 'Q';
			print_chars (scaled_joy, letter);
		}
		if ((mode == 3) && (graph_line(scaled_joy) == 2)) {
			letter = 'P';
			print_chars (scaled_joy, letter);
		}
		if ((mode == 3) && (graph_line(scaled_joy) == 0)) {
			letter = 'Z';
			print_chars (scaled_joy, letter);
		} 

        


        fflush(stdout);

    } while (b_Left != 1); 
    return 0;

}

int read_input( int* time,
                double* g_x, double* g_y, double* g_z,
                int* button_T, int* button_C, int* button_X, int* button_S,
                int* l_joy_x, int* l_joy_y, int* r_joy_x, int* r_joy_y ) 
				{
					scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d", time, g_x, g_y, g_z, 
					button_T, button_C, button_X, button_S, 
					l_joy_x, l_joy_y, r_joy_x, r_joy_y);
					if (*button_X == 1) {
						return 0;
					}
					if (button_X == 0) {
						return 1;
					}
				}
				
int scaleMagForScreen(double rad){
	return ((rad / (PI / 2)) * 39);
}
int scaleJoyForScreen(int rad){
	return (rad * 39) / 128;
}
int graph_line(int number){
	if((number < 38) && (number > 0)) {
		return 1;
	}
	if((number > -38) && (number < 0)) {
		return 2;
	}
	if((number == 38) || (number == -38)) {
		return 0;
	}
}
void print_chars(int num, char use){
	int i = 0;
	if (use == 'L') {
		while (i < 39) {
			if (num <= i){
				printf("%c", use);
				}
			if (num > i){
				printf(" ");
			}
			i = i + 1;
		}
	}
	
	if (use == 'R') {
		for (i == 0; i <= 39; i++) {
			printf(" ");
		}
		i = -39;
		while (i < 0) {
			if (num >= i){
				printf("%c", use);
				}
			if (num < i) {
				printf(" ");
			}
			i = i + 1;
		}
	}
	
	if (use == 'B') {
		while (i <= 38) {
			if (num <= i){
				printf("%c", use);
				}
			if (num > i){
				printf(" ");
			}
			i = i + 1;
		}
	}
	
	if (use == 'F') {
		for (i == 0; i <= 39; i++) {
			printf(" ");
		}
		i = -39;
		while (i < 0) {
			if (num >= i){
				printf("%c", use);
				}
			if (num < i) {
				printf(" ");
			}
			i = i + 1;
		}
	}
	
	if (use == 'Z') {
		for (i == 0; i < 39; i++) {
			printf(" ");
		}
		printf("0");
		for (i == 40; i <= 78; i++) {
			printf(" ");
		}
	}
	
	if (use == 'Q') {
		for (i == 0; i <= 39; i++) {
			printf(" ");
		}
		i = 0;
		while (i < 39) {
			if (num >= i){
				printf("%c", use);
				}
			if (num < i){
				printf(" ");
			}
			i = i + 1;
		}
	}
	
	if (use == 'P') {
		i = -39;
		while (i < 0) {
			if (num <= i){
				printf("%c", use);
				}
			if (num > i) {
				printf(" ");
			}
			i = i + 1;
		}
	}
	printf("\n");
}
				

					