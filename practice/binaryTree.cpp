#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"
#include <string.h>

/*�ֲ���������*/
typedef struct pair{
	TreeNode * parent;
	TreeNode * child;
}Pair;

/*�ֲ�����ԭ��*/
//static Pair seekItem(const Item *item, TreeNode *root);            //������ͬ��
static Pair seekItem(const Item *item, const Tree *ptree);
static TreeNode *makeNode(const Item *pi);                            //�����½ڵ�
static void addNode(TreeNode *new_node, TreeNode *root);              //����½ڵ�
static bool toLeft(const Item *i1, const Item *i2);                   //ȷ���µ����Ƿ������������
static bool toRight(const Item *i1, const Item *i2);                  //ȷ���µ����Ƿ������������
static void deleteNode(TreeNode **ptr);                               //ɾ��һ���ڵ�
static void deleteAllNodes(TreeNode *root);
static void inOrder(const TreeNode *root, void (*pfun)(Item item));
static void preorder(const TreeNode *root, void (*pfun)(Item item));
static void PostOrder(const TreeNode *root, void (*pfun)(Item item));

void initializeTree(Tree *ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}

bool treeIsEmpty(const Tree *ptree)
{
	if(ptree->root == NULL)
		return true;
	else
		return false;
}

bool treeIsFull(const Tree *ptree)
{
	if(ptree->size == MAXITEMS)
		return true;
	else
		return false;
}

int treeItemCount(const Tree *ptree)
{
	return ptree->size;
}

bool AddItem(const Item *pi, Tree *ptree)
{
	TreeNode *newNode;
	if(treeIsFull(ptree))
	{
		fprintf(stderr, "Tree is full\n");
		return false;
	}
	if(seekItem(pi,ptree).child != NULL)
	{
		fprintf(stderr, "Attempted to add duplicate item.\n");
		return false;
	}
	newNode = makeNode(pi);
	if(newNode == NULL)
	{
		fprintf(stderr, "Couldn't create node\n");
		return false;
	}
	/*�ɹ�������һ���ڵ�*/
	ptree->size++;

	if(ptree->root == NULL)
		ptree->root = newNode;
	else
		addNode(newNode, ptree->root);

	return true;

}

bool InTree(const Item *pi, const Tree *ptree)
{
	return (seekItem(pi, ptree).child == NULL) ? false : true ;
}

bool DeleteItem(const Item *pi, Tree *ptree)
{
	Pair look;
	look = seekItem(pi,ptree);
	if (look.child == NULL)
		return false;
	if (look.parent == NULL)
		deleteNode(&ptree->root);
	else if (look.parent->left == look.child)
		deleteNode(&look.parent->left);
	else
		deleteNode(&look.parent->right);
	ptree->size--;

	return true;
}

void TraverseTree(const Tree *ptree, void (*pfun)(Item item))
{
	if (ptree != NULL)
	{
		//inOrder(ptree->root, pfun);
		//preorder(ptree->root, pfun);
		PostOrder(ptree->root, pfun);
	}
		
}

void DeleteAll(Tree *ptree)
{
	if (ptree != NULL)
		deleteAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}

/*�ֲ������ӿ�ʵ��*/

static TreeNode *makeNode(const Item *pi)
{
	TreeNode *newNode;
	newNode = (TreeNode *)malloc(sizeof(TreeNode));
	if(newNode !=NULL)
	{
		newNode->item = *pi;
		newNode->left = NULL;
		newNode->right = NULL;
	}

	return newNode;
}

static Pair seekItem(const Item *item, const Tree *ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;

	if (look.child == NULL)
		return look;
	while (look.child != NULL)
	{
		if (toLeft(item,&look.child->item))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if(toRight(item,&look.child->item))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else                //���ǰ������������ǣ���ض�����ȵ����
			break;          //look.child Ŀ����Ľڵ�
	}

	return look;   
}

//�ݹ�ʵ��seekItem
//static Pair seekItem(const Item *item, TreeNode *root)
//{
//	Pair look;
//	look.parent = NULL;
//	look.child = root;
//	
//	if(look.child == NULL)
//		return look;
//
//	if(toLeft(item,&look.child->item))
//	{
//		if(look.child->left != NULL)
//		{
//			TreeNode *tempParent;
//			tempParent = look.child;
//			look = seekItem(item, root->left);
//			if(look.child != NULL && look.parent  == NULL)
//				look.parent = tempParent;
//		}
//		else
//		{
//			look.child = NULL;
//		}
//	}
//	else if(toRight(item, &look.child->item))
//	{
//		if(look.child->right != NULL)
//		{
//		    TreeNode *tempParent;
//			tempParent = look.child;
//			look = seekItem(item, root->right);
//			if(look.child != NULL && look.parent  == NULL)
//				look.parent = tempParent;
//		}
//		else
//		{
//			look.child = NULL;
//		}
//	}
//	
//	return look;
//}

//ʵ�ִ��������seekItem()����
//static Pair seekItem(const Item *item,const Tree *ptree)
//{
//	Tree *temp;
//	Pair look;
//	look.parent = NULL;
//	look.child = ptree->root;
//	
//	if(look.child == NULL)
//		return look;
//
//	if(toLeft(item,&look.child->item))
//	{
//		
//		if(look.child->left != NULL)
//		{
//			TreeNode *tempParent;
//			tempParent = look.child;
//			temp->root = look.child->left;
//			look = seekItem(item, temp);
//			if(look.child != NULL && look.parent  == NULL)
//				look.parent = tempParent;
//		}
//		else
//		{
//			look.child = NULL;
//		}
//	}
//	else if(toRight(item, &look.child->item))
//	{
//		
//		if(look.child->right != NULL)
//		{
//		    TreeNode *tempParent;
//			tempParent = look.child;
//			temp->root = look.child->right;
//			look = seekItem(item, temp);
//			if(look.child != NULL && look.parent  == NULL)
//				look.parent = tempParent;
//		}
//		else
//		{
//			look.child = NULL;
//		}
//	}
//	
//	return look;
//}

static void addNode(TreeNode *new_node, TreeNode *root)
{
	if(toLeft(&new_node->item, &root->item))         
	{
		if(root->left == NULL)                    //������
			root->left = new_node;                //���½ڵ���ӵ��˴�
		else
			addNode(new_node,root->left);         //������Ϊ�գ���������
	}
	else if(toRight(&new_node->item, &root->item))
	{
		if(root->right == NULL)
			root->right = new_node;
		else
			addNode(new_node, root->right);
	}
	else
	{
		fprintf(stderr, "location error in addNode()\n");
		exit(1);
	}

}

static bool toLeft(const Item *i1, const Item *i2)
{
	int compare;

	if ((compare = strcmp(i1->petname, i2->petname)) < 0)
		return true;
	else if (compare == 0 && strcmp(i1->petkind, i2->petkind) < 0)
		return true;
	else
		return false;
}

static bool toRight(const Item *i1, const Item *i2)
{
	int compare;

	if ((compare = strcmp(i1->petname, i2->petname)) > 0)
		return true;
	else if (compare == 0 && strcmp(i1->petkind, i2->petkind) > 0)
		return true;
	else
		return false;
}

static void deleteNode(TreeNode **ptr)
{
	TreeNode *temp;
	if ((*ptr)->left ==NULL)  
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else if ((*ptr)->right == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
	else   //��ɾ���Ľڵ��������ӽڵ�
	{
		/*�ҵ������������ӽڵ��λ��*/
		for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
			continue;
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}

static void deleteAllNodes(TreeNode *root)
{
	TreeNode *pright;   //����һ���������������ڵ��ַ��ָ��

	if (root != NULL)
	{
		pright = root->right;
		deleteAllNodes(root->left);
		free(root);
		deleteAllNodes(pright); //��ǰ�ڵ�������ɾ���꣬����������
	}
}

//�������
static void inOrder(const TreeNode *root, void (*pfun)(Item item))
{
	if (root != NULL)
	{
		inOrder(root->left, pfun);
		(*pfun)(root->item);
		inOrder(root->right, pfun);
	}
}

//�������
static void preorder(const TreeNode *root, void (*pfun)(Item item))
{
	if (root != NULL)
	{
		(*pfun)(root->item);
		preorder(root->left,pfun);
		preorder(root->right,pfun);
	}
}

//�������
static void PostOrder(const TreeNode *root, void (*pfun)(Item item))
{
	if (root != NULL)
	{
		PostOrder(root->left,pfun);
		PostOrder(root->right,pfun);
		(*pfun)(root->item);
	}

}