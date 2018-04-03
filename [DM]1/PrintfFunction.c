#include "Header.h"

void PrintError(const int err)
{
	switch (err)
	{
	    case(ERROR_EXP):
		    printf("Error: invalid expression");
		    break;
	    case(ERROR_LESS):
		    printf("Error: m can not be greater than n");
		    break;
	    case(ERROR_ZERO):
		    printf("Error: m or n is 0");
		    break;
	    case(ERROR_NEG):
		    printf("Error: negative m and n");
		    break;
	    case(ERROR_INT):
		    printf("Error: Overflow Int");
		    break;
	}
}

void PrintAnswer(const  unsigned int ans)
{
	printf("Answer is %u", ans);
}
