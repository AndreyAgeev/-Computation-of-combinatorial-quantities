#include "Header.h"



void Translation(char * str, int * c)//, const int minus)
{
	char * endptr;
	*c = (unsigned int)strtod(str, &endptr);
	free(str);
}

void CheckString(const char *s, int * err, char D, unsigned int *m, unsigned int * n)
{
	int i = 2;
	int j, k = 0;
	char * str = malloc(sizeof(char) * strlen(s));

	if (s[0] == D && s[1] == '(')
	{
		
		if (s[i] == '+')
			i++;
		else if (s[i] == '-')
		{
			*err = ERROR_NEG;
			free(str);
			return;
		}
		j = i;
		while (isNumeral(s[i]))
		{
			str[k] = s[i];
			i++;
			k++;
		}
		str[k] = '\0';
		k = 0;
		Translation(str, m);
		CheckError(err, i, j);
		if (*err != ERROR_NO)
			return;
		if (D == 'P' || D == 'B')
		{
			if (s[i] == ')');
			else
			{
				*err = ERROR_EXP;
				return;
			}
			i++;
			if (i != strlen(s) - 1)
				*err = ERROR_EXP;
			return;
		}
		if (s[i] == ',')
			i++;
		else
		{
			*err = ERROR_EXP;
			return;
		}
		str = malloc(sizeof(char) * strlen(s));
		
		if (s[i] == '+')
			i++;
		else if (s[i] == '-')
		{
			*err = ERROR_NEG;
			free(str);
			return;
		}
		j = i;
		while (isNumeral(s[i]))
		{
			str[k] = s[i];
			i++;
			k++;
		}
		str[k] = '\0';
		k = 0;
		Translation(str, n);
		CheckError(err, i, j);
		if (s[i] == ')');
		else
		{
			*err = ERROR_EXP;
			return;
		}
		i++;
		if (i != strlen(s) - 1)
			*err = ERROR_EXP;
	}
	else
	{
		*err = ERROR_EXP;
		free(str);
	}
}

void Calculation(char * s, int * err)
{
	unsigned int ans = 0;
    unsigned int m = 0, n = 0;
	unsigned int len = strlen(s);
	if (s[0] == 'U')
	{
		CheckString(s, err, s[0], &m, &n);
		if (*err != ERROR_NO)
			return;
		ans = U(m, n, err);
		if (*err == ERROR_NO)
			PrintAnswer(ans);
	}
	else if (s[0] == 'A')
	{
		CheckString(s, err, s[0], &m, &n);
		if (*err != ERROR_NO)
			return;
		ans = A(m, n, err);
		if (*err == ERROR_NO)
			PrintAnswer(ans);
	}
	else if (s[0] == 'C')
	{
		CheckString(s, err, s[0], &m, &n);
		if (*err != ERROR_NO)
			return;
		ans = C(m, n, err);
		if (*err == ERROR_NO)
			PrintAnswer(ans);
	}
	else if (s[0] == 'S')
	{
		CheckString(s, err, s[0], &m, &n);
		if (*err != ERROR_NO)
			return;
		ans = S(m, n, err);
		if (*err == ERROR_NO)
			PrintAnswer(ans);
	}
	else if (s[0] == 'P')
	{
		CheckString(s, err, s[0], &m, &n);
		if (*err != ERROR_NO)
			return;
		ans = P(m, err);
		if (*err == ERROR_NO)
			PrintAnswer(ans);
	}
	else if (s[0] == 'B')
	{
		CheckString(s, err, s[0], &m, &n);
		if (*err != ERROR_NO)
			return;
		ans = B(m, err);
		if (*err == ERROR_NO)
			PrintAnswer(ans);
	}
	else if (s[0] == 'H' && len == 2)
	{
		H();
	}
	else
		*err = ERROR_EXP;
}