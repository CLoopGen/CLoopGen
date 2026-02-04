#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;

int numcols;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_base;
static jpc_fix_t *hptr2_base;
static size_t data_size;

void init_vars() {
    data_size = 64 * 1024 * 1024; // ~64MB of data per array to target ~0.01s runtime
    numcols = data_size / sizeof(jpc_fix_t);

    lptr2_base = (jpc_fix_t*)aligned_alloc(32, data_size);
    hptr2_base = (jpc_fix_t*)aligned_alloc(32, data_size);

    if (!lptr2_base || !hptr2_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < numcols; ++idx) {
        lptr2_base[idx] = idx % 100;
        hptr2_base[idx] = (idx + 42) % 200;
    }

    lptr2 = lptr2_base;
    hptr2 = hptr2_base;
}