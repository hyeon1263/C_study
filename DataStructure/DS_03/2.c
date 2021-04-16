// 이차원 배열의 원소 개수를 입력받아 동적으로 메모리를 할당받아\
	랜덤으로 100보다 적은 값 넣기

#include <stdio.h>
#define MALLOC(p, s)\
	if ((p = malloc(s)) == NULL) { \
		fprintf(stderr, "Insufficient memory"); \
		exit(1);}

int** make2dArray(int r, int c) {
	int** x, i, j;

	MALLOC(x, r * sizeof(*x));

	for (i = 0; i < r; i++)
		MALLOC(x[i], c * sizeof(**x));
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
			*(*(x + i)+j) = rand() % 100;
	}
	
	return x;
}

int main()
{
	int** ipp;
	int i, j, rows, cols;

	printf("이차원 배열의 행과 열의 수를 입력 하세요 : ");
	scanf_s("%d %d", &rows, &cols);

	ipp = make2dArray(rows, cols);

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			printf("ipp[%d][%d] =%2d ", i, j, ipp[i][j]);
		printf("\n");
	}

	for (i = 0; i < rows; i++)    
	{
		free(ipp[i]);          
	}

	return 0;
}