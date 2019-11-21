/*Link_List.h--简单链表类型的头文件*/
#ifndef LINK_LIST_H_
#define LINK_LIST_H_

/*特定程序的声明*/

#define TSIZE        40   /*储存电影名的数组大小*/
struct film 
{
	char title[TSIZE];
	int rating;
};

/*一般类型定义*/

typedef struct film Item;

typedef struct node
{
	Item item;
	struct node *next;
}Node, *List;

/*函数原型*/

/*操作：       初始化一个链表                                                       */
/*前提条件：   plist指向一个链表                                                    */
/*后置条件：   初始化链表为空                                                       */
void InitializeList(List *plist);

/*操作：       确定链表是否为空，plist指向一个已经初始化的链表						*/
/*后置条件：   如果链表为空，返回true；否则返回false								*/
bool ListIsEmpty(const List *plist);

/*操作：       确定链表是否已满，plist指向一个已经初始化的链表						*/
/*后置条件：   如果链表已满，返回true；否则返回false								*/
bool ListIsFull(const List *plist);

/*操作：       确定链表中的项数，plist指向一个已经初始化的链表						*/
/*后置条件：   该函数返回链表中的项数												*/
unsigned int ListItemCount(const List *plist);

/*操作：       在链表的末尾添加一个项                                                */
/*前提条件：   item是一个待添加至链表的项，plist指向一个初始化的链表                 */
/*后置条件：   添加成功返回true，失败则返回false                                     */
bool AddItem(Item item, List *plist);

/*操作：       把函数作用于链表中的每一项                                            */
/*			   plist指向一个初始化的链表                                             */
/*             pfun指向一个函数，该函数接受一个Item类型的参数，且无返回值			 */
/*后置条件：   pfun指向的函数作用于链表中的每一项一次                                */
void Traverse(const List *plist, void(*pfun)(Item item));

/*操作：       释放已分配的内存（如果有的话）                                        */
/*前提条件：   plist指向一个初始化的链表                                             */
/*后置条件：   释放为链表分配的所有内存，将链表设置为空                              */
void EmptyList(List *plist);









#endif