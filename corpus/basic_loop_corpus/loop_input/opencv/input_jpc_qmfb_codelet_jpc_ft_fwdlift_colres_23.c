#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;

int numcols;
int stride;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_storage;
static jpc_fix_t *hptr2_storage;

void init_vars() {
    const size_t total_size = 64 * 1024 * 1024; // 64 MB total data
    const size_t element_size = sizeof(jpc_fix_t);
    const size_t count = total_size / (2 * element_size); // Two arrays

    numcols = (int)count;
    stride = 1;

    lptr2_storage = aligned_alloc(32, (numcols + 1) * element_size);
    hptr2_storage = aligned_alloc(32, (numcols + stride + 1) * element_size);

    if (!lptr2_storage || !hptr2_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < numcols; ++idx) {
        lptr2_storage[idx] = (jpc_fix_t)(idx & 0xFF);
        hptr2_storage[idx] = (jpc_fix_t)((idx + 1) & 0xFF);
        hptr2_storage[idx + stride] = (jpc_fix_t)((idx + 2) & 0xFF);
    }

    lptr2 = lptr2_storage;
    hptr2 = hptr2_storage;
}

void cleanup_vars() {
    free(lptr2_storage);
    free(hptr2_storage);
}