#include <stdio.h>
#include <stdlib.h>
#include "Link_list.h"

/*�ֲ�����ԭ��*/
static void copyToNode(Item item, Node *pnode);

/*�ӿں���*/
/*����������Ϊ��*/
void InitializeList(List *plist)
{
	*plist = NULL;
}

/*��������Ƿ�Ϊ��*/
bool ListIsEmpty(const List *plist)
{
	if(plist == NULL)
		return true;
	else
		return false;
}

/*�鿴�����Ƿ�����*/
bool ListIsFull(const List *plist)
{
	Node *pt;
	bool isFull;
	pt = (Node *)malloc(sizeof(Node));
	if(pt == NULL)
		isFull = true;
	else
		isFull = false;
	free(pt);

	return isFull;
}

/*��ȡ����ǰ����*/
unsigned int ListItemCount(const List *plist)
{
	unsigned int count = 0;
	Node *scanNode;
	scanNode = *plist;
	while(scanNode !=NULL)
	{
		count++;
		scanNode = scanNode->next;
	}
    
	return count;
}

/*�ڽ�β���һ��*/
bool AddItem(Item item, List *plist)
{
	Node *newNode;
	Node *scanNode = *plist;/*����ɨ��ڵ�ָ��*/
	newNode = (Node *)malloc(sizeof(Node));
	if(newNode == NULL)
		return false;       /*�����½ڵ�����ڴ�ʧ��ʱ�˳�����*/

	copyToNode(item, newNode);/*���µ�������´����Ľڵ�*/
	newNode->next = NULL;
	
	if(scanNode == NULL)
		*plist = newNode;     /*����Ϊ�գ���newNode�ŵ�����ͷ*/
	else
	{
		while(scanNode->next != NULL)
			scanNode = scanNode->next; /*�ҵ�����Ľ�β*/
		scanNode->next = newNode;     /*���µĽڵ���ӵ������β*/
	}

	return true;

}

/*����ÿ���ڵ㲢ִ��pfunָ��ĺ���*/
void Traverse(const List *plist, void(*pfun)(Item item))
{
	Node *scanNode = *plist;/*��������Ŀ�ʼ*/
	while(scanNode != NULL)
	{
		(*pfun)(scanNode->item);/*�Ѻ���Ӧ���������ÿһ��*/
		scanNode = scanNode->next;/*ǰ������һ��*/
	}
}

/*�ͷ�malloc()*������ڴ�*/
/*��������ָ��ΪNULL*/
void EmptyList(List *plist)
{
	Node *psave = *plist;
	while(*plist != NULL)
	{
		psave = (*plist)->next; /*������һ���ڵ�ĵ�ַ*/
		free(*plist);           /*�ͷŵ�ǰ�ڵ�*/
		*plist = psave;         /*ǰ������һ���ڵ�*/
	}
}

/*�ֲ���������*/
/*��һ��������ڵ���*/
static void copyToNode(Item item, Node *pnode)
{
	pnode->item = item;
}