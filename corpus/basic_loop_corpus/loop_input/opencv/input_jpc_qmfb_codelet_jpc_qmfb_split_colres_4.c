#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;

int numcols;
jpc_fix_t *srcptr2;
jpc_fix_t *dstptr2;
int i;

static jpc_fix_t *src_buffer;
static jpc_fix_t *dst_buffer;
static size_t buffer_size;

void init_vars() {
    buffer_size = 64 * 1024 * 1024 / sizeof(jpc_fix_t); // ~64MB of data to target ~0.01s runtime
    numcols = buffer_size;

    src_buffer = (jpc_fix_t*)aligned_alloc(32, buffer_size * sizeof(jpc_fix_t));
    dst_buffer = (jpc_fix_t*)aligned_alloc(32, buffer_size * sizeof(jpc_fix_t));

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < buffer_size; ++idx) {
        src_buffer[idx] = (jpc_fix_t)(idx & 0xFFFF);
        dst_buffer[idx] = 0;
    }

    srcptr2 = src_buffer;
    dstptr2 = dst_buffer;
}