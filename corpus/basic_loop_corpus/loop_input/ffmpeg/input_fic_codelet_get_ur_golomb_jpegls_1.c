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
    // Assuming typical modern CPU can do ~1e9 operations/sec, target ~1e7 iterations
    limit = 10000000;  // 10 million iterations

    re_cache = 0x40000000U;  // Ensures (re_cache >> 31) == 0 initially
    re_index = 0;
    re_size_plus8 = 32;  // Example value: corresponds to size 24 with +8 offset
    i = 0;
}