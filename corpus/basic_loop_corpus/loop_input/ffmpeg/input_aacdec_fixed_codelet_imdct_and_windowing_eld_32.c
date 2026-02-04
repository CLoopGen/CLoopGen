#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int INTFLOAT;

INTFLOAT *buf;
int i;

void init_vars() {
    size_t num_elements = 134217728; // ~512MB for INTFLOAT (4 bytes each)
    buf = aligned_alloc(32, num_elements * sizeof(INTFLOAT));
    if (!buf) {
        exit(1);
    }
    for (size_t idx = 0; idx < num_elements; idx++) {
        buf[idx] = rand();
    }
}