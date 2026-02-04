#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;

int numcols;
jpc_fix_t *srcptr2;
jpc_fix_t *dstptr2;
int i;

#define DATA_SIZE (64 * 1024 * 1024) // ~256 MB total for two arrays (64M elements * 4 bytes each)

static jpc_fix_t *src_data;
static jpc_fix_t *dst_data;

void init_vars() {
    src_data = (jpc_fix_t*)aligned_alloc(32, DATA_SIZE * sizeof(jpc_fix_t));
    dst_data = (jpc_fix_t*)aligned_alloc(32, DATA_SIZE * sizeof(jpc_fix_t));

    if (!src_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        src_data[idx] = (jpc_fix_t)(idx & 0xFFFF);
        dst_data[idx] = 0;
    }

    numcols = DATA_SIZE;
    srcptr2 = src_data;
    dstptr2 = dst_data;
    i = 0;
}