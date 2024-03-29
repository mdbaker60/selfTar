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
	//TODO
	//This should hold everything about an input file
	//Will need to expand this and move it to a more
	//sensible place 
	int* filenum;
	char* path;
}fileNode;

//TODO: Move to help.c
char *ver_ = "0.1";
int mode = 0;
int __DEBUG = 1;
void ver(){
	printf("Version %s", ver_);
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

fileNode * getInputs(char arg[]){
	int pathLen = 0, i,n;	
	char* path = arg; 
	char * buffer;
	fileNode** ret;
	fileNode *nf = (fileNode *) malloc(sizeof (fileNode));

	//Read in a file path
	while(*(path + pathLen) != '\0'){
		pathLen++;
	}
	buffer = (char *)malloc(pathLen + 1);
	buffer[pathLen] = '\0';
	//USE STR COPY FOR THIS	
	for (n = 0; n <pathLen; n++){
		*(buffer+n) = *(path+n);
	}
	nf->path = buffer;
	nf->filenum = malloc (sizeof (int));					
	*(nf->filenum) = pathLen;

	return nf;

}

void DEBUG_printout(int count, fileNode *paths[]){
	//TODO Test struct allocation
	int i;
	printf("\nDebug Output:\n-------------");
	if (__DEBUG == 1){
		for (i = 0; i < count - 1; i++){
			printf("\nPath Length: %i\n", *(paths[i]->filenum));
			printf("Path: %s\n", paths[i]->path);
	

		}	
	}
	printf("-------------\n\n");
}

void parseArgs(int args, char* arg[]){
	//TODO 	ASSUMING AT LEAST ONE PATH GIVEN AT THIS POINT
	//	CHECK
	char *argi;
	fileNode **inputs = 0x0;

	int i;
	if (args == 1) {
		printHelp();
		__DEBUG = 0;
	}
	for (i = 1; i< args; i++){
		argi = *(arg + i);
		if (*argi == '-'){
			parseFlag(argi);
			__DEBUG = 0;
			continue;
		}

		switch(mode){
			case(0):
				mode = 1;
			case(1):
				inputs = (fileNode**) realloc(inputs, sizeof(fileNode *));//sizeof(file *));
				if (inputs == 0x0){
					printf("MALLOC FAIL\n");

				}

				inputs[i - 1] = getInputs(argi);							
				break;

			default:

				break;
		}

	}
	//DEBUG_printout(i, inputs);
	//At this point, file paths have been scanned pass to archiver
	dispatch(inputs);
}


