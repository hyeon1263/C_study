// 선택정렬으로 정렬 후 이진탐색으로 데이터 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 100
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define COMPARE(x,y) (((x)<(y)) ? -1: ((x)==(y))? 0: 1)

void sort(int[], int);
// 선택정렬 (selection sort)를 수행하는 프로그램
int binsearch(int list[], int searchnum, int left, int right);
// 이진탐색 (binary search)을 수행하는 프로그램

int main(void)
{
	int i, n, searchnum, ans;
	int list[MAX_SIZE];
	printf("Enter the number of numbers to generate: ");
	scanf_s("%d", &n);
	if (n<1 || n>MAX_SIZE)
	{
		fprintf(stderr, "Improper value of n\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < n; i++)
	{
		list[i] = rand() % 1000;
		printf("%d  ", list[i]);
	}
	sort(list, n);
	printf("\n\nSorted array:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d  ", list[i]);
	}
	printf("\n\nEnter the number to search: ");
	scanf_s("%d", &searchnum);
	ans = binsearch(list, searchnum, 0, n-1);
	printf("The seach number is present in list[%d]", ans);

	return 0;
}

void sort(int list[], int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (list[j] < list[min])
				min = j;

		}
		SWAP(list[i], list[min], temp);
	}
}

int binsearch(int list[], int searchnum, int left, int right) {
	int middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (searchnum < list[middle])
			right = middle - 1;
		else if (searchnum == list[middle])
			return middle;
		else
			left = middle + 1;
	}
	return -1;
}
