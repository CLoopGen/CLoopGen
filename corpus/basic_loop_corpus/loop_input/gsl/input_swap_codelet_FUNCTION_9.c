#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t size1;
size_t p;

void init_vars() {
    // Estimate data size for ~0.01s runtime: assume simple loop overhead
    // Modern CPU can do ~1e9 iterations/sec -> 1e7 iterations for 0.01s
    size1 = 10000000;  // 10 million iterations
}