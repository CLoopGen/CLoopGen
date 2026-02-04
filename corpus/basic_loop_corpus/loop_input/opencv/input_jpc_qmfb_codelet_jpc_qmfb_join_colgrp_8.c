#include <stdlib.h>
#include <stdint.h>

typedef int_fast32_t jpc_fix_t;

jpc_fix_t *srcptr2;
jpc_fix_t *dstptr2;
int i;

static jpc_fix_t *src_buffer;
static jpc_fix_t *dst_buffer;
static size_t data_size;
static size_t num_iterations;

void init_vars() {
    data_size = 64 * 1024 * 1024; // ~256 MB total (64M elements * 4 bytes each)
    num_iterations = data_size / sizeof(jpc_fix_t);

    src_buffer = (jpc_fix_t *)aligned_alloc(32, data_size);
    dst_buffer = (jpc_fix_t *)aligned_alloc(32, data_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < num_iterations; ++idx) {
        src_buffer[idx] = (jpc_fix_t)(idx & 0x7FFF);
    }

    srcptr2 = src_buffer;
    dstptr2 = dst_buffer;
}