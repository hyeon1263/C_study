// <time.h> 헤더파일을 이용한 선택정렬에 대한 성능측정

#include <stdio.h>
#include <time.h>
#define SWAP(x,y,t) (t=x,x=y,y=t)
#define MAX_SIZE 2001

void sort(int[], int);

int main(void)
{
	FILE* fp;
	int i, n, step = 10;
	int a[MAX_SIZE];
	double duration;
	clock_t start;
	fopen_s(&fp, "out.txt", "w");

	fprintf_s(fp, "      n      time\n");
	for (n = 0; n <= 2000; n += step)
	{
		for (i = 0; i < n; i++)
			a[i] = n - i;
	
		start = clock();
		sort(a, n);
		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
		
		fprintf_s(fp, "%6d    %f\n", n, duration);
		if (n == 100) step = 100;
	}
	fclose(fp);
	
	return 0;
}

void sort(int list[], int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], temp);
	}
}