#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

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
void tree_destroy(TreeNode *treenode);
int tree_find_max(TreeNode *treenode, int *max);
int tree_find_min(TreeNode *treenode, int *min);
void tree_print_nodes(TreeNode *treenode);
void tree_print_nodes_visualize(TreeNode* root, int space);

// call seeding() before use rig011 and rig012
void timespec_seeding();
int rig011(int min, int max);
int rig012(int min, int max);

int main(void) {
	timespec_seeding();
	TreeNode *root = NULL;
	int max_capacity = 50;
	root = tree_node_insert(root, max_capacity);
	if (root) {
		for (int i=1; i <= max_capacity; i++) {
			int value = rig011(0,max_capacity * 2);
			if (tree_node_search(root, value)) continue;
			printf("%d", value);
			if (i<max_capacity) printf(", ");
			root = tree_node_insert(root, value);
		}
		printf("\n");
		tree_print_nodes(root);
		int min = 0,max = 0;
		tree_find_min(root, &min);
		tree_find_max(root, &max);
		printf("Min: %d\n", min);
		printf("Max: %d\n", max);
		int deleted_value = rig011(25,75);
		printf("Start delete %d\n", deleted_value);
		root = tree_node_delete(root, deleted_value);
		printf("Root value: %d\n", root->data);
		tree_print_nodes(root);
		tree_print_nodes_visualize(root, 1);
		tree_destroy(root);
	}
	
}

TreeNode *tree_node_insert(TreeNode *treenode, int value) {
	if (tree_node_search(treenode, value)) return treenode;
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
		if (!treenode->left) { 
			TreeNode* temp = treenode->right;
			free(treenode);
			return temp; 
		}
		if (!treenode->right) { 
			TreeNode* temp = treenode->left;
			free(treenode);
			return temp; 
		}
		int rep_side = rig011(0,1) % 2; // 1 = max of left, 0 = min of right
		if (rep_side) {
			int max = 0;
			tree_find_max(treenode->left, &max);
			treenode->data = max;
    		treenode->left = tree_node_delete(treenode->left, treenode->data);
		} else {
			int min = 0;
			tree_find_min(treenode->right, &min);
			treenode->data = min;
    		treenode->right = tree_node_delete(treenode->right, treenode->data);
		}
		printf("Deleted %d\n", value);
	}
	
	return treenode;
}
void tree_destroy(TreeNode *treenode) {
	if (!treenode) {
		fprintf(stderr, "tree_destroy treenode nulled!\n");
		return;
	}
	if (treenode->right) {
		tree_destroy(treenode->right);
	}
	if (treenode->left) {
		tree_destroy(treenode->left);
	}
	free(treenode);
	return;
}
int tree_find_max(TreeNode *treenode, int *max) {
	if (!treenode) {
		return 0;
	}
	while(treenode->right) treenode = treenode->right;
	*max = treenode->data;
	return 1;
}
int tree_find_min(TreeNode *treenode, int *min) {
	if (!treenode) {
		return 0;
	}
	while(treenode->left) treenode = treenode->left;
	*min = treenode->data;
	return 1;
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
void tree_print_nodes_visualize(TreeNode* root, int space) {
    if (root == NULL) return;
    space += 5;
    tree_print_nodes_visualize(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) printf(" ");
    printf("%d\n", root->data);
    tree_print_nodes_visualize(root->left, space);
}

void timespec_seeding() {
	struct timespec ts;
	timespec_get(&ts, TIME_UTC);
	srand((unsigned int)(ts.tv_nsec ^ ts.tv_sec)); 
}
int rig011(int min, int max) {
	if (min>max) return 0;
	long long check_point_count = (long long)max - (long long)min + 1;
	long long b1 = (long long)rand();
	long long b2 = (long long)rand();
	return 	(int)((unsigned long long)((b1 << 16) ^ b2) % check_point_count + min);
}
int rig012(int min, int max) {
	if (min>max) return 0;
	long long check_point_count = (long long)max - (long long)min + 1;
	long long x1 = (long long)rand();
	long long x2 = (long long)rand();
	long long x3 = (long long)rand();
	x1 ^= x2 << 13;
	x2 ^= x3 >> 17;
	x3 ^= x1 << 5;
	return (int)((unsigned long long)((x1 << 16) ^ (x2 << 8) ^ x3) % check_point_count + min);
}