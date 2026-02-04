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
    // On a typical modern CPU, this corresponds to roughly 10^7 to 10^8 iterations
    // We set limit to 25 million as a reasonable value within that range

    limit = 25000000;  // ~25M iterations should take ~0.01s with lightweight operations

    re_cache = 0x40000000U;  // High bit set so that (re_cache >> 31) == 1 initially, but will shift out quickly
    re_index = 0;
    re_size_plus8 = 1024;  // Arbitrary size, larger than any expected index growth
    i = 0;
}