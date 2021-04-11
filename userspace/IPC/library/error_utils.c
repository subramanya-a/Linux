/* Filename: addition-library.c */
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void Syslog(int lineno, const char *fname, const char *err_msg)
{
    /* To be implemented */
    char t_debug_b[100] = {0};
    sprintf(t_debug_b,"\r\nFAILED:\n\
	LINE    :%d\n\
	Function:%s\n\
	MSG     :%s\n",lineno,fname,err_msg);
    perror(t_debug_b);
	
}
