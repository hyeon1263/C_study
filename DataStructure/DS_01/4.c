#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 100
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define COMPARE(x,y) (((x)<(y)) ? -1: ((x)==(y))? 0: 1)

void sort(int[], int);
int binsearch(int list[], int searchnum, int left, int right);
// 재귀적 방법을 사용한 이진탐색함수 정의

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
	if (left <= right) {
		printf("call binsearch_recur, left=%d, right=%d\n", left, right);
		middle = (left + right) / 2;
		switch (COMPARE(list[middle], searchnum)) {
		case -1:
			return binsearch(list, searchnum, middle + 1, right);
		case 0: 
			return middle;			
		case 1:
			return binsearch(list, searchnum, left, middle - 1);
			
		}
	}
	return -1;
}