#ifndef DICT_H
#define DICT_H
#define DEFAULT_SIZE 23
#include <stdint.h>
// #include <stdlib.h>
#include "types.h"
#include "errors.h"
#include "node.h"
#define ER char*(*)(void*)
typedef struct _Dict {
    Node* hashmap;
    uint64 size, count;
} *Dict;

//? Dict functions
Dict new_dict(uint64 size);
ERROR_CODE dict_add(Dict dict, const char* key, void* value);
ERROR_CODE dict_rem(Dict dict, const char* key);
Element dict_find(Dict dict, const char* key);
void** dict_to_array(Dict dict, ER);
char** dict_keys(Dict dict);
void free_dict(Dict dict);
void print_dict(Dict dict, ER);
void resize_dict(Dict dict, const uint64 new_size);
#endif