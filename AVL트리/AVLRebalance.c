#include <stdio.h>
#include <math.h>
#include "BinaryTree3.h"

BTreeNode * RotateLL(BTreeNode * bst) {
	BTreeNode * pnode = bst;
	BTreeNode * cnode = GetLeftSubTree(pnode);

	ChangeLeftSubTree(pnode, GetRightSubTree(cnode));
	ChangeRightSubTree(cnode, pnode);

	return cnode;
}

BTreeNode * RotateRR(BTreeNode * bst) {
	BTreeNode * pnode = bst;
	BTreeNode * cnode = GetRightSubTree(pnode);

	ChangeRightSubTree(pnode, GetLeftSubTree(cnode));
	ChangeLeftSubTree(cnode, pnode);

	return cnode;
}

BTreeNode * RotateRL(BTreeNode * bst) {
	BTreeNode * pnode;
	BTreeNode * cnode;

	pnode = bst;
	cnode = GetRightSubTree(pnode);

	ChangeRightSubTree(pnode, RotateLL(cnode));
	return RotateRR(pnode);

}

BTreeNode * RotateLR(BTreeNode * bst) {
	BTreeNode * pnode;
	BTreeNode * cnode;

	pnode = bst;
	cnode = GetLeftSubTree(pnode);

	ChangeLeftSubTree(pnode, RotateRR(cnode));
	return RotateLL(pnode);
}

int GetHeight(BTreeNode * bst) {
	int leftH;
	int rightH;

	if (bst == NULL)
		return 0;

	leftH = GetHeight(GetLeftSubTree(bst));
	rightH = GetHeight(GetRightSubTree(bst));

	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

int GetHeightDiff(BTreeNode * bst) {
	if (bst == NULL)
		return 0;

	return GetHeight(GetLeftSubTree(bst)) - GetHeight(GetRightSubTree(bst));
}

BTreeNode * Rebalance(BTreeNode ** pRoot) {
	int hDiff = GetHeightDiff(*pRoot);

	if (hDiff > 1) {
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0) {
			*pRoot = RotateLL(*pRoot);
		}
		else {
			*pRoot = RotateLR(*pRoot);
		}
	}

	else if (hDiff < -1) {
		if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0) {
			*pRoot = RotateRR(*pRoot);
		}
		else {
			*pRoot = RotateRL(*pRoot);
		}
	}

	return *pRoot;
}