#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree3.h"
#include "BinarySearchTree.h"

int main(void)
{
	BTreeNode * avlRoot;
	BTreeNode * clNode;		// current left node
	BTreeNode * crNode;		// current right node
	BSTMakeAndInit(&avlRoot);

	BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 4);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 6);
	printf("루트 노드: %d \n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("왼쪽1: %d, 오른쪽1: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("왼쪽2: %d, 오른쪽2: %d \n", GetData(clNode), GetData(crNode));

	crNode = GetRightSubTree(crNode);
	printf("오른쪽3: %d \n",GetData(crNode));
	return 0;
}