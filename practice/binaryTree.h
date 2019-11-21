#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

/*�ɸ��ݾ���������¶���Item*/
#define SLEN 20
typedef struct itme
{
	char petname[SLEN];
	char petkind[SLEN];
}Item;

#define MAXITEMS 30

typedef struct treeNode
{
	Item item;
	struct treeNode *left;  //ָ�����֧��ָ��
	struct treeNode *right; //ָ���ҷ�֧��ָ��
}TreeNode;

typedef struct tree
{
	TreeNode *root;//ָ����ڵ��ָ��
	int size;      //��������
}Tree;


/*����ԭ��*/

void initializeTree(Tree *ptree);

bool treeIsEmpty(const Tree *ptree);

bool treeIsFull(const Tree *ptree);

int treeItemCount(const Tree *ptree);

bool AddItem(const Item *pi, Tree *ptree);

bool InTree(const Item *pi, const Tree *ptree);

bool DeleteItem(const Item *pi, Tree *ptree);

void TraverseTree(const Tree *ptree, void (*pfun)(Item item));

void DeleteAll(Tree *ptree);




#endif // !_BINARYTREE_H_
