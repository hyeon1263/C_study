#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101
#define MAX_COL 6

typedef struct {
	int col;
	int row;
	int value;
}term;

void fastTranspose(term a[], term b[])
{
	int rowTerms[MAX_COL], startingPos[MAX_COL];
	int i, j, numCols = a[0].col, numTerms = a[0].value;
	b[0].row = numCols; b[0].col = a[0].row;
	b[0].value = numTerms;

	if (numTerms > 0)
	{
		for (i = 0; i < numCols; i++)
			rowTerms[i] = 0;
		for (i = 1; i <= numTerms; i++)
			rowTerms[a[i].col]++;
		startingPos[0] = 1;
		for (i = 1; i < numCols; i++)
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
		for (i = 1; i <= numTerms; i++)
		{
			j = startingPos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}
term a[MAX_TERMS];
term b[MAX_TERMS];

int main()
{
	FILE* fp1, *fp2;
	int i, j, k;
	int rows = 6, cols = 6;

	fopen_s(&fp1, "a.txt", "r"); 
	if (fp1 == NULL)
		exit(1);

	for (i = 0; i < 9; i++)
		fscanf_s(fp1, "%d %d %d", &a[i].row, &a[i].col, &a[i].value);

	fastTranspose(a, b);

	fopen_s(&fp2, "b.txt", "w"); 
	if (fp2 == NULL)
		exit(1);

	for (i = 0; i < 9; i++)
		fprintf_s(fp2, "%4d %4d %4d\n", b[i].row, b[i].col, b[i].value);

	k = 1;
	printf("A\n");
	for (i = 0; i < a[0].row; i++)
	{
		for (j = 0; j < a[0].col; j++)
		{
			if ((a[k].row == i) && (a[k].col == j))
			{
				printf("%4d", a[k].value);
				k++;
			}
			else
				printf("%4d", 0);
		}
		printf("\n");
	}

	k = 1;
	printf("B\n");
	for (i = 0; i < b[0].row; i++)
	{
		for (j = 0; j < b[0].col; j++)
		{
			if ((b[k].row == i) && (b[k].col == j))
			{
				printf("%4d", b[k].value);
				k++;
			}
			else
				printf("%4d", 0);
		}
		printf("\n");
	}

	fclose(fp1);
	fclose(fp2);

	return 0;
}