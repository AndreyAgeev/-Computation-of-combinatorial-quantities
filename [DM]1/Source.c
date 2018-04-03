#include "Header.h"

void Begin(void)
{	
	int c;
	char * buf = malloc(sizeof(char) * CountString);
	char * str;
	char * p;
	int err = ERROR_NO;
	int i = 0, count = 0, d = CountString;
	str = buf;
	printf("Printf:");
	while (1)
	{
		c = getc(stdin);
		if (c != ' ')
		{
			buf[i++] = (char)c;
			count++;
			if (count > CountString)
			{
				p = realloc(buf, count + d);
				if (p == NULL)
				{
					printf("Not enough Memory");
					return;
				}
				buf = p;
				d += count;
				count = 0;
			}
			if (buf[i - 1] == '\n')
			{
				err = ERROR_NO;
				buf[i] = 0;
				if (str[0] == 'Q' && strlen(str) == 2)
				{
					free(buf);
					return;
				}
				Calculation(str, &err);
				str = buf + i;
				if (err != ERROR_NO)
					PrintError(err);
				printf("\n");
				printf("Printf:");
			}
		}
		else
			continue;
	}
	buf[i - 1] = 0;
	free(buf);
}


int main()
{
	Begin();
	return 0;
}




