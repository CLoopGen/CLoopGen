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

void init_vars() {
    size_t num_elements = 16777216; // ~64 MB of data (16 * 4 bytes per element * 1e6 / 4)
    src_buffer = (jpc_fix_t*)aligned_alloc(32, num_elements * sizeof(jpc_fix_t));
    dst_buffer = (jpc_fix_t*)aligned_alloc(32, num_elements * sizeof(jpc_fix_t));

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; ++idx) {
        src_buffer[idx] = (jpc_fix_t)(idx & 0xFFFFF);
    }

    srcptr2 = src_buffer;
    dstptr2 = dst_buffer;
}

__attribute__((destructor))
static void cleanup() {
    free(src_buffer);
    free(dst_buffer);
}