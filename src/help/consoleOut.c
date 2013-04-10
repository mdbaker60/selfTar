//Console help library
//Add help print stuff here
#include "help.h"
char *ver_ = "0.1";
//Generic help message print.
void printHelp(){
	printf("ARCHIVER - ");
	ver();
	printf("%c", '\n');
}


//Read flags and dispatch proper help message
void parseFlg(int argc, char** argv){
	printf("Reading Flags\n");	
	int i = 1;
	for (;i < argc; i++){
		//printf("FLAG: %c\n", ( *(*(argv + i)+1) ) );
		char flag = *(*(argv + i)+1);
		switch(flag){
			case('h'):
				printf("HELP FLAG");	
			
			break;


		}
	}
}


void ver(){
	printf("%s", ver_);
	//Version String
}
