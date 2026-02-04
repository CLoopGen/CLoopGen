#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;

int numcols;
jpc_fix_t *srcptr2;
jpc_fix_t *dstptr2;
int i;

static jpc_fix_t *src_storage;
static jpc_fix_t *dst_storage;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB total for both arrays (64M elements × 4 bytes × 2)
    const size_t num_elements = data_size / sizeof(jpc_fix_t);

    src_storage = (jpc_fix_t*)aligned_alloc(32, data_size);
    dst_storage = (jpc_fix_t*)aligned_alloc(32, data_size);

    if (!src_storage || !dst_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; ++idx) {
        src_storage[idx] = (jpc_fix_t)(idx & 0xFFFF);
    }

    numcols = (int)num_elements;
    srcptr2 = src_storage;
    dstptr2 = dst_storage;
}