#ifndef DICT_HASH_H
#define DICT_HASH_H
#include <stdint.h>
uint64_t hashed(const char* key);
uint64_t index_from_hash(const uint64_t hash, const size_t size);
#endif