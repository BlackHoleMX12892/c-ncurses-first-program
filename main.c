#include <ncurses.h>
#include <string.h>
#include <stdio.h>

int handleData(char inputText[]) {
	FILE *fptr;

	fptr = fopen("OutputFile.txt", "w");
	fprintf(fptr, "The user wrote: %s", inputText);
	fclose(fptr);

	return 0;
}

int main() {
	int row, col;
	char textstring[]="Hello world! From ncurses > ";
	char textinput[80];

	initscr();
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	getmaxyx(stdscr, row, col);
	mvprintw(row/2, col/2-strlen(textstring), "%s", textstring);

	getstr(textinput);
	mvprintw(LINES - 2, 0, "Some text for you written by you: %s", textinput);

	refresh();
	getch();
	handleData(textinput);
	endwin();

	return 0;
}
