#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	const int SIZE = 4096;
	const char *name = "OS";
	const char *msg_0 = "Hello,";
	const char *msg_1 = "World!";

	/* shared memory file descriptor */
	int fd;
	/* pointer to shared memory object */
	char *ptr;

	/* Creating shared memory object */
	fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	ftruncate(fd, SIZE);

	/* memory map the shared memory object */
	ptr = (char *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	sprintf(ptr, "%s", msg_0);
	ptr += strlen(msg_0);
	sprintf(ptr, "%s", msg_1);
	ptr += strlen(msg_1);

	return 0;
}
