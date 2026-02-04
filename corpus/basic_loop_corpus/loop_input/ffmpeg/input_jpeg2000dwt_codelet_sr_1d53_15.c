#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int *p;
int i0;
int i1;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data to target ~0.01 sec runtime
    p = (unsigned int*)aligned_alloc(32, data_size);
    if (!p) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size / sizeof(unsigned int); idx++) {
        p[idx] = rand();
    }

    i0 = 2;  // ensures 2*i >= 0 and 2*i accesses valid memory
    i1 = (data_size / sizeof(unsigned int)) - 2;  // ensures 2*i+2 < array size when i < (i1>>1)
}