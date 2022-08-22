#include "headers/dict.h"
#include "headers/errors.h"
#include "headers/hash.h"
#include "headers/node.h"
#include "headers/prime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Dict new_dict(uint64 size) {
    if (!size)
        size = DEFAULT_SIZE;
    Dict dict = malloc(sizeof(struct _Dict));
    dict->size = size;
    dict->count = 0;
    dict->hashmap = calloc(size, sizeof(Node));
    return dict;
}

ERROR_CODE dict_add(Dict dict, const char* key, void* value) {
    uint64 dict_sz = dict->size;
    if (node_find(dict->hashmap, key, dict_sz))
        return ERR_ADD_ALREADY_EXISTS;
    Node node_new = new_node(key, value);
    if (!node_new)
        return 1;
    uint64 index = index_from_hash(hashed(key), dict_sz);
    dict->count++;
    if (!dict->hashmap[index]) {
        dict->hashmap[index] = node_new;
        if (dict->count >= dict->size - 1) {
            uint64 new_sz = next_prime(dict_sz * 2);
            resize_dict(dict, new_sz);
        }
    }
    else {
        node_new->next = dict->hashmap[index];
        dict->hashmap[index] = node_new;
    }
    return EXIT_SUCCESS;
}

ERROR_CODE dict_rem(Dict dict, const char* key, void free_element(Element)) {
    uint64 index = index_from_hash(hashed(key), dict->size);
    Node target = node_find(dict->hashmap, key, dict->size);
    if (target)
        node_del(target, free_element);
    else
        return ERR_REMOVE_NONEXISTENT;
    dict->hashmap[index] = NULL;
    dict->count--;
    return EXIT_SUCCESS;
}

Element dict_get(Dict dict, const char* key) {
    Node node = node_find(dict->hashmap, key, dict->size);
    if (node)
        return node->element;
    else
        return NULL;
}

ERROR_CODE free_dict(Dict dict, void free_element(Element)) {
    for (int i = 0; i < (int)dict->size; i++)
        if (dict->hashmap[i])
            node_del(dict->hashmap[i], free_element);
    free(dict->hashmap);
    dict->hashmap = 0;
    free(dict);
    return EXIT_SUCCESS;
}

ERROR_CODE reinsert_dict(Dict dict, Node keynode) {
    uint64 index = index_from_hash(hashed(keynode->key), dict->size);
    if (dict->hashmap[index])
        keynode->next = dict->hashmap[index];
    dict->hashmap[index] = keynode;
    return EXIT_SUCCESS;
}

void** dict_to_array(Dict dict, char* (*element_return)(void*)) {
    void** listed_dict = calloc(sizeof(void*), dict->count);
    Node* nodes = dict->hashmap;
    int placed = 0;
    for (int i = 0; i < (int)dict->size; i++) {
        Node keynode = nodes[i];
        do {
            if (keynode) {
                listed_dict[placed++] = element_return(keynode);
                keynode = keynode->next;
            }
            else
                break;
        } while (keynode);
    }
    return listed_dict;
}

char** dict_keys(Dict dict) {
    char** listed_keys = (char**)dict_to_array(dict, (ER)node_return_key);
    return listed_keys;
}

void* dict_values(Dict dict) {
    void* listed_values = dict_to_array(dict, (ER)node_return_value);
    return listed_values;
}

char* basic_element_return(Element element) {
    char* element_return = malloc(sizeof(char) * 100);
    snprintf(element_return, 100, "<Object: address %p>", element);
    return element_return;
}

void print_dict(Dict dict, char* (*element_return)(void*), uint64 spacing) {
    char* spaces = malloc(spacing + 1);
    char** keys = dict_keys(dict);
    if (!keys) {
        free(spaces);
        return;
    }
    uint64 i = 0;
    if (spacing)
        for (; i < spacing;i++)
            spaces[i] = ' ';
    spaces[i] = '\0';
    if (!element_return) element_return = basic_element_return;

    for (int i = 0; i < (int)dict->count; i++) {
        Node node = node_find(dict->hashmap, keys[i], dict->size);
        if (!node) {
            printf("%sNo node with this key: %s\n", spaces, keys[i]);
            break;
        }
        char* value = element_return(node->element);
        printf("%s%s: %s\n", spaces, keys[i], value);
        if (element_return == basic_element_return)
            free(value);
    }
    free(keys);
    free(spaces);
}

ERROR_CODE resize_dict(Dict dict, const uint64 new_size) {
    Node* old_dict = dict->hashmap;
    dict->hashmap = calloc(new_size, sizeof(Node));
    uint64 old_size = dict->size;
    dict->size = new_size;
    for (int i = 0; i < (int)old_size; i++) {
        for (Node keynode = old_dict[i]; keynode;) {
            Node next = keynode->next;
            keynode->next = NULL;
            reinsert_dict(dict, keynode);
            keynode = next;
        }
    }
    free(old_dict);
    return EXIT_SUCCESS;
}
