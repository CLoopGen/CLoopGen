#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

size_t M;
size_t N;
size_t i;
size_t j;

void init_vars() {
    const size_t target_iters = 10000000; // Target approximately 10M iterations for ~0.01 sec runtime
    M = N = (size_t)sqrt((double)target_iters);
}