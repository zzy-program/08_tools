#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_LEN 4096

int main() {

	int fd_r, fd_w;
	char buf[BUF_LEN];
	char *p = NULL;

	printf("pid=%d\n", getpid());

	sleep(20);

	// file open
	printf("open files\n");
	fd_r = open("a.out", O_RDONLY);
	fd_w = open("test", O_CREAT | O_RDWR);

	if(fd_r < 0 || fd_w < 0) {
		printf("open file error\n");
		return -1;
	}
	else {
		printf("fd_r=%d, fd_w=%d\n", fd_r, fd_w);
	}

	// read/write
	printf("sleep...\n");
	sleep(10);
	read(fd_r, buf, BUF_LEN);
	write(fd_w, buf, BUF_LEN);

	printf("sleep...\n");
	sleep(10);
	read(fd_r, buf, BUF_LEN);

	printf("sleep...\n");
	sleep(10);
	read(fd_r, buf, BUF_LEN);

	printf("sleep...\n");
	sleep(10);
	read(fd_r, buf, BUF_LEN);

	p = malloc(BUF_LEN);
	memset(p, 0xff, BUF_LEN);

	printf("done\n");

	// release the resources
	if(fd_r > 0)
		close(fd_r);

	if(fd_w > 0)
		close(fd_w);

	if(p)
		free(p);

	return 0;
}
