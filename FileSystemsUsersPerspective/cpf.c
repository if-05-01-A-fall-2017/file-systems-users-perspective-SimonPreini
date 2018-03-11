#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char* argv[]){
	int fd_from = -2;
	int fd_to = -2;
	
	if(argc == 3){
		printf("Copied\n");
		
		fd_from = open(argv[1], O_RDWR);
		fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
		
		char d[50];
		int run = 1;
		while(run != 0){
			run = read(fd_from, d, 50);
			if(run == 0){
				close(fd_from);
				close(fd_to);	
			}
			else{
				write(fd_to,d,run);
			}
		}
	}
	else
		printf("Invalid arguments\n");
	return 0;
}

