#include <stdio.h>
#include <string.h>

int main()
{
	FILE* fp;
	char fname[256];
	char buffer[256];
	char word[256];
	int line = 0;

	printf("파일 이름을 입력하세요: ");
	scanf("%s", fname);
	printf("탐색할 단어를 입력하세요: ");
	scanf("%s", word);

	if ((fp = fopen(fname, "r")) == NULL)
	{
		fprintf(stderr, "파일 %s을 열 수 없습니다.\n", fname);
		return 0;
	}
	
	while (fgets(buffer, 256, fp)) //buffer에 256만큼을 읽어서 담아준다
	{
		line++;
		if (strstr(buffer, word)) //word가 buffer에 포함되어 있는지/아닌지
		{
			printf("라인 %d: 단어 %s이(가) 발견되었습니다.\n", line, word);
		}
	}

	return 0;
}