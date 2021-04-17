// 일차원 배열의 원소 개수를 입력받아 동적으로 메모리를 할당받아\
	랜덤으로 100보다 적은 값 넣는 

#include <stdio.h>
#define MALLOC(p, s)\
	if ((p = malloc(s)) == NULL) { \
		fprintf(stderr, "Insufficient memory"); \
		exit(1);}

int* make1dArray(int R) {
	int* p;
	int i;

	MALLOC(p, (sizeof(int) * R));

	for (i = 0; i < R; i++)
	{
		for (i = 0; i < R; i++)
			*(p + i) = rand() % 100;
	}
	return p;
}

int main()
{
	int* ipp;
	int i, num;

	printf("일차원 배열의 수를 입력하세요: ");
	scanf_s("%d", &num);

	ipp = make1dArray(num);
	for (i = 0; i < num; i++)
	{
		printf("ipp[%2d] =%2d ", i, ipp[i]);
		if ((i % 5) == 4)
			printf("\n");
	}
	free(ipp);

	return 0;
}
