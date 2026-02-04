#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t i;
size_t n = 65536000; // ~500MB of size_t elements (8 bytes each)
size_t *pp;

void init_vars() {
    pp = (size_t*)aligned_alloc(64, n * sizeof(size_t));
    if (!pp) {
        exit(1);
    }
}