#ifndef DICT_NODE_H
#define DICT_NODE_H
#include "errors.h"
#include "types.h"

typedef void* Element;

typedef struct _Node {
    struct _Node* next;
    char* key;
    Element element;
} *Node;

Node new_node(const char* key, void* value);
Node node_find(Node* nodes, const char* key, uint64 size);

Node node_return_self(Node node);
char* node_return_key(Node node);
Element node_return_value(Node node);

void node_del(Node node, void free_element(Element));
#endif
