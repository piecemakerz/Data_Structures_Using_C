#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree3.h"
#include "BinarySearchTree.h"
#include "AVLRebalance.h"

void ShowIntData(int data){
	printf("%d ", data);
}

void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	if (*pRoot == NULL) {
		*pRoot = MakeBTreeNode();
		SetData(*pRoot, data);
	}
	
	else if (data < GetData(*pRoot)) {
		BSTInsert(&((*pRoot)->left), data);
		*pRoot = Rebalance(pRoot);
	}

	else if (data > GetData(*pRoot)) {
		BSTInsert(&((*pRoot)->right), data);
		*pRoot = Rebalance(pRoot);
	}
	else {
		return NULL;
	}
	return *pRoot;
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
	BTreeNode * cNode = bst;    // current node
	BSTData cd;    // current data

	while (cNode != NULL)
	{
		cd = GetData(cNode);

		if (target == cd)
			return cNode;
		else if (target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	return NULL;
}

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target) {
	BTreeNode * pVRoot = MakeBTreeNode();
	BTreeNode * pNode = pVRoot;
	BTreeNode * dNode = *pRoot;

	ChangeRightSubTree(pVRoot, *pRoot);

	while (dNode != NULL)
	{
		if (target == GetData(dNode))
			break;

		pNode = dNode;

		if (target < GetData(dNode))
			dNode = GetLeftSubTree(dNode);
		else
			dNode = GetRightSubTree(dNode);
	}

	if (dNode == NULL)
		return NULL;

	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) {
		BTreeNode * dcNode;

		if (GetLeftSubTree(dNode) != NULL) 
			dcNode = GetLeftSubTree(dNode);
		else 
			dcNode = GetRightSubTree(dNode);
		
		if(GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	else {
		BTreeNode * mNode = GetRightSubTree(dNode);
		BTreeNode * mpNode = dNode;
		BSTData delData;

		while (GetLeftSubTree(mNode) != NULL) {
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));

		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData);
	}

	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);

	free(pVRoot);
	*pRoot = Rebalance(pRoot);
	return dNode;
}

void BSTShowAll(BTreeNode * bst) {
	InorderTraverse(bst, ShowIntData);
}