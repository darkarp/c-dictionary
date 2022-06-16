#include "headers/node.h"
#include "headers/hash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Node new_node(const char* key, void* value) {
    uint64 size = strlen(key) + 1;
    Node node = malloc(sizeof(struct _Node));
    if (!node) return NULL;
    node->key = calloc(size, sizeof(char));
    if (!node->key) {
        free(node);
        return NULL;
    }
    node->next = NULL;
    node->element = value;
    memcpy(node->key, key, size);
    //? The commented out ones don't work with my GNU Clib
    // memccpy(node->key, key, 0, size);
    // memcpy_s(node->key, size, key, size);
    return node;
}

Node node_find(Node* nodes, const char* key, uint64 size) {
    uint64 index = index_from_hash(hashed(key), size);
    for (Node knode = nodes[index];knode;knode = knode->next)
        if (!memcmp(knode->key, key, strlen(key))) return knode;
    return NULL;
}

void node_del(Node node) {
    if (node) {
        node_del(node->next);
        free(node->key);
        free(node);
    }
    else return;
}

Node node_return_self(Node node) {
    return node;
}

char* node_return_key(Node node) {
    return node->key;
}

Element node_return_value(Node node) {
    return node->element;
}