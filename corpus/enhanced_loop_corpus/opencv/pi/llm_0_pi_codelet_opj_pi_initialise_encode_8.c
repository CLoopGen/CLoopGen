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
    OPJ_UINT32 compno_outer;
    for (compno_outer = 0; compno_outer < numcomps; ++compno_outer) {
        compno = compno_outer;
        l_tmp_ptr[compno] = l_encoding_value_ptr;
        l_encoding_value_ptr += l_data_stride;
    }
}
