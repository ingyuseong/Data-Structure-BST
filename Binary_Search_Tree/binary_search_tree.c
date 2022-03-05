/********************************************
 Class: Data Structure and Algorithms
 Project 2: Binary Search Tree

 BST.c

 Name: Sung In Gyu
 StudentID: 2017170992
 E-mail: dlssrb7777@korea.ac.kr

 **********************************************/
#include "student_BST.h"

treeNode createNode(char inputData)
{
	if (inputData < 97 || inputData > 122) {
		printf("Type of inputData is wrong\n");
		return NULL;
	}
	treeNode newNode;

	if ((newNode = (treeNode)malloc(sizeof(struct bstNode))) == NULL) {
		printf("Node creation is failed\n");
		return NULL;
	}
	newNode->data = inputData;
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;
	newNode->parentNode = NULL;

	return newNode;
}


int insertNode(char inputData) 
{
	if(isNodeExist(inputData) == 1) {					// no existing data.
		printf("Already existing data.\n");
		return 0;
	}

	treeNode newNode = createNode(inputData);
	treeNode cur = rootNode;

	if(newNode == NULL)							// failed to create new node.
		return 0;


	if ( rootNode == NULL) {			// rootNode don't have proper data. So, tree is empty.
		rootNode = newNode;
		printf("%c is inserted successfully.\n", inputData);
		return 1;
	} else {											// if there is a rootNode.

		treeNode parent = cur->parentNode;
		int left = 1;

		while(cur != NULL)
		{
			if(inputData < cur->data) {
				parent = cur;
				cur = cur->leftNode;
				left = 1;
			} else {
				parent = cur;
				cur = cur->rightNode;
				left = 0;
			}
		}

		newNode->parentNode = parent;
		if(left) {
			parent->leftNode = newNode;
		} else {
			parent->rightNode = newNode;
		}
		printf("%c is inserted successfully.\n", inputData);
		return 1;

	}

}

/* 
@Function name: int insertNode
@Parameters: char inputData
@Descriptions: This function insert the node in the BST. The node's data is input data. If insertion failed, return 0 or else return 1.
@Error cases: 
*/ 

int isNodeExist(char inputData)
{
	treeNode cur = rootNode;				// started from rootNode

	if ( rootNode == NULL) {			// rootNode don't have proper data. So, tree is empty.
		printf("Tree is empty.\n");
		return 0;
	}

	while(cur != NULL)						// search Node
	{
		if(cur->data == inputData) {
			return 1;
		} else if (inputData < cur->data) {
			cur = cur->leftNode;
		} else {
			cur = cur->rightNode;
		}
	}

	printf("%c is not in the Tree.\n",inputData);			// because function didn't finished until the end.
	return 0;
}

/* 
@Function name: int isNodeExist
@Parameters: char inputData
@Descriptions: This function print whether node that has inputdata is exist or not. If the node exists, return 1 or else return 0.
@Error cases: 
*/ 

treeNode findPosition(char inputData, treeNode node)
{
	if(inputData == node->data) {
		return node;
	} else if(inputData < node->data) {
		return (node->leftNode != NULL) ? findPosition(inputData, node->leftNode) : node;
	} else {
		return (node->rightNode != NULL) ? findPosition(inputData, node->rightNode) : node;
	}
}

/* 
@Function name: treeNode findPosition
@Parameters: char inputData, treeNode node
@Descriptions: This function compare input data and input node's data to find the node that has input data. If they find node, return that node. If not, they return the nearest node(parent node).
@Error cases: 
*/ 

int findDepth(char inputData)
{
	if(isNodeExist(inputData) == 0)
		return -1;

	treeNode cur = rootNode;
	int dep = 0;

	while(cur->data != inputData)
	{
		if(inputData < cur->data) {
			cur = cur->leftNode;
		} else {
			cur = cur->rightNode;
		}

		dep++;
	}

	return dep;
}

/* 
@Function name: int findDepth
@Parameters: char inputData
@Descriptions: This function find the node's depth whose data is same with input data. If node that has input data doesn't exists, return -1. If they find the node, return the depth of that node.
@Error cases: 
*/ 

treeNode findMin(treeNode node)
{
	treeNode cur = node;
	while(cur->leftNode != NULL)
		cur = cur->leftNode;
	
	printf("%c is minimum.\n",cur->data);
	return cur;
}

/* 
@Function name: treeNode findMin
@Parameters: treeNode node
@Descriptions: This fuction find the node that has minimum value in the tree whose root node is input node. If they find the node that has the smallest data, they return that node.
@Error cases: 
*/ 

int deleteNode(char inputData)
{
	if(!isNodeExist(inputData))
		return 0;

	treeNode cur = rootNode;
	treeNode parent = NULL;
	char modData;
	// int left = 1;

	while(cur->data != inputData)				// find node to delete
	{
		parent = cur;
		if(inputData < cur->data) {
			cur = cur->leftNode;
		} else {
			cur = cur->rightNode;
		}
	}

	if (cur->leftNode == NULL && cur->rightNode == NULL) {						// node to delete has no child

		if(parent != NULL) {
			if(parent->leftNode == cur) {
				parent->leftNode = NULL;
				free(cur);
			} else {
				parent->rightNode = NULL;
				free(cur);
			}
		} else {
			rootNode = NULL;
			free(cur);
		}
		

	} else if (cur->leftNode != NULL && cur->rightNode != NULL) {				// 2 children
		
		treeNode mod = cur->rightNode;
		while(mod->leftNode != NULL)
		{
			mod = mod->leftNode;
		}

		modData = mod->data;
		deleteNode(modData);

		cur->data = modData;

	} else {																	// 1 child
		if(parent != NULL) {
			if(cur->leftNode != NULL) {
				if(parent->leftNode == cur) {
					parent->leftNode = cur->leftNode;
					cur->leftNode->parentNode = parent;
					free(cur);
				} else {
					parent->rightNode = cur->leftNode;
					cur->leftNode->parentNode = parent;
					free(cur);
				}
			} else {
				if(parent->leftNode == cur) {
					parent->leftNode = cur->rightNode;
					cur->rightNode->parentNode = parent;
					free(cur);
				} else {
					parent->rightNode = cur->rightNode;
					cur->rightNode->parentNode = parent;
					free(cur);
				}
			}
		} else {
			if(cur->leftNode != NULL) {
				cur->leftNode->parentNode = parent;
				rootNode = cur->leftNode;
				free(cur);
			} else {
				cur->rightNode->parentNode = parent;
				rootNode = cur->rightNode;
				free(cur);
			}
		}
	}

	printf("%c is deleted successfully.\n", inputData);
	return 1;

}

/* 
@Function name: int deleteNode
@Parameters: char inputData
@Descriptions: This function delete the node that has same data with inputData. If deletion succeed, they return 1 with proper message. If not, they return 0 with error message.
@Error cases: 
*/ 

void destroyBST(void)
{
	char i;
	for (i='a'; i<='z'; i++)
		deleteNode(i);
	printf("Tree is destroyed.\n");

	return;
}

/* 
@Function name: void destroyBST 
@Parameters: void
@Descriptions: This function destory the whole BST. It means it delete every node in the tree and finally destroy tree. 
@Error cases: 
*/ 

int findNode(char inputData) 	// without using findPosition
{
	if(isNodeExist(inputData) == 0)
		return 0;
	
	treeNode cur = rootNode;

	while(cur != NULL)
	{
		if(cur->data == inputData)
			break;

		if(inputData < cur->data) {
			cur = cur->leftNode;
		} else {
			cur = cur->rightNode;
		}
	}

	printf("%c is in the Tree.\n", cur->data);
	(cur->parentNode != NULL) ? printf("Parent node is %c.\n", cur->parentNode->data) : printf("Parent node is NULL.\n");
	(cur->leftNode != NULL) ? printf("Left child node is %c.\n", cur->leftNode->data) : printf("Left child node is NULL.\n");
	(cur->rightNode != NULL) ? printf("Right child node is %c.\n", cur->rightNode->data) : printf("Right child node is NULL.\n");
	printf("Depth of %c is %d.\n", cur->data, findDepth(cur->data));
	return 1;
}

/* 
@Function name: int findNode
@Parameters: char inputData
@Descriptions: This function find node that has same data value with input data and print some information(whether it exists, parent, leftChild, rightChild, depth ) of that node.
@Error cases: 
*/ 

int treeTraversal(int type, char inputData)
{
	if(isNodeExist(inputData) == 0)
		return 0;

	treeNode cur = rootNode;

	while(cur != NULL)
	{
		if(cur->data == inputData)
			break;

		if(inputData < cur->data) {
			cur = cur->leftNode;
		} else {
			cur = cur->rightNode;
		}
	}

	if(type == 0) {
		printf("Pre-Order\n");
		preTraverse(cur->data);
		return 1;
	} else if (type == 1) {
		printf("In-Order\n");
		inTraverse(cur->data);
		return 1;
	} else if (type == 2) {
		printf("Post-Order\n");
		postTraverse(cur->data);
		return 1;
	} else {
		printf("Invaild Input.\n");
		return 0;
	}
}

/* 
@Function name: int treeTraversal
@Parameters: int traverseType, char inputData
@Descriptions: This function is for traverse the tree whose root node has same data with input data. There are 3 types of traverse and each function created recursively. While they traverse the tree they print out the data of node that they visiting. If traverse complete without any error, return 1 or else return 0. 
@Error cases: 
*/ 

int preTraverse(char inputData)
{
	if(inputData == 'A')
		return 0;

	treeNode cur = rootNode;

	while(cur != NULL)
	{
		if(cur->data == inputData)
			break;

		if(inputData < cur->data) {
			cur = cur->leftNode;
		} else {
			cur = cur->rightNode;
		}
	}

	printf("%c\n", cur->data);
	(cur->leftNode != NULL) ? preTraverse(cur->leftNode->data) : preTraverse('A');
	(cur->rightNode != NULL) ? preTraverse(cur->rightNode->data) : preTraverse('A');

	return 1;
}

int inTraverse(char inputData) 
{
	if(inputData == 'A')
		return 0;

	treeNode cur = rootNode;

	while(cur != NULL)
	{
		if(cur->data == inputData)
			break;

		if(inputData < cur->data) {
			cur = cur->leftNode;
		} else {
			cur = cur->rightNode;
		}
	}

	(cur->leftNode != NULL) ? inTraverse(cur->leftNode->data) : inTraverse('A');
	printf("%c\n", cur->data);
	(cur->rightNode != NULL) ? inTraverse(cur->rightNode->data) : inTraverse('A');

	return 1;
}

int postTraverse(char inputData) 
{
	if(inputData == 'A')
		return 0;

	treeNode cur = rootNode;

	while(cur != NULL)
	{
		if(cur->data == inputData)
			break;

		if(inputData < cur->data) {
			cur = cur->leftNode;
		} else {
			cur = cur->rightNode;
		}
	}

	(cur->leftNode != NULL) ? postTraverse(cur->leftNode->data) : postTraverse('A');
	(cur->rightNode != NULL) ? postTraverse(cur->rightNode->data) : postTraverse('A');
	printf("%c\n", cur->data);

	return 1;
}



int findHeight(void) 
{

	if ( rootNode == NULL) {			// rootNode don't have proper data. So, tree is empty.
		printf("Tree is empty.\n");
		return -1;
	} else {

		treeNode a[100];			// data -> [a,z]. Therefore, maxsize 100 is safe.
		int bi = 0, i = 0, height = -1;
		int first = 1;
		a[i++] = rootNode;

		while(i<100)
		{
			int count = i - bi;

			if(count == 0)
			{
				printf("The height of tree is %d.\n", height);
				return height;
			}

			// bi = i-count; // meaingless..?
			height++;

			while(count > 0)
			{
				if(a[bi]->leftNode != NULL) {
					a[i++] = a[bi]->leftNode;
				}

				if(a[bi]->rightNode != NULL) {
					a[i++] = a[bi]->rightNode;
				}

				bi++;
				count--;
			}

		}

		
	}

}

/* 
@Function name: int findHeight
@Parameters: void
@Descriptions: This function print out and return the whole height of the BST. If tree is empty, it return -1.
@Error cases: 
*/

int NodeBinaryPosition(char inputData)
{
	if(isNodeExist(inputData) == 0)
		return 0;
	
	treeNode cur = rootNode;
	int i = 1;
	int h = findHeight();
	char bp[100];
	bp[0] = '1';

	while(cur != NULL)
	{
		if(cur->data == inputData)
			break;

		if(inputData < cur->data) {
			cur = cur->leftNode;
			bp[i++] = '0';
		} else {
			cur = cur->rightNode;
			bp[i++] = '1';
		}
	}

	bp[i++] = '\0';

	printf("\'%c\'s position binary value = %s", cur->data, bp);

	return 1;
}

/* 
@Function name: int NodeBinaryPosition
@Parameters: char inputData
@Descriptions: This function print out the node's(whose data is same with input data) position binary value. If node doesn't exists, return 0 or else return 1.
binary value 
@Error cases: 
*/

int showLeaves(void)
{

	if ( rootNode == NULL) {			// rootNode don't have proper data. So, tree is empty.
		printf("Tree is empty.\n");
		return 0;
	}


	treeNode cur = rootNode;
	treeNode s[100];
	int top = 0;
	int i = 0;

	while(top < 100)			//initialize
	{
		s[top++] = NULL;
	}
	top = 0;

	s[i++] = cur;

	while(s[top] != NULL)
	{
		treeNode leafornot = s[top++];

		if(leafornot->leftNode == NULL && leafornot->rightNode == NULL)
		{
			printf("%c is a leaf.\n", leafornot->data);
			continue;
		}

		if(leafornot->leftNode != NULL)
		{
			s[i++] = leafornot->leftNode;
		}

		if(leafornot->rightNode != NULL)
		{
			s[i++] = leafornot->rightNode;
		}
	}

	return 1;
}

/* 
@Function name: int showLeaves
@Parameters: void
@Descriptions: This function show all leaf node of the BST. If tree is empty, return 0 or else return 1.
@Error cases: 
*/

int makeCompleteBST(void) 
{
	if(rootNode == NULL)
	{
		printf("Tree is empty.\n");
		return 0;
	}

	char a[100];
	char b[100];
	char c[100];
	char i;
	int n=0,j=1,k,h=0,leaf, leaf_i, full, full_i, sq, repeat=1;
	for (i='a'; i<='z'; i++)
	{
		if(deleteNode(i) == 1) 
		{
			a[j++] = i;
			n++;
		}
	}

	j=1; 			// init index

	sq=1;

	while(1)
	{
		sq*=2;
		k=sq-1;
		if(n<k)				// same height
			break;

		h++;
	}

	k-=(sq/2);
	leaf = n - k;
	full = n - leaf;
	leaf_i = 1;
	full_i = 1;

	while(1)
	{
		if(leaf == 0)
			break;
		b[leaf_i++] = a[j];
		a[j] = '*';
		j+=2;
		leaf--;
	}

	leaf_i = 1;
	leaf = n - full;

	for(j = 1; j < n+1; j++)
	{
		if(a[j]!='*')
			c[full_i++] = a[j];
	}

	full_i = 1;

	for(j=0; j<h; j++)
	{
		int m = (full+1) / 2;
		sq/=2;
		full-=m;
		for(k=0; k < repeat; k++)
		{
			insertNode(c[m]);
			m+=sq;
		}
		repeat*=2;
	}

	for(j=1; j < leaf+1; j++)
		insertNode(b[j]);
	
	return 1;
}


/* 
@Function name: int makeCompleteBST
@Parameters: void
@Descriptions: This function change the structure of BST to Complete binary tree. If tree is empty, return 0 or else return 1.
@Error cases: 
*/


int showTree(void)
{
	if(rootNode == NULL)
	{
		printf("Tree is empty.\n");
		return 0;
	}

	int h = findHeight();
	int i,d,n=1, top=1;

	for(i=0; i < h+1; i++)	//total node to print
		n*=2;


	char s[n];

	for(i=0; i < n; i++)
		s[i] = '*';


	s[top] = rootNode->data;

	i = 2;
	
	while(i<=n)
	{
		while(s[top] == '*')
		{
			i+=2;
			top++;
		}

		treeNode p = findPosition(s[top++], rootNode);	//pop

		if(p->leftNode != NULL) {
			s[i++] = p->leftNode->data;
		} else {
			i++;
		}

		if(p->rightNode != NULL) {
			s[i++] = p->rightNode->data;
		} else {
			i++;
		}
	}

	// printf(d=0; d<100; d++)
	// 	printf("%c::\n", s[d]);

	for(d=0; d<=h; d++)
	{
		int start = 1, end = 1, z;
		for(z=0; z<d; z++)
			start*=2;
		
		end = start*2 - 1;
		
		printf("Depth: %d ", d, start, end);
		for(i=start; i<=end; i++)
			printf("%c ", s[i]);
		printf("\n");
	}
	
}

/* 
@Function name: int showLeaves
@Parameters: void
@Descriptions: This function show whole structure of the BST. It print all node (include empty node [*]) by each depth.
@Error cases: 
*/