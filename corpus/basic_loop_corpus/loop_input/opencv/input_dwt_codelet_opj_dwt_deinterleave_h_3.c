#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;

OPJ_INT32 dn;
OPJ_INT32 i;
OPJ_INT32 *restrict l_dest;
OPJ_INT32 *restrict l_src;

static OPJ_INT32 *l_dest_buf;
static OPJ_INT32 *l_src_buf;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64MB of input data for l_src
    const size_t num_elements = total_data_size / sizeof(OPJ_INT32);
    
    dn = num_elements / 2; // because l_src advances by 2 per iteration

    l_dest_buf = (OPJ_INT32*)aligned_alloc(32, dn * sizeof(OPJ_INT32));
    l_src_buf = (OPJ_INT32*)aligned_alloc(32, num_elements * sizeof(OPJ_INT32));

    if (!l_dest_buf || !l_src_buf) {
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; ++idx) {
        l_src_buf[idx] = (OPJ_INT32)(idx & 0xFF);
    }

    l_dest = l_dest_buf;
    l_src = l_src_buf;
}