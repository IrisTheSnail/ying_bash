#include<stdio.h>
#include<stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sqlite3.h>
#include "chadstr.h"

void callback();


int openyyy(){
	sqlite3 *db;
	char *zErrMsg = 0;
   	int rc;
   	rc = sqlite3_open("test.db", &db);
   	if( rc ) {
      	fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      	return(0);
   	} else {
      	fprintf(stderr, "Opened database successfully\n");
      	
   	}
	//i don't remember this db shit well so it s time to test stuff
	//ghadi tdor kssayd haha

	char *sql = "CREATE TABLE salats( \
	   		ID INTEGER NOT NULL, \
	   		type VARCHAR(10), \
	   		datetime INTEGER NOT NULL, \
	   		state VARCHAR(20), \
	   		PRIMARY KEY( ID ), \
	   		CONSTRAINT which_type FOREIGN KEY (type) \
	   		REFERENCES types(name) \
	   		CONSTRAINT which_state FOREIGN KEY (state) \
	   		REFERENCES states(name) \
	   		); \
	   	CREATE TABLE types ( \
	   	    name VARCHAR(10) NOT NULL, \
	   	    PRIMARY KEY (name) \
			); \
		CREATE TABLE states ( \
			name VARCHAR(20) NOT NULL, \
	   	    PRIMARY KEY (name) \
			); \
		COMMIT;";
   	rc = sqlite3_exec(db, sql, callback, &zErrMsg);
   	   
   	   if( rc != SQLITE_OK ){
   	      fprintf(stderr, "SQL error: %s\n", zErrMsg);
   	      sqlite3_free(zErrMsg);
   	   } else {
   	      fprintf(stdout, "haha it s ficking there!!\n");
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


