#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "error_utils.h" /* Custom error logging libray */

int main(int args, char *argv[])
{
	int t_data_len = 1;
	char t_data = '\0';
	int t_ret = 0;						

	int t_fd = open("./fifofile", O_RDONLY);
	ASSERT(ISFAILURE(t_fd),OPEN_FAILED,"Error in opening the FIFO file");

	while(read(t_fd, &t_data,t_data_len) > 0)	
	{
		printf("%c",t_data);
	}

	t_ret = close(t_fd);
	ASSERT(ISFAILURE(t_ret),CLOSE_FAILED,"Error in closing the FIFO file");

	return 0;
}
