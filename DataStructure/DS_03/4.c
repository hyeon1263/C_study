// 두 다항식을 입력받아 구조체를 이용하여 다항식을 더하는 프로그램 만들기 1

#include <stdio.h>
#include <stdlib.h>
#define MAX_DEGREE 101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

void poly_print(char c[], polynomial);
polynomial padd(polynomial A, polynomial B);

int main()
{
	polynomial A, B, C;
	printf("<< C(x) = A(x) + B(x) >>\n");
	printf("Input the degree of items of A(x) : ");
	scanf_s("%d", &A.degree);
	printf("Input the coefficients A(x) : ");
	for (int i = 0; i <= A.degree; i++)
	{
		scanf_s("%2f", &A.coef[i]);
	}
	printf("Input the degree of items of B(x) : ");
	scanf_s("%d", &B.degree);
	printf("Input the coefficients B(x) : ");
	for (int i = 0; i <= B.degree; i++)
	{
		scanf_s("%2f", &B.coef[i]);
	}
	C.degree = max(A.degree, B.degree);
	for (int i = 0; i <= C.degree; i++)
	{
		C.coef[C.degree - i] = A.coef[A.degree - i] + B.coef[B.degree - i];
	}
	poly_print("A(x)", A);
	poly_print("B(x)", B);
	poly_print("C(x)", C);

	return 0;
}

void poly_print(char c[], polynomial p) {
	printf("%s = ", c);
	for (int i = p.degree; i > 0; i--) {
		if (!p.coef[p.degree - i]) continue;
		printf("%2.fx^%d +", p.coef[p.degree - i], i);
	}
	printf("%2.f", p.coef[p.degree]);
	printf("\n");
}