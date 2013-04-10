//Main file
//Invoke from here
#include"main.h"

int main (int argc, char *argv[]){
	//TODO
	//read input
	//generate destination
	//
	//copy contents of each input item
	//printf("%i", argc);	
	if (argc <= 2){
		printHelp();
	}
	
	else if (*(argv+1) == "-"){
		parseFlg(argv);
	}	
	
	
	return 0;
}


