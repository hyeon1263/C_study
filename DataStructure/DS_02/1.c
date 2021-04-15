// 여러 가지 함수 정의 후 구현하기

#include <stdio.h>
#include <stdlib.h>

int func1();
void func2(int *pi);
void func3(int **pi);
int func4(int s);

int main(void)
{
	int* pNum;
	char* pChar;
	int size = 100;

	pNum = func1();
	printf("%d\n", *pNum);
	
	func2(pNum);
	printf("%d\n", *pNum);

	func3(&pNum); 
	printf("%d\n", *pNum);

	pChar = func4(100);
	
	printf("입력할 문자열 : ");
	scanf_s("%s", pChar, sizeof(char)*size);
	printf("pChar contents = %s\n", pChar);
	
	free(pNum);
	free(pChar);

	return 0;
}

int func1() {
	int* pi;
	pi = (int*)malloc(sizeof(int));
	if (pi == NULL) {
		fprintf(stderr, "fail");
		exit(EXIT_FAILURE);
	}
	*pi = 10;

	return pi;
}

void func2(int *pi) {
	*pi = 100;
}

void func3(int **pi) {
	int* p;
	p = &pi;
	**pi = 200;
}

int func4(int s) {
	char* st = (char*)malloc(sizeof(char) * s);
	if (st == NULL) {
		fprintf(stderr, "fail");
		exit(EXIT_FAILURE);
	}
	return st;
}