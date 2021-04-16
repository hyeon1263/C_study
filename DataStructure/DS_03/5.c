// 두 다항식을 입력받아 구조체를 이용하여 다항식을 더하는 프로그램 만들기 2

#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100
#define COMPARE(x,y) ((x<y)?-1:(x==y)?0:1)

typedef struct {
	int coef;
	int expon;
}polynomial;
polynomial terms[MAX_TERMS];
int avail = 0;

void printPolynomial(int start, int finish) {
	int i;
	for (i = start; i < finish; i++)
		printf("%dx^%d + ", terms[i].coef, terms[i].expon);
	
	if (terms[finish].expon == 0)
		printf("%d\n", terms[finish].coef);
	else
		printf("%dx^%d\n", terms[finish].coef, terms[finish].expon);
}

void attach(int coefficient, int exponent) {
	if (avail >= MAX_TERMS) {
		fprintf(stderr, "Too many terms in the polynomial\n");
		exit(EXIT_FAILURE);
	}
	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;
}

void padd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD) {
	float coefficient;
	*startD = avail;
	while (startA <= finishA && startB <= finishB)
		switch (COMPARE(terms[startA].expon, terms[startB].expon)) {
		case -1:
			attach(terms[startB].coef, terms[startB].expon);
			startB++;
			break;
		case 0:
			coefficient = terms[startA].coef + terms[startB].coef;
			if (coefficient)
				attach(coefficient, terms[startA].expon);
			startA++;
			startB++;
			break;
		case 1:
			attach(terms[startA].coef, terms[startA].expon);
			startA++;
		}
	for (; startA <= finishA; startA++)
		attach(terms[startA].coef, terms[startA].expon);
	for (; startB <= finishB; startB++)
		attach(terms[startB].coef, terms[startB].expon);
	*finishD = avail - 1;
}

int main()
{
	int startA, finishA, startB, finishB, startD, finishD;
	int coef, expon, i, m, n;
	char c;

	printf("<< D(x) = A(x) + B(x) >>\n");
	printf("Input the number of items of A(x) : ");
	scanf_s("%d", &m);
	printf("Input the number of items of B(x) : ");
	scanf_s("%d", &n);

	startA = 0;
	finishA = m - 1;
	startB = finishA + 1;
	finishB = startB + n - 1;
	avail = finishB + 1;

	printf("\ninput in descending order\n\n");
	printf("coefficient and exponent of A(x)=10x^5+8x^3+7 (10 5, 8 3, 7 0) : ");
	for (i = startA; i < finishA; i++)
	{
		scanf_s("%d %d %c", &coef, &expon, &c, (int)sizeof(char));
		terms[i].coef = coef;
		terms[i].expon = expon;
	}
	scanf_s("%d %d", &coef, &expon);
	terms[i].coef = coef;
	terms[i].expon = expon;

	printf("coefficient and exponent of B(x)=10x^5+8x^2+3 (10 5, 8 2, 3 0) : ");
	for (i = startB; i < finishB; i++)
	{
		scanf_s("%d %d %c", &coef, &expon, &c, (int)sizeof(char));
		terms[i].coef = coef;
		terms[i].expon = expon;
	}
	scanf_s("%d %d", &coef, &expon);
	terms[i].coef = coef;
	terms[i].expon = expon;
	printf("\n");

	padd(startA, finishA, startB, finishB, &startD, &finishD);

	printf("\nA(x) = "); printPolynomial(startA, finishA);
	printf("B(x) = "); printPolynomial(startB, finishB);
	printf("D(x) = "); printPolynomial(startD, finishD);
	
	return 0;
}