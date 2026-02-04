#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int INTFLOAT;

INTFLOAT *buf;
int i;

void init_vars() {
    size_t num_elements = 64 * 1024 * 1024 / sizeof(INTFLOAT);
    buf = aligned_alloc(32, num_elements * sizeof(INTFLOAT));
    if (!buf) {
        exit(1);
    }
    for (size_t j = 0; j < num_elements; j++) {
        buf[j] = rand();
    }
}