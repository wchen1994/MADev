#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifdef MYDEBUG
#define debug(S, ...) printf("[DEBUG]" #S "\n", __VA_ARGS__);
#else
#define debug(S, ...)
#endif

#define errif(M, S) if(M){printf("[ERROR]" #S "\n"); goto error;}

int create(char *fname){
	FILE *fp = fopen(fname, "w+");
	errif(fp == NULL, "Failed create file");
	fclose(fp);
	return 0;
error:
	fclose(fp);
	exit(0);
}

void printHelp(){
	FILE *fp = fopen("help", "r+");
	char strBuf[1024];
	while(fgets(strBuf, 1024, fp) != NULL){
		printf("%s", strBuf);
	}
	fclose(fp);
	exit(0);
}

int main(int argc, char *argv[]){
	if (argc > 1){
		if (strcmp(argv[1], "--help") == 0){
			printHelp();
		} else if (argv[1][0] == '-'){
			char *param;
			if (strlen(argv[1]) == 2 && argc > 2){
				param = argv[2];
			} else if (strlen(argv[1]) > 2){
				param = argv[1]+2;
			} else {
				printHelp();
			}
			char opt = argv[1][1];
			debug("Option:\t%c",opt); 
			debug("Param:\t%s", param);
			switch(opt){
				case 'c':
					create(param);
					break;

				case 's':
					break;

				default:
					printHelp();
			}
		}
	} else {
		printHelp();
	}

	return 0;
}
