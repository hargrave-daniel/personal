// Lab 09 DS4Talker Skeleton Code       

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses/ncurses.h>
#include <string.h>
#define WORDLENGTH 11
#define MAXWORDS 100
#define DEBUGM 1   // Set this to 0 to disable debug output
#define AVATAR 'O' //This is avatar that helps user select word
#define EMPTY_SPACE ' ' //This is a blank space that will replace the avatar
#define COLUMNS 80 //Max length
#define ROWS 110 

char full_board[COLUMNS][ROWS];
// Reads words from the file into WL and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int read_words(char* WL[MAXWORDS], char* file_name);

// modifies str to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char* str);
void draw_character(int x, int y, char use);

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordcount;
	int i;
	int j;
	int b_up, b_right, b_down, b_left;
	int t;
	int b_1, b_2, b_3, b_4, b_5, b_6, b_7, b_8;
	int j_LX, j_LY, j_RX, j_RY;
	int x_place = 0;
	int y_place = 0;
	int timer;
	int z = 0;
	int movementx1;
	int movementy1;
	int movementx2;
	int movementy2;
	int circle = 0;
	int length[80];
	int w = 0;
	int q = 0;
	wordcount = read_words(wordlist, argv[1]);

	if (DEBUGM) {
		printf("Read %d words from %s \n", wordcount, argv[1]);
		for (i = 0; i < wordcount; i++) {
			printf("%s,", wordlist[i]);

		}
		printf("\n");
	}
	
	initscr();
    refresh();
	for (i = 0; i < 20; ++i) { //  20 because 100 is maxwords. 100/5 = 20
		for (j = 0; j < 5; j++) { // 5 because 5 columns of words
			if (z < wordcount) {
			mvprintw(i, (1+((j)*12)), "%s", wordlist[z]);
			z = z + 1;
			}
		}
	}
	refresh();
	
	while(1) {
		draw_character(x_place, y_place, AVATAR);
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &t, &b_up, &b_right, &b_down, &b_left, &b_2, &b_1, &b_3, &b_4, &b_5, &b_6, &b_7, &b_8, &j_LX, &j_LY, &j_RX, &j_RY);
		timer = t;
		// below checks the movement of the joystick and checks to see if the button relating to the circle is clicked
		if (j_LX > 50) {
			movementx1 = 1;
		}
		if (j_LX < -50) {
			movementx1 = -1;
		}
		if (j_LY > 50) {
			movementy1 = 1;
		}
		if (j_LY < -50) {
			movementy1 = -1;
		}
		if (b_right == 1) {
			circle = 1;
		}
		if (b_1 == 1) {
			w = 0;
			q = 0;
			for (i = 0; i < 80; i++) {
				mvprintw(30, i, " ");
			}
		}
			
		if (b_up == 1) {
			mvprintw(30, q, " %s", wordlist[((x_place / 12) + (y_place * 5))]);
			length[w] = 1 + strlen(wordlist[((x_place / 12) + (y_place * 5))]);
			w = w + 1;
			q = q + 1 + strlen(wordlist[((x_place / 12) + (y_place * 5))]);
		}
		if (b_left == 1) {
			mvprintw(30, q, "%s", wordlist[((x_place / 12) + (y_place * 5))]);
			length[w] = strlen(wordlist[((x_place / 12) + (y_place * 5))]);
			w = w + 1;
			q = q + strlen(wordlist[((x_place / 12) + (y_place * 5))]);
		}
		if (b_down == 1) {
			for (i = (q - length[(w - 1)]); i < q; i++) {
			mvprintw(30, i, " ");
			}
			q = q - length[(w - 1)];
			w = w - 1;
		}
		// Below puts in the movement depending n the joystick.
		// It draws an empty space where the character was then draws the avatar in the new position
		if ((movementy1 == 1) && (y_place < 20)) {
			draw_character(x_place, y_place, EMPTY_SPACE);
			y_place = y_place + 1;
			draw_character(x_place, y_place, AVATAR);
			while (t < (timer + 100)) {
				scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &t, &b_up, &b_right, &b_down, &b_left, &b_2, &b_1, &b_3, &b_4, &b_5, &b_6, &b_7, &b_8, &j_LX, &j_LY, &j_RX, &j_RY);
			}
			timer = t;
		}
		if ((movementy1 == -1) && (y_place > 0)) {
			draw_character(x_place, y_place, EMPTY_SPACE);
			y_place = y_place - 1;
			draw_character(x_place, y_place, AVATAR);
			while (t < (timer + 100)) {
				scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &t, &b_up, &b_right, &b_down, &b_left, &b_2, &b_1, &b_3, &b_4, &b_5, &b_6, &b_7, &b_8, &j_LX, &j_LY, &j_RX, &j_RY);
			}
			timer = t;
		}
		if ((movementx1 == 1) && (x_place < 48)) {
			draw_character(x_place, y_place, EMPTY_SPACE);
			x_place = x_place + 12;
			draw_character(x_place, y_place, AVATAR);
			while (t < (timer + 100)) {
				scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &t, &b_up, &b_right, &b_down, &b_left, &b_2, &b_1, &b_3, &b_4, &b_5, &b_6, &b_7, &b_8, &j_LX, &j_LY, &j_RX, &j_RY);
			}
			timer = t;
		}
		if ((movementx1 == -1) && (x_place > 0)) {
			draw_character(x_place, y_place, EMPTY_SPACE);
			x_place = x_place - 12;
			draw_character(x_place, y_place, AVATAR);
			while (t < (timer + 100)) {
				scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &t, &b_up, &b_right, &b_down, &b_left, &b_2, &b_1, &b_3, &b_4, &b_5, &b_6, &b_7, &b_8, &j_LX, &j_LY, &j_RX, &j_RY);
			}
			timer = t;
		}
		movementy1 = 0;
		movementx1 = 0;
		//while(t < (timer + 100)) {
			//scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &t, &b_up, &b_right, &b_down, &b_left, &b_1, &b_2, &b_3, &b_4, &b_5, &b_6, &b_7, &b_8, &j_LX, &j_LY, &j_RX, &j_RY);
		//}
		while((b_up != 0) || (b_right != 0) || (b_left != 0) || (b_down != 0) || (b_1 != 0)) {
			scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &t, &b_up, &b_right, &b_down, &b_left, &b_2, &b_1, &b_3, &b_4, &b_5, &b_6, &b_7, &b_8, &j_LX, &j_LY, &j_RX, &j_RY);
		}
		movementy1 = 0;
		movementx1 = 0;
	}

	// most of your code goes here. Do not forget to include the ncurses library 
	endwin();
	return 0;
}

// DO NOT MODIFY THIS FUNCTION!
void trimws(char* str) {
	int length = strlen(str);
	int x;
	if (length == 0) return;
	x = length - 1;
	while (isspace(str[x]) && (x >= 0)) {
		str[x] = '\0';
		x -= 1;
	}
}


// DO NOT MODIFY THIS FUNCTION!
int read_words(char* WL[MAXWORDS], char* file_name)
{
	int numread = 0;
	char line[WORDLENGTH];
	char *p;
	FILE* fp = fopen(file_name, "r");
	while (!feof(fp)) {
		p = fgets(line, WORDLENGTH, fp);
		if (p != NULL) 
		{
			trimws(line);
			WL[numread] = (char *)malloc(strlen(line) + 1);
			strcpy(WL[numread], line);
			numread++;
		}
	}
	fclose(fp);
	return numread;
}
//this is the draw character function from lab 8
void draw_character(int x, int y, char use)
{
    mvaddch(y,x,use);
    refresh();
}	