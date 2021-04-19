#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
#define MAX_SIZE 100

int failure[MAX_SIZE];

int pmatch(char* string, char* pat)
{
	int i = 0, j = 0;
	int lens = strlen(string);
	int lenp = strlen(pat);

	while (i < lens && j < lenp){
		if (string[i] == pat[j])
		{
			i++; j++;
		}
		else if (j == 0)
			i++;
		else
			j = failure[j - 1] + 1;
	}
	return ((j == lenp) ? (i - lenp) : -1);
}

void fail(char* pat)
{
	int n = strlen(pat);
	int i, j;
	failure[0] = -1;

	for (j = 1; j < n; j++) {
		i = failure[j - 1];
		while ((pat[j] != pat[i + 1]) && (i >= 0))
			i = failure[i];
		if (pat[j] == pat[i + 1])
			failure[j] = i + 1;
		else
			failure[j] = -1;
	}
}

int main()
{
	char string[MAX_SIZE];
	char pat[MAX_SIZE];
	int startp;

	printf("문자열을 입력하세요 : ");
	scanf_s("%s", string, sizeof(string));
	getchar();
	printf("비교할 패턴을 입력하세요 : ");
	scanf_s("%s", pat, sizeof(pat));

	fail(pat);
	startp = pmatch(string, pat);
	printf("pat의 위치 정보 값\n");
	for (int i = 0; i < strlen(pat); i++)
	{
		printf("failure[%d]= %4d  ", i, failure[i]);
		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n");

	if (startp == -1)
		printf("문자열에서 해당 패턴을 발견할 수 없습니다.");
	else
		printf("문자열 %d 번째부터 패턴이 시작됨..\n", startp);

	return 0;
}