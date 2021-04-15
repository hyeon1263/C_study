#include <stdio.h>

// 2���� �迭�� ���� �迭������ ���� ���ϴ� ���α׷�
// 3���� ������ �Լ� ���� �� ����
int sumAry2D_f1(int ary[][3], int ROW, int COL);
int sumAry2D_f2(int(*ary)[3], int ROW);
int sumAry2D_f3(int ary[3][3]);

int main(void)
{
	int ary2D[][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	int ROW = 3, COL = 3;
	
	printf("sumAry2D_f1() %d\n", sumAry2D_f1(ary2D, ROW, COL));
	printf("sumAry2D_f2() %d\n", sumAry2D_f2(ary2D, ROW));
	printf("sumAry2D_f3() %d\n\n", sumAry2D_f3(ary2D));
	
	return 0;
}

int sumAry2D_f1(int ary[][3], int ROW, int COL) {
	int i, j, sum=0;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			sum += ary[i][j];
		}
	}
	return sum;
}

int sumAry2D_f2(int(*ary)[3], int ROW) {
	int i, j, sum=0;
	int col = sizeof(ary[0]) / sizeof(int);
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < col; j++)
		{
			sum += (*(ary+i))[j];
		}
	}return sum;
}
int sumAry2D_f3(int ary[3][3]) {
	int i, j, sum=0;
	int col = sizeof(ary[0]) / sizeof(int);
	int row = sizeof(*ary) / sizeof(*ary[0]);
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			sum += ary[i][j];
		}
	}return sum;
}