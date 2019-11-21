/*Link_List.h--���������͵�ͷ�ļ�*/
#ifndef LINK_LIST_H_
#define LINK_LIST_H_

/*�ض����������*/

#define TSIZE        40   /*�����Ӱ���������С*/
struct film 
{
	char title[TSIZE];
	int rating;
};

/*һ�����Ͷ���*/

typedef struct film Item;

typedef struct node
{
	Item item;
	struct node *next;
}Node, *List;

/*����ԭ��*/

/*������       ��ʼ��һ������                                                       */
/*ǰ��������   plistָ��һ������                                                    */
/*����������   ��ʼ������Ϊ��                                                       */
void InitializeList(List *plist);

/*������       ȷ�������Ƿ�Ϊ�գ�plistָ��һ���Ѿ���ʼ��������						*/
/*����������   �������Ϊ�գ�����true�����򷵻�false								*/
bool ListIsEmpty(const List *plist);

/*������       ȷ�������Ƿ�������plistָ��һ���Ѿ���ʼ��������						*/
/*����������   �����������������true�����򷵻�false								*/
bool ListIsFull(const List *plist);

/*������       ȷ�������е�������plistָ��һ���Ѿ���ʼ��������						*/
/*����������   �ú������������е�����												*/
unsigned int ListItemCount(const List *plist);

/*������       �������ĩβ���һ����                                                */
/*ǰ��������   item��һ���������������plistָ��һ����ʼ��������                 */
/*����������   ��ӳɹ�����true��ʧ���򷵻�false                                     */
bool AddItem(Item item, List *plist);

/*������       �Ѻ��������������е�ÿһ��                                            */
/*			   plistָ��һ����ʼ��������                                             */
/*             pfunָ��һ���������ú�������һ��Item���͵Ĳ��������޷���ֵ			 */
/*����������   pfunָ��ĺ��������������е�ÿһ��һ��                                */
void Traverse(const List *plist, void(*pfun)(Item item));

/*������       �ͷ��ѷ�����ڴ棨����еĻ���                                        */
/*ǰ��������   plistָ��һ����ʼ��������                                             */
/*����������   �ͷ�Ϊ�������������ڴ棬����������Ϊ��                              */
void EmptyList(List *plist);









#endif