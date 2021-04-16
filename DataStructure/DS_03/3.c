// 구조체를 이용하여 같은 사람인지 확인하는 프로그램

#include <stdio.h>
#include <string.h>
#define FALSE 0
#define TRUE 1

typedef struct {
	char name[20];
	int age;
	int salary;
}humanBeing;

int humansEqual(humanBeing* person1, humanBeing* person2) {
	if (strcmp(person1->name, person2->name))
		return FALSE;
	if (person1->age != person2->age)
		return FALSE;
	if (person1->salary != person2->salary)
		return FALSE;

	return TRUE;
}

int main()
{
	humanBeing* person1, * person2;
	humanBeing p1, p2;
	person1 = &p1;
	person2 = &p2;

	printf("Input person1's name, age, salary : ");
	gets_s(p1.name, sizeof(p1.name));
	scanf_s("%d", &p1.age);
	scanf_s("%d", &p1.salary);
	getchar();

	printf("Input person2's name, age, salary : ");
	gets_s(p2.name, sizeof(p2.name));
	scanf_s("%d", &p2.age);
	scanf_s("%d", &p2.salary);

	if (humansEqual(person1, person2))
		printf("The two human beings are the same\n");
	else
		printf("The two human beings are not the same\n");

	return 0;
}