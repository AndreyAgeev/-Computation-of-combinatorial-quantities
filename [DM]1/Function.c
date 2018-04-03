#include "Header.h"

void H(void)
{
	printf("U(m,n) - the number of placements\n");
	printf("A(m,n) -the number of placements without repetition\n");
	printf("P(m) - the number of permutations\n");
	printf("C(m,n) - the number of combinations\n");
	printf("S(m,n) - Stirling numbers of the second kind\n");
	printf("B(m) Bell numbers -\n");
	printf("H - getting help\n");
	printf("Q - completion of work\n");
}

int U(unsigned int m, unsigned int n, int *err)//  U(m,n) = m^n
{
	unsigned int ans = 1;
	if (m < 0 || n < 0)
	{
		*err = ERROR_NEG;
		return 0;
	}
	for (unsigned int i = 0; i < n; i++)
	{
		if (CheckInt(ans, m))
			*err = ERROR_INT;
		ans *= m;
	}
	return ans;
}

int A(unsigned int m, unsigned int n, int * err)//   A(m,n) = m!/(m-m)! = m(m-1)....(m - n + 1) 
{
	unsigned int ans = 1, i = 0;
	if (m < 0 || n < 0)
	{
		*err = ERROR_NEG;
		return 0;
	}
	if (n > m)
		return 0;
	if (n == 0)
		return 1;
	for (i = 0; i < n; i++)
	{
		if (CheckInt(ans, m - i))
			*err = ERROR_INT;
		ans *= m - i;
	}
	return ans;
}

int P(unsigned int n, int * err)//  P(n) = n!
{
	unsigned int ans, i = 1;
	ans = n;
	if (n < 0)
	{
		*err = ERROR_NEG;
		return 0;
	}
	for (i = n - 1; i > 0; i--)
	{
		if (CheckInt(ans, i))
			*err = ERROR_INT;
		ans *= i;
	}
	return ans;
}

int S(unsigned int m, unsigned int n, int * err)//  S(m,n) = S(m-1, n-1) + n * S(m-1, n) 
{
	unsigned int ans;
	unsigned int *Sp = malloc(sizeof(unsigned int) * (m + 1));
	unsigned int *Sn = malloc(sizeof(unsigned int) * (m + 1));
	unsigned int i = 0;
	
	if (m == n)
		return 1;
	if (n > m || n == 0)
		return 0;

	if (m < 0 || n < 0)
	{
		*err = ERROR_NEG;
		return 0;
	}



	for (unsigned int k = 0; k <= n; k++)
	{
		if (k == 0)
		{
			Sn[k] = 1;
			for (i = 1; i <= m; i++)
			{
				Sn[i] = 0;
			}
		}
		if (k == 1)
		{
			Sn[0] = 0;
			for (i = 1; i <= m; i++)
			{
				Sn[i] = 1;
			}
		}
		if (k >= 2)
		{
			Sn[k] = 1;
			for (i = k + 1; i <= m; i++)
			{
				if ( ((UINT_MAX / k < Sn[i - 1]) || (UINT_MAX - Sp[i - 1] < Sn[i - 1] * k)) && k == n)
				{
					*err = ERROR_INT;
					free(Sn);
					free(Sp);
					return 0;
				}
				Sn[i] = Sn[i - 1] * k + Sp[i - 1];
			}
		}


		for (i = k; i < m; i++)
			Sp[i] = Sn[i];
	}
	ans = Sn[m];
	free(Sp);
	free(Sn);
	return ans;
	
}

int get_N( int a, int b)
{
    int t;
	while (b != 0)
	{
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}
int C(unsigned int m, unsigned int n, int *err)//  C(m,n) = m!(n!*(m-n)!) = A(m,n)/ P(n)
{
	int i = 0;
	unsigned int ans1 = m;
	unsigned int ans2 = n;
	unsigned int ans = 1;
	unsigned int N, tk, tr, tm;
	if (m < 0 || n < 0)
	{
		*err = ERROR_NEG;//C(21,12)
		return 0;
	}
	if (n > m)
		return 0;

	for (unsigned i = 1; i <= n; i++, m--)
	{
		N = get_N(m, i);
		tk = i / N;
		tm = m / N;
		tr = ans / tk;
		if (CheckInt(tr, tm))
		{
			*err = ERROR_INT;
			return 0 ;
		}
		ans = tr * tm;
	}
	return ans;
}

int B(unsigned int m, int * err)// B(m) = Zi=0, m S(m,n)
{
	unsigned int ans = 0, i = 0;
	int s = 0;
	if (m == 0)
		return 1;
	if (m < 0)
	{
		*err = ERROR_NEG;
		return 0;
	}
	for (i = 0; i <= m; i++)
	{
		s = S(m, i, err);
		if (ans > UINT_MAX - s)
		{
			*err = ERROR_INT;
			return 0;
		}
		ans += s;
	}
	return ans;
}
