#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main()
{

	int t_fd = -1; /* Default Failed status.*/
	struct flock lock ={0};
	char t_rd_char = '\0';

	lock.l_type = F_WRLCK; 		/* read/write lock (exclusive versus shared) */
	lock.l_whence = SEEK_SET;	/* base for seek offset. */
	lock.l_start = 0;		/* 1 byte in file. */
	lock.l_len = 0;			/* 0 here means 'until EOF' */			
	lock.l_pid = getpid();		/* process id. */

	/* check file open is not-successful (open returns negative number.). */
	if((t_fd = open("sharedfile.txt",O_RDONLY)) < 0)
		perror("File open failed");
	else 
	{
		/* check file lock status is not-successful (fcntl returns negative number.). */
		fcntl(t_fd,F_GETLK,&lock);  
		if (lock.l_type != F_UNLCK)
			perror("file still lock....");

		/* file open and lock status unlocked, then read data from opened file. */
		else
		{
			printf("Reading file...\r\n");

			while(read(t_fd,&t_rd_char,sizeof(t_rd_char) > 0))
			{
				printf("%c",t_rd_char);
			}
			printf("process %d, has written data\r\n", lock.l_pid);          
		}

		/* Unlock the locked file/ releasse the lock explicitly. */
		lock.l_type = F_UNLCK;
		/* check the unlock status is success, if not succcess just print error msg, 
		* any way during file closse, unlock's the closed file automatically */
		if(fcntl(t_fd, F_SETLK,&lock)<0)
			perror("explicitly unlocking file failed.");


		if(close(t_fd) < 0)
			perror("error in closing file.");
	}



return (0);
}
