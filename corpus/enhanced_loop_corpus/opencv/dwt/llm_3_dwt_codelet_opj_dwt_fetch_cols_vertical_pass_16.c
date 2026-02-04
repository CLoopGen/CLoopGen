#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

typedef int32_t OPJ_INT32;

extern OPJ_UINT32 height;
extern OPJ_UINT32 stride_width;
extern OPJ_UINT32 cols;
extern  OPJ_INT32 *restrict array;
extern OPJ_INT32 *restrict tmp;
extern OPJ_UINT32 k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < height; ++k) {
        OPJ_UINT32 c;
        // Reverse traversal of input row to modify memory access pattern
        OPJ_UINT32 offset_in = k * stride_width;
        OPJ_UINT32 offset_out = 8 * k;
        if (cols > 0) {
            for (c = cols; c > 0; --c) {
                OPJ_UINT32 idx = c - 1;
                tmp[offset_out + idx] = array[offset_in + idx];
            }
        }
        // Fill remaining output positions with zero (forward from cols to 7)
        for (c = cols; c < 8; ++c) {
            tmp[offset_out + c] = 0;
        }
    }
}
