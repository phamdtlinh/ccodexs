#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode TreeNode;

struct TreeNode {
	int data;
	TreeNode *left;
	TreeNode *right;
};
// BTS Tree Invariants applied:
// Add + Traversal In-order (left < root < right)
// Free Post Order (left > right > root)
TreeNode *tree_node_insert(TreeNode *treenode, int value);
TreeNode *tree_node_search(TreeNode *treenode, int value);
TreeNode *tree_node_delete(TreeNode *treenode, int value);
void tree_print_nodes(TreeNode *treenode);

int main(int argc, char **argv) {
	TreeNode *root = NULL;
	root = tree_node_insert(root, 50);
	root = tree_node_insert(root, 25);
	root = tree_node_insert(root, 75);
	root = tree_node_insert(root, 12);
	root = tree_node_insert(root, 37);
	root = tree_node_insert(root, 62);
	root = tree_node_insert(root, 87);
	root = tree_node_insert(root, 6);
	root = tree_node_insert(root, 18);
	root = tree_node_insert(root, 31);
	root = tree_node_insert(root, 43);
	root = tree_node_insert(root, 56);
	root = tree_node_insert(root, 68);
	root = tree_node_insert(root, 81);
	root = tree_node_insert(root, 93);
	root = tree_node_insert(root, 3);
	root = tree_node_insert(root, 9);
	root = tree_node_insert(root, 21);
	root = tree_node_insert(root, 34);
	root = tree_node_insert(root, 40);
	TreeNode *deletedParent = tree_node_delete(root, 0);
	if (deletedParent) {
		printf("Deleted value: %d\n", deletedParent->data);
	} else {
		printf("Not found to delete\n");
	}
	tree_print_nodes(root);
	
}

TreeNode *tree_node_insert(TreeNode *treenode, int value) {
	if (!treenode) {
		TreeNode *tn = malloc(sizeof(*tn));
		if (!tn) {
			fprintf(stdout, "tree_node_insert malloc failed!\n");
			return NULL;
		}
		tn->data = value;
		tn->left = NULL;
		tn->right = NULL;
		return tn;
	}
	if (value<treenode->data) {
		treenode->left = tree_node_insert(treenode->left, value);
	} else {
		treenode->right = tree_node_insert(treenode->right, value);
	}
	return treenode;
}

TreeNode *tree_node_search(TreeNode *treenode, int value) {
	if (!treenode) {
		return NULL;
	}
	if (treenode->data > value) {
		return tree_node_search(treenode->left, value);
	} else if (treenode->data < value) {
		return tree_node_search(treenode->right, value);
	} else {
		return treenode;
	}
	return NULL;
}
TreeNode *tree_node_delete(TreeNode *treenode, int value) {
	if (!treenode) {
		return NULL;
	}
	if (treenode->data > value) {
		treenode->left = tree_node_delete(treenode->left, value);
	} else if (treenode->data < value) {
		treenode->right = tree_node_delete(treenode->right, value);
	} else {
		// DO SOMETHING HERE
	}
	return treenode;
}

void tree_print_nodes(TreeNode *treenode) {
	if (!treenode) {
		fprintf(stdout, "tree_print_nodes treenode nulled!\n");
		return;
	}
	if (treenode->left) {
		tree_print_nodes(treenode->left);
	}
	printf("value: %d\n", treenode->data);
	if (treenode->right) {
		tree_print_nodes(treenode->right);
	}
}
