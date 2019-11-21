#include <stdio.h>
#include <stdlib.h>
#include "Link_list.h"

/*局部函数原型*/
static void copyToNode(Item item, Node *pnode);

/*接口函数*/
/*把链表设置为空*/
void InitializeList(List *plist)
{
	*plist = NULL;
}

/*检查链表是否为空*/
bool ListIsEmpty(const List *plist)
{
	if(plist == NULL)
		return true;
	else
		return false;
}

/*查看链表是否已满*/
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

/*获取链表当前项数*/
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

/*在结尾添加一项*/
bool AddItem(Item item, List *plist)
{
	Node *newNode;
	Node *scanNode = *plist;/*设置扫描节点指针*/
	newNode = (Node *)malloc(sizeof(Node));
	if(newNode == NULL)
		return false;       /*创建新节点分配内存失败时退出函数*/

	copyToNode(item, newNode);/*将新的项拷贝到新创建的节点*/
	newNode->next = NULL;
	
	if(scanNode == NULL)
		*plist = newNode;     /*链表为空，将newNode放到链表开头*/
	else
	{
		while(scanNode->next != NULL)
			scanNode = scanNode->next; /*找到链表的结尾*/
		scanNode->next = newNode;     /*将新的节点添加到链表结尾*/
	}

	return true;

}

/*访问每个节点并执行pfun指向的函数*/
void Traverse(const List *plist, void(*pfun)(Item item))
{
	Node *scanNode = *plist;/*设置链表的开始*/
	while(scanNode != NULL)
	{
		(*pfun)(scanNode->item);/*把函数应用于链表的每一项*/
		scanNode = scanNode->next;/*前进到下一项*/
	}
}

/*释放malloc()*分配的内存*/
/*设置链表指针为NULL*/
void EmptyList(List *plist)
{
	Node *psave = *plist;
	while(*plist != NULL)
	{
		psave = (*plist)->next; /*保存下一个节点的地址*/
		free(*plist);           /*释放当前节点*/
		*plist = psave;         /*前进至下一个节点*/
	}
}

/*局部函数定义*/
/*把一个项拷贝到节点中*/
static void copyToNode(Item item, Node *pnode)
{
	pnode->item = item;
}