#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t OPJ_UINT32;

OPJ_UINT32 numcomps = 65536;
OPJ_UINT32 compno;
OPJ_UINT32 **l_tmp_ptr;
OPJ_UINT32 l_data_stride = 16;
OPJ_UINT32 *l_encoding_value_ptr;

void init_vars() {
    l_tmp_ptr = (OPJ_UINT32**)calloc(numcomps, sizeof(OPJ_UINT32*));
    if (!l_tmp_ptr) {
        exit(1);
    }

    OPJ_UINT32 total_data_size = numcomps * l_data_stride;
    l_encoding_value_ptr = (OPJ_UINT32*)malloc(total_data_size * sizeof(OPJ_UINT32));
    if (!l_encoding_value_ptr) {
        free(l_tmp_ptr);
        exit(1);
    }
}