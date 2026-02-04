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
    OPJ_UINT32 i;
    OPJ_UINT32 *base_ptr = l_encoding_value_ptr;
    for (i = 0; i < numcomps; ++i) {
        l_tmp_ptr[i] = base_ptr;
        base_ptr += l_data_stride;
    }
    l_encoding_value_ptr = base_ptr;
}
