#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

typedef int tmsize_t;

tmsize_t cc;
tmsize_t i;

void init_vars() {
    // Estimate iteration count for ~0.01 seconds
    // Assume modern CPU can do ~1e9 simple operations per second
    // So for 0.01s, aim for ~1e7 iterations
    cc = 10000000; // 10 million iterations
    i = 0;
}