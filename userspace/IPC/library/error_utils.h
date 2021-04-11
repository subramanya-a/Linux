/*Filename: error_utils.h*/
#include <stdlib.h>

/*Defining prototyping for addition functionality*/
void Syslog(int lineno, const char *fname, const char *err_msg);
/*===========================================================================*/
/* Typedefs                                                                  */
/*===========================================================================*/
typedef enum 
{
	NO_ERROR = 0,
	PIPE_CREATION_FAIL = -1,
	FORK_CREATION_FAIL = -2,
	OPEN_FAILED= -3,
	CLOSE_FAILED= -4,
	READ_FAILED= -5,
	WRITE_FAILED= -6,
	MSG_QUEUE_GET_FAILED= -7,

	
}E_ERROR_NO;
/*===========================================================================*/
/* Defines                                                                   */
/*===========================================================================*/
#define ISFAILURE(X)	((0 <= X)? 1:0)
#define ASSERT(expr,ret,err_msg) \
    if (!(expr)) \
        {Syslog(__LINE__,__func__,err_msg); exit(ret);}

/*===========================================================================*/



