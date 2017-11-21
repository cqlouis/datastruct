#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} SLNode;

void menu()
{
	printf("====================================\n");
	printf("======  1. 初始化链表    ===========\n");
	printf("======  2. 添加节点      ===========\n");
	printf("======  3. 显示链表元素  ===========\n");
	printf("======  4. 计算链表长度  ===========\n");
	printf("======  5. 删除节点      ===========\n");
	printf("======  6. 销毁链表      ===========\n");
	printf("====================================\n");
}

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

	printf("输入头节点的值, -1 终止输入：\n");
	scanf("%d", &(head->data));

	while (1) {
		int j;
		printf("输入节点的值, -1 终止输入：\n");
		scanf("%d", &j);
		if (j == -1)
			break;

		if ((q = (SLNode *) malloc(sizeof(SLNode))) == NULL) {
			printf("malloc failed!");
			exit(-1);
		}

		q->data = j;
		p->next = q;
		q->next = NULL;
		p = q;
	}
	printf("input finished,jump to next function.\n");
}

void displayList(SLNode * head)
{
	int i = 0;
	SLNode *p = head;
	while (p->next != NULL) {
		printf("%d --> ", p->data);
		p = p->next;
		i++;
	}
	i++;
	printf("%d\n", p->data);
	printf("如上共计 %d 个节点.\n", i);
}

//void deleteNode(SLNode * head, int index)
//{

//}

void main()
{
	system("clear");
	SLNode *head;
//	menu();
	while (1) {
		int i;
		menu();
		printf("请输入你想要的功能:");
		scanf("%d", &i);

		switch (i) {
		case 1:
			initList(&head);
			break;

		case 2:
			insertList(head);
			break;

		case 3:
			displayList(head);
			break;
		default:
			printf("error input\n");
			break;
		}
	}
}
