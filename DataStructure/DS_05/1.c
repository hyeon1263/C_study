//input data를 방아서 스택에 저장, 삭제 및 출력하는 프로그램
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5
#define MAX_NAME_SIZE 20
#define MAX_LEN 100

typedef struct {
	int id;
	char name[MAX_NAME_SIZE];
}element;

element stack[MAX_STACK_SIZE];

int main()
{
	FILE* fp;
	char line[MAX_LEN];
	char *tok = NULL;
	char *next_str = NULL;
	int top = -1;
	int i;

	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL)
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	printf("<< stack operations where MAX_STACK_SIZE is 5>>\n");
	printf("The format of the stack operation is as follows!!\npush 1 Jung\npop\n\n");
	printf("***************************************************\n");
	
	while (fgets(line, sizeof(line), fp))
	{
		next_str = line;
		tok = strtok_s(next_str, " \n", &next_str);
		
		if (!strcmp(tok, "push"))
		{
			top++;
			if (top >= MAX_STACK_SIZE)
			{
				top--;
				printf("stack is full, cannot add element\n");
				printf("current stack elements :\n");
				for (i = 0; i < top + 1; i++)
				{
					printf("%d %s\n", stack[top - i].id, stack[top - i].name);
				}
				break;
			}
			sscanf_s(line + strlen(tok) + 1, "%d%s", &stack[top].id, stack[top].name, sizeof(stack[top].name));
		}
		else if (!strcmp(tok, "pop"))
		{
			if (top == -1)
			{
				printf("\nstack is empty, cannot remove element\n");
				break;
			}
			top--;
		}
		else if (!strcmp(tok, "sprint"))
		{
			for (i = 0; i < top + 1; i++)
			{
				printf("%d %s\n", stack[top - i].id, stack[top - i].name);
			}
			printf("\n\n");
		}
		else if (!strcmp(tok, "quit"))
			exit(1);
		else
			printf("wrong command! try again!\n\n");
	}
	fclose(fp);

	return 0;
}