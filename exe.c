#include<stdio.h>
#include<stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sqlite3.h>
#include "chadstr.h"

int openyyy(){
	sqlite3 *db;
   	
   	int rc;

   	rc = sqlite3_open("test.db", &db);

   	if( rc ) {
      	fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      	return(0);
   	} else {
      	fprintf(stderr, "Opened database successfully\n");
   	}
   	sqlite3_close(db);
}

int main(int argc, char * argv[]) {

	struct winsize w;//w.ws_col
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	//chadstr On_Green = str("\033[42m\]");
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED);
	chadstr coo = str(str("\e[48;5;022m  "), str(atoi(argv[1])), str("\x1B[K\n") );

	for (int i = 1; i <= w.ws_col; i++){
      	printf("\e[48;5;022m ");
    }

	printf(str(*coo));
	int cc = (w.ws_col/3);
	if(atoi(argv[2]) >= cc){
		for(int j = 1 ; j <= atoi(argv[2]) ; j++){
			if(j >= 0 && j < 10){printf("0%d|", j);}
			else{printf("%d|", j);}
		}
    }
	printf("\n");

	openyyy();
	return 0;
}


