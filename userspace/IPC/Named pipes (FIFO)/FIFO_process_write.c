#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include "error_utils.h" /* Custom error logging libray */
/*===========================================================================*/
/* Defines                                                                   */
/*===========================================================================*/
/* process id */
#define M_FILE_PATH	"./fifofile"

#define M_FIFO_DATA_MSG	"Data is sent from process [%d]\r\n"

int main(int args, char *argv[])
{
	int t_data_len = 0;
	char t_data_buffer[50] = {0};
	int t_ret = 0;						

	if(mkfifo(M_FILE_PATH,0777) < 0)
	{
		if(errno != EEXIST)
		{
			perror("Could not open FIFO");	
			exit(PIPE_CREATION_FAIL);		
		}
	}

	printf("waiting FIFO to be opened by other process\r\n");
	int t_fd = open(M_FILE_PATH, O_WRONLY);
	ASSERT(ISFAILURE(t_fd),OPEN_FAILED,"Error in opening the FIFO file");

	t_data_len = sprintf(&t_data_buffer[0],M_FIFO_DATA_MSG,getpid());
	
	t_ret = write(t_fd, &t_data_buffer[0],t_data_len);
	ASSERT(ISFAILURE(t_ret),WRITE_FAILED,"Error in writing to the FIFO");

	t_ret = close(t_fd);
	ASSERT(ISFAILURE(t_ret),CLOSE_FAILED,"Error in closing the FIFO file");

	return 0;
}
