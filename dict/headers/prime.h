#ifndef PRIME_H
#define PRIME_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

bool is_prime(uint64_t n);
uint64_t next_prime(uint64_t n);

#endif