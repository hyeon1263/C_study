// ������ �迭�� ���� ������ �Է¹޾� �������� �޸𸮸� �Ҵ�޾�\
	�������� 100���� ���� �� �ֱ�

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

	printf("������ �迭�� ���� �Է��ϼ���: ");
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