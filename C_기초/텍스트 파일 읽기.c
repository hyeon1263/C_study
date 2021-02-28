#include <stdio.h>

int main()
{
	FILE *fp = NULL;
	int c;
	fp = fopen("input.txt", "r");

	if (fp == NULL)
	{
		printf("파일 열기에 실패했습니다.\n");
	}
	else
	{
		printf("파일 열기에 성공했습니다.\n");
	}

	while ((c = fgetc(fp)) != EOF) //end of file
	{
		putchar(c);
	}
	fclose(fp);

	return 0;
}