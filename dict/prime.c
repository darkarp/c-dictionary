#include "headers/prime.h"
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

//todo cleanup
bool is_prime(uint64 n)
{
    if (n <= 3) return (bool)(n > 1);
    if (!(n % 2) || !(n % 3)) return false;
    int total = (int)pow((double)n, 0.5);
    for (int i = 5; i <= total; i += 6)
        if (!(n % i) || !(n % (i + 2)))
            return false;
    return true;
}

uint64 next_prime(uint64 n)
{
    for (; !is_prime(++n););
    return n;
}