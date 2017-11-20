#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} SLNode;

void initList(SLNode ** head)
{
	if ((*head = (SLNode *) malloc(sizeof(SLNode))) == NULL) {
		printf("malloc failed!");
		exit(-1);
	}
	(*head)->next = NULL;
}

void insertList(SLNode * head)
{
	int i;
	SLNode *p, *q;
	p = head;
	head->data = 1;

	for (i = 1; i < 10; i++) {
		if ((q = (SLNode *) malloc(sizeof(SLNode))) == NULL) {
			printf("malloc failed!");
			exit(-1);
		}
		p->next = q;
		q->data = i + 1;
		q->next = NULL;
		p = q;
	}
}

void displayList(SLNode * head)
{
	SLNode *p = head;
	while (p->next != NULL) {
		printf("%d\n", p->data);
		p = p->next;
	}
	printf("%d\n", p->data);
}

void setList(SLNode * head, int index, int i)
{

}

void main()
{
	SLNode *head;

	initList(&head);
	insertList(head);
	displayList(head);
//      destroyList();


}
