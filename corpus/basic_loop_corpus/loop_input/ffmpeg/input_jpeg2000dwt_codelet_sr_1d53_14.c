#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int *p;
int i0;
int i1;
int i;

static unsigned int *p_storage;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of data to ensure sufficient runtime
    p_storage = (unsigned int *)calloc(data_size, sizeof(unsigned int));
    if (!p_storage) {
        exit(1);
    }

    // Ensure 2*i-1 and 2*i+1 are valid: need at least [0, 2*((i1>>1)+1)-1] indices in p
    // So max index accessed is 2*((i1>>1)) + 1. Set i0 and i1 so that array bounds are safe.
    // Let’s set i0 = 2, i1 = (data_size / 2) * 2 - 2, so that 2*i+1 <= data_size-1

    i0 = 2;
    i1 = (int)(data_size - 4); // ensures 2*i+1 <= data_size-1 when i < (i1>>1)+1

    p = p_storage;
}

__attribute__((destructor))
static void cleanup() {
    free(p_storage);
}