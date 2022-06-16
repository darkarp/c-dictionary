#include "headers/hash.h"
#include <string.h>

uint64 index_from_hash(const uint64 hash, const uint64 size)
{
    return hash & (size - 1);
}

uint64 hashed(const char* key)
{
    uint64 hash = 0;
    for (int i = 0; i < (int)strlen(key); i++) {
        hash *= 72;
        hash += (uint64)key[i];
    }
    return hash;
}