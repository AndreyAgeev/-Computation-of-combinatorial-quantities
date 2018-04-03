#pragma once
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define CountString 80
#define isNumeral(c) (c >= '0' && c <= '9')

enum ERROR
{
	ERROR_NO,
	ERROR_EXP,
	ERROR_LESS,
	ERROR_ZERO,
	ERROR_NEG,
	ERROR_INT
};

void PrintError(const int);
void PrintAnswer(const unsigned  int );
void Translation(char *, int *);
void CheckString(const char *, int * , char , unsigned int *, unsigned int * );
void Calculation(char * , int * );
void Begin(void);
void CheckError(int *, int, int);
int CheckInt(unsigned int , unsigned int );
void H(void);
int U(unsigned int , unsigned int , int *);// число размещений U(m,n) = m^n
int A(unsigned int , unsigned int , int *);// число размещений без повторений  A(m,n) = m!/(m-m)! = m(m-1)....(m - n + 1) 
int P(unsigned int , int * );// число перестановок P(n) = n!
int S(unsigned int , unsigned int , int * );// число Стирлинга второго рода S(m,n) = S(m-1, n-1) + n * S(m-1, n) //НЕ РОБИТ
int C(unsigned int, unsigned  int, int *);// число сочетаний C(m,n) = m!(n!*(m-n)!) = A(m,n)/ P(n)
int B(unsigned int , int * );// число белла B(m) = Zi=0, m S(m,n)
