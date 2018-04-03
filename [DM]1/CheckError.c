#include "Header.h"

void CheckError(int * err, int i, int j)
{
	if (j == i)
		*err = ERROR_EXP;
}


int CheckInt(unsigned int m, unsigned int n)
{
	if (m > UINT_MAX / n)
		return 1;
	return 0;
}
