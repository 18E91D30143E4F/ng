#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102

typedef int T;

typedef struct Node_tag
{
	T info;
	struct Node_tag* next;
} Node_t;

void push(Node_t** head, T info);
Node_t* pop1(Node_t** head);
void SortStackByAdress(Node_t* srtStack);
void (*SortStackByAdres) (Node_t* srtStack);
void SortStackByData(Node_t* srtStack);
void printStack(const Node_t* head);
size_t getSize(const Node_t* head);
Node_t* swapMinAndMax(Node_t* Head);

int main()
{
	setlocale(LC_ALL, "Russian");

	Node_t* head = NULL;
	char command = '\\';
	int info;

	puts(" 1 - Добавить в стек\n 2 - Достать из стека\n 3 - Вывести стек\n 4 - Поменять местами максимальный и минимальный элементы\n 5 - Сортировка по адресу\n 6 - Сортировка по значению\n 7 - Выход\n");

	while (command != '7')
	{
		scanf_s("%1c", &command);

		switch (command)
		{
		case '1':
			puts("Введите значение");
			scanf_s("%4d", &info);
			push(&head, info);
			break;
		case '2':
			printf("%d\n", pop1(&head)->info);
			break;
		case '3':
			printStack(head);
			break;
		case '4':
			head = swapMinAndMax(head);
			printStack(head);
			break;
		case '5':
			SortStackByAdres(head);
			break;
		case '6':
			SortStackByData(head);
			break;

		default:
			break;
		}
	}

	getch();

	return 0;
}

void push(Node_t** head, T info)
{
	Node_t* tmp = malloc(sizeof(Node_t));
	if (tmp == NULL)
	{
		exit(STACK_OVERFLOW);
	}
	SortStackByAdres = SortStackByData;

	tmp->next = *head;
	tmp->info = info;
	*head = tmp;
}

Node_t* pop1(Node_t** head)
{
	Node_t* out;
	if ((*head) == NULL)
	{
		exit(STACK_UNDERFLOW);
	}
	out = *head;
	*head = (*head)->next;
	return out;
}

void SortByAdress(Node_t* srtStack)
{
	Node_t* t, * m, * a, * b;

	for (bool go = true; go; )
	{
		go = false;
		a = t = srtStack->next;
		b = srtStack->next->next;

		while (b != NULL)
		{
			if (a->info > b->info)
			{
				if (t == a)
					srtStack->next = b;
				else
					t->next = b;

				a->next = b->next;
				b->next = a;
				m = a, a = b, b = m;
				go = true;
			}
			t = a;
			a = a->next;
			b = b->next;
		}
	}
}

void SortStackByData(Node_t* srtStack)
{
	Node_t* a;
	T  tmpData;

	for (bool go = true; go; )
	{
		go = false;
		a = srtStack;

		while (a->next != NULL)
		{
			if (a->info > a->next->info)
			{
				tmpData = a->info;
				a->info = a->next->info;
				a->next->info = tmpData;
				go = true;
			}
			a = a->next;
		}
	}
}

void printStack(const Node_t* head)
{
	printf("stack > ");
	while (head) {
		printf("%d ", head->info);
		head = head->next;
	}
	printf("\n");
}

Node_t* swapMinAndMax(Node_t* Head)
{
	int MAX;
	int MIN;
	Node_t* ptr = Head;

	MIN = ptr->info;
	MAX = ptr->info;

	while (ptr) {
		if (ptr->info > MAX) {
			MAX = ptr->info;
		}
		if (ptr->info < MIN) {
			MIN = ptr->info;
		}
		ptr = ptr->next;
	}

	printf_s("Максимальное число стека: %d\n Минимальное число стека: %d\n", MAX, MIN);

	ptr = Head;

	while (ptr) {
		if (ptr->info == MAX) {
			ptr->info = MIN;
		}
		else if (ptr->info == MIN) {
			ptr->info = MAX;
		}
		ptr = ptr->next;
	}

	return Head;
}

size_t getSize(const Node_t* head)
{
	size_t size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return size;
}