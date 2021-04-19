#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nfind(char* string, char* pat){

	int i = 0, j = 0, start = 0;
	int lasts = strlen(string) - 1;
	int lastp = strlen(pat) - 1;
	int endmatch = lastp;

	for (i = 0; endmatch <= lasts; endmatch++, start++)
	{
		if (string[endmatch] == pat[lastp])
		{
			j = 0;
			for (i = start; j < lastp && string[i] == pat[j]; i++)
				j++;
		}
		if (j == lastp)
			return start;
	}
	return -1;
}

int main()
{
	char* string = malloc(sizeof(char) * 100);
	char* pat = malloc(sizeof(char) * 100);

	int startp = 0;

	printf("���ڿ��� �Է��ϼ��� : ");
	scanf_s("%s", string, sizeof(char) * 100);
	getchar();
	printf("���� ������ �Է��ϼ��� : ");
	scanf_s("%s", pat, sizeof(char) * 100);

	startp = nfind(string, pat);

	if (startp == -1)
		printf("�Է��� ������ ���ڿ��� �����ϴ�.\n");
	else
		printf("���ڿ� %d ��°���� ������ ���۵�..\n", startp);

	free(string);
	free(pat);

	return 0;
}