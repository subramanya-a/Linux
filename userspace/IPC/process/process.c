#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
/*
*	Creating 2 process, 1 parent and 1 child process.
*	Child are created when fork(); is invoked, return child process id (In short: pid) 
*	Child process are invoked from some parent, this parend process id is obtained by getppid. 
*/
void ParentProcess(void);
void ChildProcess(void);

int main()
{

	pid_t t_pid = fork();

	if (t_pid < 0)
	{
		printf("Process creation failed: [%d]\n",getpid());
	}
	else 
	{
		if (t_pid == 0)
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
	printf("Hello from child process (%d), invoked from parent process (%d)\n",getpid(),getppid());
}

void ParentProcess(void)
{
	/* wait till child process execute, 
	* if parent process exits before child process child parend id will be assigned junk (ie, some parent id).
	**/
	wait(NULL);			
	printf("Hello from parent process (%d), invoked from parent process (%d)\n",getpid(),getppid());
}
