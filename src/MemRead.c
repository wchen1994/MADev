#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
//#include <sys/types.h>
//#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/ptrace.h>

#define debug(M, ...) if(!(M)){printf("[DEBUG]" __VA_ARGS__);printf("\n");}

int main(){
	char fname[64];
	long pid;
	printf("Input the pid of the viewed process\n");
	scanf("%ld", &pid);
	sprintf(fname, "/proc/%ld/mem", pid);
	int fd = open(fname, O_RDWR);
	debug(fd > 0, "fd is %d", fd);

	long rc;
	rc = ptrace(PTRACE_ATTACH, pid, 0, 0);
	debug(rc >= 0, "ptrace returned %ld", rc);

	rc = waitpid(pid, NULL, 0);
	debug(rc > 0, "ptrace returned %ld", rc);

	off_t addr;
	printf("Input the memory address to be read\n");
	scanf("%ld", &addr);

	int size;
	printf("Input the size of memeory to be read\n");
	scanf("%d", &size);
	if (size > 0){
		char *value = malloc(size);
		pread(fd, value, size, addr);
		//pwrite(fd, value, size, addr);
		int i;
		for (i=0; i<size; i++){
			printf("%d ", value[i]);
			if (i%32 == 31){
				printf("\n");
			}
		}
		printf("\n");
	} else {
		int bufferSize = 1024;
		char *value = malloc(bufferSize);
		int byteRead;
		do{
			byteRead = pread(fd, value, bufferSize, addr);
			int i;
			for(i=0; i<byteRead; i++){
				printf("%c", value[i]);
			}
			addr += byteRead;
		} while ( byteRead > 0);
	}

	ptrace(PTRACE_DETACH, pid, 0, 0);

	close(fd);

	return 0;
}
