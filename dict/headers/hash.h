#ifndef DICT_HASH_H
#define DICT_HASH_H

#include "types.h"
uint64 hashed(const char *key);
uint64 index_from_hash(const uint64 hash, const uint64 size);
#endif
