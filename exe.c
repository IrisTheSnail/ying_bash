#include<stdio.h>
#include<stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "chadstr.h"

int main(int argc, char * argv[]) {

	struct winsize w;//w.ws_col
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	//chadstr On_Green = str("\033[42m\]");
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED);
	chadstr coo = str(str("\e[48;5;022mMOIS     :     "), str(atoi(argv[1])), str("\x1B[K\n") );

	for (int i = 1; i <= w.ws_col; i++){
      	printf("\e[48;5;022m ");      	
    }
    
	printf(str(*coo));
    
	printf("\n");

	return 0;
}
