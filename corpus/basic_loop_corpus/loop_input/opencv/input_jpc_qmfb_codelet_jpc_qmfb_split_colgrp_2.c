#include <stdlib.h>
#include <stdint.h>

typedef int_fast32_t jpc_fix_t;

jpc_fix_t *srcptr2;
jpc_fix_t *dstptr2;
int i;

static jpc_fix_t *src_storage;
static jpc_fix_t *dst_storage;
static size_t data_size;

void init_vars() {
    data_size = 1 << 24; // 16M elements, ~64MB total data

    src_storage = (jpc_fix_t*)aligned_alloc(32, data_size * sizeof(jpc_fix_t));
    dst_storage = (jpc_fix_t*)aligned_alloc(32, data_size * sizeof(jpc_fix_t));

    if (!src_storage || !dst_storage) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        src_storage[idx] = (jpc_fix_t)(idx & 0xFFFFF);
    }

    srcptr2 = src_storage;
    dstptr2 = dst_storage;
}