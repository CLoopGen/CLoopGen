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
    // Set up parameters to ensure the loop runs for approximately 0.01 seconds
    // On a typical modern CPU, we assume the loop body takes several cycles.
    // Empirically, setting limit around 10 million gives roughly 0.01s when optimized.

    limit = 10000000;

    re_cache = 0x40000000U;  // High bit set so that (re_cache >> 31) == 0 initially
    re_index = 0;
    re_size_plus8 = 256 + 8;  // Example value: corresponds to some buffer size + 8
    i = 0;
}