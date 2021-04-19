#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_TERMS 101

typedef struct {
	int col;
	int row;
	int value;
}term;

term a[MAX_TERMS];

int main()
{
	srand((unsigned)time(NULL)); 

	int i, j, n;
	int rows = 20;
	int cols = 20;
	int matrix[20][20];

	printf("원소의 개수를 쓰시오 .. ");
	scanf_s("%d", &n);
	printf("Random generated Matrix(20, 20)\n");

	for (i = 0; i < 20; i++)
		for (j = 0; j < 20; j++)
			matrix[i][j] = 0;

	for (i = 0; i < n; i++)
	{
		a[i].row = rand() % 20;
		a[i].col = rand() % 20;
		a[i].value = rand() % 100;
		if (matrix[a[i].row][a[i].col] == 0)
			matrix[a[i].row][a[i].col] = a[i].value;
		else
			i--;
	}

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			printf("%4d", matrix[i][j]);
		printf("\n");
	}

	printf("sparse matrix\n");

	for (i = 0; i < n; i++)
		printf("%4d, %4d %4d\n", a[i].row, a[i].col, a[i].value);

	return 0;
}