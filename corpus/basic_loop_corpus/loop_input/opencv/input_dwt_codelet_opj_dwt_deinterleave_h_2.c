#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;

OPJ_INT32 sn;
OPJ_INT32 i;
OPJ_INT32 *restrict l_dest;
OPJ_INT32 *restrict l_src;

static OPJ_INT32 *l_src_buffer;
static OPJ_INT32 *l_dest_buffer;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64MB of input data for ~0.01 sec runtime
    const size_t num_elements = total_data_size / sizeof(OPJ_INT32);
    
    sn = num_elements;

    l_src_buffer = (OPJ_INT32*)aligned_alloc(32, sizeof(OPJ_INT32) * (sn * 2));
    l_dest_buffer = (OPJ_INT32*)aligned_alloc(32, sizeof(OPJ_INT32) * sn);

    if (!l_src_buffer || !l_dest_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < sn * 2; ++idx) {
        l_src_buffer[idx] = (OPJ_INT32)(idx * 3);
    }

    l_src = l_src_buffer;
    l_dest = l_dest_buffer;
}