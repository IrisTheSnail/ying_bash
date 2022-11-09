#include<stdio.h>
#include<stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sqlite3.h>
#include "chadstr.h"

int main(int argc, char * argv[]){
	sqlite3 *db;
	char *zErrMsg = 0;
	rc = sqlite3_open("test.db", &db);
   	if( rc ) {
      	fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      	return(0);
   	} else {
      	fprintf(stderr, "Opened database successfully\n");
      	
   	}

   	//if the date/time is a string.... how to 

   	char * sql = "Insert "
	return 0;
}
