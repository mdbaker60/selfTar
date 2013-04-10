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
	int i = 1;
	char flag; 
	for (;i < argc; i++){
		flag = *(*(argv + i)+1);
		switch(flag){
			case('h'):
				printf("HELP FLAG");	
				break;	

			case('v'):
				ver();	
				printf("\n\n");
				break;


		
		}
	}
}


void ver(){
	printf("Version %s", ver_);
	//Version String
}
