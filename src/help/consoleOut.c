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
	printf("Reading Flags");	
	int i = 1;
	for (i; i <=argc; i++){
		printf("%s", (*(argv + argc)));
		switch(argc){
			case(1):
				
			
			break;


		}
	}
}


void ver(){
	printf("%s", ver_);
	//Version String
}
