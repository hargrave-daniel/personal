/*-----------------------------------------------------------------------------
-					  		SE 185 Lab 08
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name:
- Section:
-	NetID:
-	Date:
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-								Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>


/*-----------------------------------------------------------------------------
-								Defines
-----------------------------------------------------------------------------*/
/* Mathmatical constants */
#define PI 3.14159

/* 	Screen geometry
    Use ROWS and COLUMNS for the screen height and width (set by system)
    MAXIMUMS */
#define COLUMNS 100
#define ROWS 80
#define MAXPOINTS 10000

/* 	Character definitions taken from the ASCII table */
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '

/*	Number of samples taken to form an moving average for the gyroscope data
    Feel free to tweak this. */
#define NUM_SAMPLES 10


/*-----------------------------------------------------------------------------
-								Static Data
-----------------------------------------------------------------------------*/
/* 2D character array which the maze is mapped into */
char MAZE[COLUMNS][ROWS];


/*-----------------------------------------------------------------------------
-								Prototypes
-----------------------------------------------------------------------------*/
/*	POST: Generates a random maze structure into MAZE[][]
    You will want to use the rand() function and maybe use the output %100.
    You will have to use the argument to the command line to determine how
    difficult the maze is (how many maze characters are on the screen). */
void generate_maze(int difficulty);

/*	PRE: MAZE[][] has been initialized by generate_maze()
    POST: Draws the maze to the screen */
void draw_maze(void);

/*	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y */
void draw_character(int x, int y, char use);

/*	PRE: -1.0 < mag < 1.0
    POST: Returns tilt magnitude scaled to -1.0 -> 1.0
    You may want to reuse the roll function written in previous labs. */
double calc_roll(double mag);

/* 	Updates the buffer with the new_item and returns the computed
    moving average of the updated buffer */
double m_avg(double buffer[], int avg_size, double new_item);

/* This is for the bonus.*/
double is_over(int x_place, int y_place);


/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/
/*	Main - Run with './ds4rd.exe -t -g -b' piped into STDIN */
void main(int argc, char* argv[])
{
	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	double new_x, new_y, new_z;
    double avg_x, avg_y, avg_z;
    int lengthofavg = 0;
	int b_up, b_right, b_down, b_left;
	int t;
	int i;
	int timer;
	double movement;
	int difficulty = 0;
	int delay = 400;
	int x_place = COLUMNS / 2;
	int y_place = 0;
	int a;
	
	if (argc>1) {
        sscanf(argv[1], "%d", &lengthofavg);
		sscanf(argv[2], "%d", &difficulty);
        //printf("You entered a buffer length of %d\n", lengthofavg);
    }


  if (argc != 3 )
  {
      printf("You must enter the difficulty level on the command line.");
      refresh();
      return;
  }
  else
  {
    /* 	Setup screen for Ncurses
        The initscr functionis used to setup the Ncurses environment
        The refreash function needs to be called to refresh the outputs
        to the screen */
    initscr();
    refresh();
	//scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &t, &new_x, &new_y, &new_z, &b_up, &b_right, &b_down, &b_left);
	srand(time(0));
	

    /* WEEK 2 Generate the Maze */
	generate_maze(difficulty);
	draw_maze();
	

    /* Read gyroscope data and fill the buffer before continuing */
	for(i = 0; i < lengthofavg; i++)
    {
        scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &t, &new_x, &new_y, &new_z, &b_up, &b_right, &b_down, &b_left);
        x[i] = new_x;
        y[i] = new_y;
        z[i] = new_z;
    }
	timer = t;

    /* Event loop */
    do
    {
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &t, &new_x, &new_y, &new_z, &b_up, &b_right, &b_down, &b_left);
		draw_character(x_place, y_place, AVATAR);
		movement = calc_roll(m_avg(x, lengthofavg, new_x));
		if ((t > (timer + delay)) && (MAZE[x_place][y_place + 1] != 1)) {
			draw_character(x_place, y_place, EMPTY_SPACE);
			y_place = y_place + 1;
			draw_character(x_place, y_place, AVATAR);
			timer = t;
		}
		if ((movement > 0) && (x_place != 0) && (MAZE[x_place - 1][y_place] != 1)) {
			draw_character(x_place, y_place, EMPTY_SPACE);
			x_place = x_place - 1;
			draw_character(x_place, y_place, AVATAR);
		}
		if ((movement < 0) && (x_place != COLUMNS) && (MAZE[x_place + 1][y_place] != 1)) {
			draw_character(x_place, y_place, EMPTY_SPACE);
			x_place = x_place + 1;
			draw_character(x_place, y_place, AVATAR);
		}
		if (is_over(x_place, y_place) == 1) { 
			printf("You lose\n");
			endwin();
			printf("You lose\n");
			break;
		}

        /* Read data, update average */

        /* Is it time to move?  if so, then move avatar */

    } while(y_place != ROWS); // Change this to end game at right time

    /* Print the win message */
	if (y_place == ROWS) {
		printf("You win!\n");
		endwin();
		printf("YOU WIN!\n");
	}

    /* This function is used to cleanup the Ncurses environment.
    Without it, the characters printed to the screen will persist
    even after the progam terminates */

  }
}

double m_avg(double buffer[], int avg_size, double new_item)
{
	double sum = 0;
	int i;
	for (i = 0; i < avg_size; i++) {
		if (i < (avg_size - 1)) { 
			buffer[i] = buffer[(i+1)];
			sum = sum + buffer[i];
		}
		if (i == (avg_size - 1)) { 
			buffer[i] = new_item;
			sum = sum + buffer[i];
		}			
	}
	sum = sum / avg_size;
    return sum;
}


/* 	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y
    THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
    DO NOT NEED TO CHANGE THIS FUNCTION. */
void draw_character(int x, int y, char use)
{
    mvaddch(y,x,use);
    refresh();
}
double calc_roll(double mag){
	if( mag > 0.2) {
		return 1;
	}
	if ( mag < -0.2) {
		return -1;
	}
	else {
		return 0;
	}
}
void generate_maze(int difficulty) {
	int i;
	int j;
	int x;
	int y;
		for (i = 2; i < ROWS; i++) {
			for (j = 0; j < difficulty; j++) {
				while (y != 1){
					x = rand() % 100;
					if (MAZE[x][i] != 1) {
						MAZE[x][i] = 1;
						y = 1;
					}
				}
				y = 0;
			}
		}
}

void draw_maze(void){
	int i;
	int j;
	for (i = 0; i < COLUMNS; i++) {
		for (j = 2; j < ROWS; j++) {
			if (MAZE[i][j] == 1) {
				draw_character(i, j, WALL);
			}
		}
	}
}

double is_over(int x_place, int y_place) {
	int a = x_place;
	int b = y_place;
	int d = 0;
	int e = 0;
	while (d == 0) {
		if (MAZE[a][y_place + 1] == 1) {
			if (MAZE[a + 1][y_place] == 1) {
				d = 1;
			}
		}
		if (MAZE[a][y_place + 1] != 1) {
			return 0;
		}
		a = a + 1;
	}
	a = x_place;
	while (e == 0) {
		if (MAZE[a][y_place + 1] == 1) {
			if (MAZE[a - 1][y_place] == 1) {
				e = 1;
			}
		}
		if (MAZE[a][y_place + 1] != 1) {
			return 0;
		}
		a = a - 1;
	}
	if ((e == 1) && (d == 1)) {
		return 1;
	}
}
	