// ������ �迭�� ���� ������ �Է¹޾� �������� �޸𸮸� �Ҵ�޾�\
	�������� 100���� ���� �� �ֱ�

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

	printf("������ �迭�� ��� ���� ���� �Է� �ϼ��� : ");
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