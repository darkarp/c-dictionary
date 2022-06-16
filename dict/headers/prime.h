#ifndef PRIME_H
#define PRIME_H

#include <stdbool.h>
#include "types.h"
#include <stdio.h>
#include <math.h>

bool is_prime(uint64 n);
uint64 next_prime(uint64 n);

#endif