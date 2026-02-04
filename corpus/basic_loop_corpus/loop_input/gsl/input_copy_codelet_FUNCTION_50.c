#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <string.h>

size_t M;
size_t N;
size_t i;

void init_vars() {
    // Estimate data size for ~0.01 seconds runtime
    // Assume modern CPU can do ~1e9 iterations/sec -> aim for ~1e7 iterations
    M = 10000000;
    N = 10000000;
}