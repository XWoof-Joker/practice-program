#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

/*可根据具体情况重新定义Item*/
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
	struct treeNode *left;  //指向左分支的指针
	struct treeNode *right; //指向右分支的指针
}TreeNode;

typedef struct tree
{
	TreeNode *root;//指向根节点的指针
	int size;      //树的项数
}Tree;


/*函数原型*/

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
