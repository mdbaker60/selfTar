//Main file
//Invoke from here
#include"main.h"

int main (int argc, char *argv[]){
	//TODO
	//read input
	//generate destination
	//
	//copy contents of each input item

	if (argc < 2){
		printHelp();
	}
	
	else if (*(argv+1) == "-"){
		printf("%c", **(argv + 1) );	
		parseFlg(argc, argv);
	}	
	
	
	return 0;
}


