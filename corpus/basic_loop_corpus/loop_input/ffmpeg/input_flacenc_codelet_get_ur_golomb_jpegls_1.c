#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int limit;
unsigned int re_index;
__attribute__((unused)) unsigned int re_cache;
unsigned int re_size_plus8;
int i;

void init_vars() {
    // Initialize variables to ensure the loop runs for approximately 0.01 seconds
    // Assuming typical modern CPU can handle ~1e8-1e9 iterations per second,
    // set limit to around 1e6 to 1e7 for a 0.01s runtime.

    limit = 5000000;  // 5 million iterations should take ~0.01s

    re_cache = 0x40000000U;  // High bit set so that (re_cache >> 31) == 1 initially, but condition fails until shift makes it zero
    re_index = 0;
    re_size_plus8 = 1024;  // Large enough to allow index growth without bound issues
    i = 0;
}