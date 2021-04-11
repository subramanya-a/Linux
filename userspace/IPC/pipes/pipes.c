#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "error_utils.h"/* Custom error logging libray */
/* ----------------------------------------------------------------------------
 * Pipes work in along with fork(), hence the communication is always between
 * processes belonging to the same process tree.
 *
 * Pipes are unidirectional communication channel.
 *
 * Pipes do not persist after the termination of the process tree.
 *
 */
/*===========================================================================*/
/* Typedefs                                                                  */
/*===========================================================================*/
typedef enum 
{
	PIPE_READ = 0,
	PIPE_WRITE
}E_PIPE_WR_INDEX;

/*===========================================================================*/
/* Defines                                                                   */
/*===========================================================================*/
/* process id */
#define M_CHILD_PROCESS_ID	(0UL)

#define M_STR_CHILD_PROCESS_MSG	"Data is sent from child process [%d]\r\n"

/*===========================================================================*/
/* Globals                                                                   */
/*===========================================================================*/
static int pipe_fd[2] = {0};
// pipe_fd[0] = Read end
// pipe_fd[1] = Write end
/*===========================================================================*/
/* Prototypes                                                                */
/*===========================================================================*/
void ParentProcess(void);
void ChildProcess(void);
/*===========================================================================*/

int main(int args, char *argv[])
{

	if(0 < pipe(pipe_fd))
	{
		perror("pipes creation failed");
		exit(PIPE_CREATION_FAIL);
	}
	
	/* Creating the child process */
	pid_t t_pid = fork();
	if (t_pid < 0)
	{
		printf("Process creation failed: [%d]\n",t_pid);
		exit(FORK_CREATION_FAIL);
	}
	else 
	{
		if (t_pid == M_CHILD_PROCESS_ID)
		{			
			ChildProcess();
		}
		else 
		{
			ParentProcess();							
		}
	}

	return 0;
}

void ChildProcess(void)
{
	int t_data_len = 0;
	int t_ret = 0;
	char t_data_buffer[50] = {0};
	
	printf("Hello from child process (%d), invoked from parent process (%d)\n",getpid(),getppid());
	/* As this process we are going to writing, we are going to close read end of pipe, before writing*/
	t_ret = close(pipe_fd[PIPE_READ]);
	ASSERT(ISFAILURE(t_ret),CLOSE_FAILED,"Error in closing the read end of the pipe");


	t_data_len = sprintf(&t_data_buffer[0],M_STR_CHILD_PROCESS_MSG,getpid());
	
	if( 0 < t_data_len)
	{
		t_ret = write(pipe_fd[PIPE_WRITE],&t_data_buffer[0],t_data_len);
		//printf("t_ret:%d\n",t_ret);
		ASSERT(ISFAILURE(t_ret),WRITE_FAILED,"Error in writing to the pipe");
	}
	t_ret = close(pipe_fd[PIPE_WRITE]);
	ASSERT(ISFAILURE(t_ret),CLOSE_FAILED,"Error in closing the write end of the pipe");
}

void ParentProcess(void)
{
	char t_char_data = 0;
	int t_ret = 0;

	/* wait till child process execute, 
	* if parent process exits before child process child parend id will be assigned junk (ie, some parent id).
	* child process memory will not be cleared
	**/
	wait(NULL);			
	printf("Hello from parent process (%d), invoked from parent process (%d)\n",getpid(),getppid());

	/* As this process we are going to read, we are going to close write end of pipe, before reading*/
	t_ret = close(pipe_fd[PIPE_WRITE]);
	ASSERT(ISFAILURE(t_ret),CLOSE_FAILED,"Error in closing the write end of the pipe");

	while((t_ret = read(pipe_fd[PIPE_READ],&t_char_data,1)) > 0)			
		printf("%c",t_char_data);
	
	t_ret = close(pipe_fd[PIPE_READ]);
	ASSERT(ISFAILURE(t_ret),CLOSE_FAILED,"Error in closing the read end of the pipe");
}
