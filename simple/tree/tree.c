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
	root = tree_node_insert(root, 5);
	root = tree_node_insert(root, 10);
	root = tree_node_insert(root, 15);
	root = tree_node_insert(root, 5);
	root = tree_node_insert(root, 57);
	root = tree_node_insert(root, 21);
	root = tree_node_insert(root, 81);
	root = tree_node_insert(root, 57);
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
