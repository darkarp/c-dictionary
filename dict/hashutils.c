#include "headers/hash.h"
#include <string.h>

uint64_t index_from_hash(const int hash, const int size)
{
    return hash & (size - 1);
}

uint64_t hashed(const char* key)
{
    uint64_t hash = 0;
    for (int i = 0; i < (int)strlen(key); i++) {
        hash *= 72;
        hash += (uint64_t)key[i];
    }
    return hash;
}