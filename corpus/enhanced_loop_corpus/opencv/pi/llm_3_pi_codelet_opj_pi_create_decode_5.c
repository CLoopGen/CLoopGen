#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 numcomps;
extern OPJ_UINT32 compno;
extern OPJ_UINT32 **l_tmp_ptr;
extern OPJ_UINT32 l_data_stride;
extern OPJ_UINT32 *l_encoding_value_ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 *l_tmp_indices = (OPJ_UINT32*)malloc(numcomps * sizeof(OPJ_UINT32));
    if (!l_tmp_indices) return;
    for (compno = 0; compno < numcomps; ++compno) {
        l_tmp_indices[compno] = compno;
    }
    for (compno = 0; compno < numcomps; ++compno) {
        OPJ_UINT32 idx = l_tmp_indices[compno];
        l_tmp_ptr[idx] = l_encoding_value_ptr;
        l_encoding_value_ptr += l_data_stride;
    }
    free(l_tmp_indices);
}
