#ifndef STACK_H
#define STACK_H

typedef struct Node Node;
typedef struct StackNode StackNode;

void stacknode_destroy(StackNode *stacknode);
void (*stacknode_push)(StackNode *stacknode, const void *value, const int type); // 0 = INT, 1 = CHAR
void *(*stacknode_pop)(StackNode *stacknode);

#endif