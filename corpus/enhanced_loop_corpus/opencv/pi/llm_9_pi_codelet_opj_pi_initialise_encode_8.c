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
    OPJ_UINT32 i, unroll_factor = 4;
    OPJ_UINT32 rounded_down = (numcomps / unroll_factor) * unroll_factor;
    for (compno = 0; compno < rounded_down; compno += unroll_factor) {
        for (i = 0; i < unroll_factor; ++i) {
            l_tmp_ptr[compno + i] = l_encoding_value_ptr;
            l_encoding_value_ptr += l_data_stride;
        }
    }
    for (; compno < numcomps; ++compno) {
        l_tmp_ptr[compno] = l_encoding_value_ptr;
        l_encoding_value_ptr += l_data_stride;
    }
}
