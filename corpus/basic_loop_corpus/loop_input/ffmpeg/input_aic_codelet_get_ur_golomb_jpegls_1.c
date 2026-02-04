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
    // Initialize variables to ensure the loop runs meaningfully
    // and operates within safe bounds.

    // Choose problem size so that loop runs ~0.01 seconds
    // Based on typical performance, several hundred thousand iterations
    // take about 0.01s; we choose limit accordingly.
    limit = 500000;

    re_index = 0;
    re_cache = 0; // Ensures condition (((uint32_t)(re_cache)) >> (32 - (1))) == 0 is initially true
    re_size_plus8 = 32; // A reasonable size for re_index upper bound
    i = 0;
}