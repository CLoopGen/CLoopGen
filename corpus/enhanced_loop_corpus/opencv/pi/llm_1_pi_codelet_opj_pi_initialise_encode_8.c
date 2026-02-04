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
    OPJ_UINT32 group_size = 4;
    OPJ_UINT32 num_groups = (numcomps + group_size - 1) / group_size;
    OPJ_UINT32 g, i;
    for (g = 0; g < num_groups; ++g) {
        for (i = 0; i < group_size; ++i) {
            compno = g * group_size + i;
            if (compno >= numcomps) break;
            l_tmp_ptr[compno] = l_encoding_value_ptr;
            l_encoding_value_ptr += l_data_stride;
        }
    }
}
