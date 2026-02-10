#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ncurses/ncurses.h>
/*
Daniel Hargrave
*/
void draw_screen(int a);

int main() {
	char round[100]; //letter table
	int r[100]; // number table
	int scores[9][2]; //highscore table scores
	char names[9][3]; //highscore table names
	int i;
	int j;
	int m = 1;
	int z;
	time_t t;
	int timer;
	int score = 0; //user score
	int x = 1; //used for knowing round
	char name[3]; //name if user wins
	char userinput; //wasd user input
	char starterinput; //pressing z to start
	FILE *outFile; //file
	//Gives instructions
	printf("Welcome to the memory game.\n");
	printf("To start the game press z.\n");
	printf("In the game, various shapes will appear with a circle around it.\n");
	printf("You must remember the shapes that circled and repeat the order.\n");
	printf("Use w for up, s for down, d for right, and a for left.\n");
	printf("\nHighscore Table:\n");
	printf("Rank Score Name\n");
	//opens file for scanning in the values from highscore table
	outFile = fopen("highscore_data.txt", "r");
	if (outFile == NULL) {
      printf("Could not open file highscore_data.txt.\n");
      return -1;
   }
   //it scans the values from the txt file into an array then prints them
   for (i = 0; i < 9; i++) {
	   fscanf(outFile, "%d %d %c %c %c", &scores[i][0], &scores[i][1], &names[i][0], &names[i][1], &names[i][2]);
	   printf(" %d   %d %d   %c %c %c\n", (i+1), scores[i][0], scores[i][1], names[i][0], names[i][1], names[i][2]);
   }
   //closes the file
   fclose(outFile);
   printf("What would you like to do?\n");
   printf("z for a game\n");
   scanf("%c", &starterinput);
   //starts up the game
   //clock() tells the current time 
   if(starterinput == 'z') {
	   t = clock();	   
	   printf("3 ...\n");
	   while (1){
		   if(clock() >= t + 300) {
			   break;
		   }
	   }	
	   printf("2 ...\n");
	   while (1){
		   if(clock() >= t + 600) {
			   break;
		   }
	   }
	   printf("1 ...\n");
	   while (1){
		   if(clock() >= t + 900) {
			   break;
		   }
	   }
   }
   //creates a random seed
   srand(time(NULL));
   //as long as the user remains correct it keeps going
   while(m == 1) {
	   //this makes the place in the array r[] a random number from 1-4
	   r[x-1] = 1 + (rand() % 4);
	   //depending on the number of r[], round[] becomes w a s or d
	   if (r[x-1] == 1) {
		   round[x-1] = 'w';
		   }
		   if (r[x-1] == 2) {
			   round[x-1] = 'a';
		   }
		   if (r[x-1] == 3) {
			   round[x-1] = 's';
		   }
		   if (r[x-1] == 4) {
			   round[x-1] = 'd';
		   }
		   //creates the lncurses screen
		   initscr();
	   //depending on the round, the loop will show the screen the correct amount of times
	   for(i = 0; i < x; i++) {
		   //refreshes the screen
		   refresh();
		   //will go into detail later. It draws the symbols though
		   draw_screen(r[i]);
		   //same as before
		   t = clock();
		   while (1){
			   if(clock() >= t + 900) {
				   break;
			   }
		   }
		   //this completely clears the lncurses screen
		   for (z = 0; z < 90; z++) {
			   for (j = 0; j < 90; j++) {
				   mvaddch(j,z,' ');
				   refresh();
			   }
		   }
	   }
	   //gets rid of lncurses
	   endwin();
	   //shows the turn, score, and asks what the answer is
	   printf("Turn: %d\n", x);
	   printf("Score: %d\n", score);
	   printf("Okay, what was the order? (Use w,a,s,d)\n");
	   
	   //makes it go for as many turns as needed
	   for(i = 0; i < x; i++) {
		   //prints turn
		   printf("%d time:\n", i + 1);
		   //scans in user input. checks if it is a valid input
		   while(1) {
			   scanf(" %c", &userinput);
			   if ((userinput == 'a') || (userinput == 's')|| (userinput == 'w') || (userinput == 'd')) {
				   break;
			   }
			   else {
					printf("Enter a s w or d\n");
			   }
		   }
		   //if userinput is correct you gain a point and it continues
		   if (userinput == round[i]) {
			   score = score + 1;
			   printf("Score: %d\n\n", score);
		   }
		   //if userinput is incorrect it ends the loop and shows you how much you got
		   if (userinput != round[i]) {
			   printf("Nope the correct answer was %c.\n", round[i]);
			   printf("Sorry, you lose, at least you got to turn %d.\n", x);
			   printf("Your final score was %d. Try again and get even higher!\n", score);
			   m = 0;
			   break;
		   }
	   }
	   //increases round
	   x = x + 1;
   }
   //This moves the array that were the high scores. If userscore is higher, it shifts everything below it down
   for (i = 8; i >= 0; i--) {
	   if(score >= (scores[i][0] * 10) + (scores[i][1])) {
		   if (i != 8) {
			   scores[i+1][0] = scores[i][0];
			   scores[i+1][1] = scores[i][1];
			   names[i+1][0] = names[i][0];
			   names[i+1][1] = names[i][1];
			   names[i+1][2] = names[i][2];
			   }
	   }
	   //once the score is lower than the next one or the score is higher than the top one, it prints a congrats message
	   if (((score < ((scores[i-1][0] * 10) + (scores[i-1][1]))) || ((i == 0) && (score >= (scores[i][0] * 10) + (scores[i][1])))) && (score >= 10 * scores[8][0] + scores[8][1])) {
		   printf("Congratulations, you made it on the highscore table!\n");
		   printf("Please enter your name (Only 3 capital letters):\n");
		   //scans in user name and changes the high score table 
		   //if there is a score that is higher
		   if (((score / 10) >= scores[i][0]) && ((score % 10) > scores[i][1])) { 
		   scanf(" %c %c %c", &names[i][0], &names[i][1], &names[i][2]);
		   scores[i][0] = score / 10;
		   scores[i][1] = score % 10;
		   }
		   //if there isnt a score that is higher
		   else {
			   scanf(" %c %c %c", &names[i+1][0], &names[i+1][1], &names[i+1][2]);
			   scores[i+1][0] = score / 10;
			   scores[i+1][1] = score % 10;
		   }
		   break;
		}
	}
	//opens the txt file for modifying it
   outFile = fopen("highscore_data.txt", "w");
   if (outFile == NULL) {
      printf("Could not open file highscore_data.txt.\n");
      return -1;
   }
   //shows the new high score table and prints the data into the file
   printf("\nHighscore Table:\n");
   printf("Rank Score Name\n");
   for (i = 0; i < 9; i++) {
	   fprintf(outFile, "%d %d %c %c %c\n", scores[i][0], scores[i][1], names[i][0], names[i][1], names[i][2]);
	   printf(" %d   %d %d   %c %c %c\n", (i+1), scores[i][0], scores[i][1], names[i][0], names[i][1], names[i][2]);
   }
   //closes the file
   fclose(outFile);
   
   return 0;
}

//draws the symbols
void draw_screen(int a) {
	int i;
	int j;
	int x;
	//the box's shape and position changes depending on the final answer
	if (a == 1) {
		for(j = 0; j < 10; j++) {
			mvaddch((3+j),(12),'*');
			mvaddch((3+j),(24),'*');
			refresh();
		}
		for(i = 0; i < 11; i++) {
			mvaddch(3,(i+13),'*');
			mvaddch(12,(i+13),'*');
			refresh();
		}
	}
	if (a == 2) {
		for(j = 0; j < 13; j++) {
			mvaddch((11+j),(3),'*');
			mvaddch((11+j),(15),'*');
			refresh();
		}
		for(i = 0; i < 11; i++) {
			mvaddch(11,(i+4),'*');
			mvaddch(23,(i+4),'*');
			refresh();
		}
	}
	if (a == 3) {
		for(j = 0; j < 10; j++) {
			mvaddch((25+j),(12),'*');
			mvaddch((25+j),(24),'*');
			refresh();
		}
		for(i = 0; i < 11; i++) {
			mvaddch(25,(i+13),'*');
			mvaddch(34,(i+13),'*');
			refresh();
		}
	}
	if (a == 4) {
		for(j = 0; j < 13; j++) {
			mvaddch((11+j),(22),'*');
			mvaddch((11+j),(34),'*');
			refresh();
		}
		for(i = 0; i < 11; i++) {
			mvaddch(11,(i+23),'*');
			mvaddch(23,(i+23),'*');
			refresh();
		}
	}
	//draws the square
	for(j = 0; j < 9; j++) {
		mvaddch((13+j),(6),'H');
		mvaddch((13+j),(12),'H');
		refresh();
	}
	for(i = 0; i < 5; i++) {
		mvaddch(13,(i+7),'H');
		mvaddch(21,(i+7),'H');
		refresh();
	}
	x = 1;
	//draws the triangle
	for(j = 0; j < 5; j++) {
		for(i = 0; i < x; i++) {
			mvaddch((j+6),(18-i),'^');
			mvaddch((j+6),(i+18),'^');
			refresh();
		}
		x = x + 1;
	}
	x = 1;
	//draws the circle
	for(j = 0; j < 4; j++) {
		mvaddch((j+13),(28+(x-1)),'A');
		mvaddch((j+13),(28-x),'A');
		x = x + 1;
		refresh();
	}
	x = 1;
	for(j = 0; j < 4; j++) {
		mvaddch((20-j),(28+(x-1)),'A');
		mvaddch((20-j),(28-x),'A');
		x = x + 1;
		refresh();
	}
	x = 0;
	//draws the x
	for(j = 0; j < 7; j++) {
		mvaddch((26+j),(15+x),'X');
		mvaddch((26+j),(21-x),'X');
		refresh();
		x = x + 1;
	}
	//refreshes the screen
    refresh();
}	


