#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;

int stride;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of data to ensure sufficient runtime
static jpc_fix_t *lptr_base;
static jpc_fix_t *hptr_base;

void init_vars() {
    stride = 16; // reasonable stride value to prevent out-of-bounds access

    lptr_base = (jpc_fix_t *)aligned_alloc(32, (DATA_SIZE + stride) * sizeof(jpc_fix_t));
    hptr_base = (jpc_fix_t *)aligned_alloc(32, DATA_SIZE * sizeof(jpc_fix_t));

    if (!lptr_base || !hptr_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE + stride; ++idx) {
        lptr_base[idx] = (jpc_fix_t)(idx % 1024);
    }
    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        hptr_base[idx] = (jpc_fix_t)((idx + 512) % 2048);
    }

    lptr2 = lptr_base;
    hptr2 = hptr_base;
}