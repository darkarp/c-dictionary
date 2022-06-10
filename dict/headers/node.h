#ifndef DICT_NODE_H
#define DICT_NODE_H
#include "errors.h"

typedef void* Element;

typedef struct _Node {
    struct _Node* next;
    char* key;
    Element element;
} *Node;

Node new_node(const char* key, void* value);
Node node_find(Node* nodes, const char* key, int size);

Node node_return_self(Node node);
char* node_return_key(Node node);
Element node_return_value(Node node);

void node_del(Node node);
void print_keys_in_node(Node* nodes, const int size);
#endif