#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot) {
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst) {
	return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data) {
	BTreeNode * newNode = MakeBTreeNode();
	SetData(newNode, data);
	BTreeNode * savePos = *pRoot;


	if (*pRoot == NULL) {
		*pRoot = newNode;
		return;
	}

	while (TRUE) {
		if (GetData(savePos) < data) {
			if (GetRightSubTree(savePos) != NULL)
				savePos = GetRightSubTree(savePos);

			else {
				MakeRightSubTree(savePos, newNode);
				break;
			}
		}

		else if (GetData(savePos) > data) {
			if (GetLeftSubTree(savePos) != NULL)
				savePos = GetLeftSubTree(savePos);
			else {
				MakeLeftSubTree(savePos, newNode);
				break;
			}
		}

		else
			break;
	}

	return;
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target) {
	while (bst != NULL) {
		if (GetData(bst) < target)
			bst = GetRightSubTree(bst);

		else if (GetData(bst) > target)
			bst = GetLeftSubTree(bst);

		else
			return bst;
	}

	return NULL;
}

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target) {
	BTreeNode * pVRoot = MakeBTreeNode();
	BTreeNode * pNode = pVRoot;
	BTreeNode * cNode = *pRoot;
	BTreeNode * dNode;

	ChangeRightSubTree(pVRoot, *pRoot);

	while (cNode != NULL && GetData(cNode) != target) {
		pNode = cNode;
		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL)
		return NULL;

	dNode = cNode;

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

		if (GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	else {
		BTreeNode * mNode = GetRightSubTree(dNode);
		BTreeNode * mpNode = dNode;
		int delData;

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
	return dNode;
}

void ShowIntData(int data) {
	printf("%d ", data);
}

void BSTShowAll(BTreeNode * bst) {
	InorderTraverse(bst, ShowIntData);
}