//Console dispatch
//Add help print stuff here

//TODO: Line scanning isn't that robust yet.
//	For now, assume no flags occur after
//	the first path is given and that the
//	last path is the output file

#include "consio.h"
#include <stdlib.h>
typedef struct
{
	//TODO For now just a node in a linked 
	//list of file names. Expand to hold file
	//details
	
	int filenum;
	char* path;
}file;

//TODO: Move to help.c
char *ver_ = "0.1";
int mode = 0;
void ver(){
	printf("Version %s", ver_);
	//Version String
}

//TODO: Move to help.c
//Generic help message print.
void printHelp(){
	printf("ARCHIVER - ");
	ver();
	printf("\n");
}

//Read flags and dispatch proper help message
void parseFlag(char* argv){
	int i = 1;
	char flag = *(argv + 1); 
	switch(flag){
		case('h'):
			helpMain();	
			return;

		case('v'):
			ver();	
			printf("\n\n");
			break;
		default:
			printf("ARCHIVER: invalid option\n\n");
	}
}

file * getInputs(char* arg[]){
	//get list of input paths
	printf("IN INPUTS\n");
	int pathLen = 0, i,n;	
	char* path = arg[0]; 
	char * buffer;
	file** ret;
	file *nf = (file *) malloc(sizeof (file));
	//Read in a file path
	while(*(path + pathLen) != '\0'){
		pathLen++;
	}
	
	buffer = (char *)malloc(pathLen + 1);
	
	for (n = 0; n <pathLen; n++){
		*(buffer+n) = *(path+n);
	}

	nf->path = buffer;
	nf->filenum = i;					


	return nf;

}

void parseArgs(int args, char* arg[]){
	//TODO 	ASSUMING AT LEAST ONE PATH GIVEN AT THIS POINT
	//	CHECK
	char *argi;
	file **inputs;
	


	int i;
	if (args == 1) printHelp();
	for (i = 1; i< args; i++){
		argi = *(arg + i);
		if (*argi == '-'){
			parseFlag(argi);
		}

		switch(mode){
			case(0):
				mode = 1;
			case(1):
				printf("READING PATH SIZEOF:%i\n", sizeof(file *));
				inputs = (file**) realloc(inputs, sizeof(file *));
				if (inputs == 0x0){
					printf("MALLOC FAIL\n");

				}
				inputs[i - 1] = getInputs(arg + i);								
				break;

			default:
				break;
		}

	}
}


