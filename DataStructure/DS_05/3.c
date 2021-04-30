//input data를 입력받아 환형 큐에 데이터를 저장, 삭제 및 출력하는 프로그램
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 3
#define MAX_NAME_SIZE 20
#define MAX_LEN 100

typedef struct {
	int id;
	char name[MAX_NAME_SIZE];
}element;

element queue[MAX_QUEUE_SIZE];

int main()
{
	FILE* fp;
	char line[MAX_LEN];
	char* tok;
	char* next_str;
	int temp;
	int rear = 0;
	int front = 0;

	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL)
	{
		fprintf(stderr, "cannot open file");
		exit(EXIT_FAILURE);
	}
	printf("<< Circular queue operations where MAX_QUEUE_SIZE is 3>>\n");
	printf("add 1 Jung \n");
	printf("delete\n\n");
	printf("**************************************************\n");

	while (fgets(line, sizeof(line), fp))
	{
		next_str = line;
		tok = strtok_s(next_str, " \n", &next_str);
		if (!strcmp(tok, "add"))
		{
			temp = rear;
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			
			if (rear == front)
			{
				rear = temp;
				printf("queue is full, not added\n");
			}
			else
				sscanf_s(line + strlen(tok) + 1, "%d%s", &queue[rear].id, queue[rear].name, sizeof(queue[rear].name));
		}
		else if (!strcmp(tok, "delete"))
		{
			if (front == rear) 
			{
				printf("queue is empty\n");
				break;
			}
			front = (front + 1) % MAX_QUEUE_SIZE;
		}
		else if (!strcmp(tok, "qprint"))
		{
			if (front < rear)
			{
				for (int i = front + 1; i <= rear; i++)
					printf("%d, %s\n", queue[i].id, queue[i].name);
				printf("\n\n");
			}
			else if (rear < front)
			{
				for (int i = 0; i <= rear; i++)
					printf("%d, %s\n", queue[i].id, queue[i].name);
				printf("\n");
			}
		}
		else if (!strcmp(tok, "quit"))
			exit(1);
		else
			printf("wrong command! try again!\n");
	}
	fclose(fp);

	return 0;
}
