#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"
#include "string.h"

#define M_DATA_TO_FILE  "Shared storage data create, write and read with fcntl lock"

int main()
{

   int t_fd = -1; /* Default Failed status.*/
   struct flock lock ={0};
   
   lock.l_type = F_WRLCK; 	/* read/write lock (exclusive versus shared) */
   lock.l_whence = SEEK_SET;	/* base for seek offset. */
   lock.l_start = 0;		/* 1 byte in file. */
   lock.l_len = 0;		/* 0 here means 'until EOF' */			
   lock.l_pid = getpid();	/* process id. */

   /* check file creation is not-successful (open returns negative number.). */
   if((t_fd = open("sharedfile.txt",O_RDWR | O_CREAT,0666)) < 0)
        perror("File creation failed");
   
   /* check file lock status is not-successful (fcntl returns negative number.). */
   else if (fcntl(t_fd,F_SETLK,&lock) < 0)
        perror("fcntl faled to get lock....");

   /* file creation and lock status success, then write data to opened file. */
   else
   {
        write(t_fd,M_DATA_TO_FILE,strlen(M_DATA_TO_FILE));
        printf("process %d, has written data\r\n", lock.l_pid);          
   }

   //while(1); /* Blocking the file unlock process, to ckeck if the other process able to read the file*/
   
   /* Unlock the locked file/ releasse the lock explicitly. */
   lock.l_type = F_UNLCK;
   /* check the unlock status is success, if not succcess just print error msg, 
   * any way during file closse, unlock's the closed file automatically */
   if(fcntl(t_fd, F_SETLK,&lock)<0)
       perror("explicitly unlocking file failed.");

   
   if(close(t_fd) < 0)
       perror("error in closing file.");


   return (0);
}
