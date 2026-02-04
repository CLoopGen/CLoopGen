#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;

jpc_fix_t *srcptr2;
jpc_fix_t *dstptr2;
int i;

static jpc_fix_t *src_buffer;
static jpc_fix_t *dst_buffer;
static size_t data_size = 1 << 20; // 1MB of data (approximately 262,144 elements for jpc_fix_t)

void init_vars() {
    src_buffer = (jpc_fix_t*)aligned_alloc(64, data_size * sizeof(jpc_fix_t));
    dst_buffer = (jpc_fix_t*)aligned_alloc(64, data_size * sizeof(jpc_fix_t));

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        src_buffer[idx] = (jpc_fix_t)(idx & 0x7FFF);
        dst_buffer[idx] = 0;
    }

    srcptr2 = src_buffer;
    dstptr2 = dst_buffer;
}