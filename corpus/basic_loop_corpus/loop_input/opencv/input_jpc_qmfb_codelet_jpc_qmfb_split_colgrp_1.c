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
static size_t buffer_size = 16777216; // 64 MB of data (16,777,216 elements * 4 bytes each ≈ 64 MB)

void init_vars() {
    src_buffer = (jpc_fix_t*)aligned_alloc(32, buffer_size * sizeof(jpc_fix_t));
    dst_buffer = (jpc_fix_t*)aligned_alloc(32, buffer_size * sizeof(jpc_fix_t));

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < buffer_size; ++idx) {
        src_buffer[idx] = (jpc_fix_t)(idx & 0x7FFF);
    }

    srcptr2 = src_buffer;
    dstptr2 = dst_buffer;
}