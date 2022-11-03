#include<stdio.h>
#include<stdlib.h>
#include "chadstr.h"

int main(int argc, char * argv[]) {

	system("printf '\e[48;5;022m\033[39m'");
	//chadstr On_Green = str("\033[42m\]");
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED);
	chadstr coo = str(str("MOIS:"), str(atoi(argv[1]), "\n"), str("\n"));
	printf(str(*coo));

	for (int i = 1; i <= 30; i++){
      	printf("%d|", i);
      	
    }
    system("pwd");
	printf("\n");
	return 0;
}
