#include "stack.h"
#include <stdlib.h>

struct Node {
    Node *node;
};

struct StackNode {
    unsigned int type : 1;
    void *data;
    Node *next;
};


void stacknode_destroy(StackNode *stacknode);
void stacknode_push_int(StackNode *stacknode, const void *value, const int type);
void stacknode_push_char(StackNode *stacknode, const void *value, const int type);
StackNode *stacknode_init(int type);

int stacknode_pop_int(StackNode *stacknode);
StackNode *stacknode_pop_char(StackNode *stacknode);

Node *node_init();
void *node_destroy(Node *node);


Node *node_init() {
    Node *node = malloc(sizeof(*node));
    if (!node) return NULL;
    node->node = NULL;
    return node;
}
void *node_destroy(Node *node) {
    if (!node) return NULL;
    free(node);
}
StackNode *stacknode_init(int type) {
    StackNode *stacknode = malloc(sizeof(*stacknode));
    if (!stacknode) {
        return NULL;
    }
    Node *node = node_init();
    if (!node) {
        stacknode_destroy(stacknode);
        return NULL;
    }
    size_t data_size = 0;
    if (type==0) data_size = sizeof(int);
    else data_size = sizeof(char);
    int *data = malloc(data_size);
    if (!data) {
        node_destroy(node);
        stacknode_destroy(stacknode);
        return NULL;
    }
    stacknode->type = type;
    stacknode->next = node;
    return stacknode;
}
void stacknode_push_int(StackNode *stacknode, const void *value, const int type) {

}
void stacknode_init_char(StackNode *stacknode, const void *value, const int type) {
    
}
StackNode 
