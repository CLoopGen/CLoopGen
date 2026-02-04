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
    limit = 10000000; // Sufficient iterations to take ~0.01 seconds
    re_index = 0;
    re_cache = 0;
    re_size_plus8 = 32; // Example value ensuring safe indexing behavior
    i = 0;
}