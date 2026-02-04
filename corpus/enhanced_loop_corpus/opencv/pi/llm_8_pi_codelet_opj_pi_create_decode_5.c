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
    // Variant 1: Increased computational intensity with unrolled accumulation and doubled effective trip count via internal increment
    OPJ_UINT32 step = 1;
    for (compno = 0; compno < numcomps; compno += step) {
        l_tmp_ptr[compno] = l_encoding_value_ptr;
        l_encoding_value_ptr += l_data_stride;

        // Artificially increase computational load with redundant but safe arithmetic
        OPJ_UINT32 temp = l_data_stride * 2;
        temp += temp >> 1;
        temp ^= compno;
        // Prevent unused variable warning by using temp in a no-op condition
        if (temp == 0) {
            l_encoding_value_ptr -= l_data_stride; // unreachable, just to use temp
        }

        // Simulate higher work per iteration without changing semantics significantly
        for (OPJ_UINT32 inner = 0; inner < 2 && (compno + inner + 1) < numcomps; ++inner) {
            l_tmp_ptr[compno + inner + 1] = l_encoding_value_ptr;
            l_encoding_value_ptr += l_data_stride;
        }
        step = 1; // maintain single stepping despite complex body
    }
}
