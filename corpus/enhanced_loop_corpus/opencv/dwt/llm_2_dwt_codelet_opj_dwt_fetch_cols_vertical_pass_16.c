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
        // Interleaved access with stride of 8, unrolled by 4 for consecutive writes
        for (c = 0; c + 3 < cols; c += 4) {
            tmp[8 * k + c]     = array[c + k * stride_width];
            tmp[8 * k + c + 1] = array[c + 1 + k * stride_width];
            tmp[8 * k + c + 2] = array[c + 2 + k * stride_width];
            tmp[8 * k + c + 3] = array[c + 3 + k * stride_width];
        }
        for (; c < cols; ++c) {
            tmp[8 * k + c] = array[c + k * stride_width];
        }
        for (; c < 8; ++c) {
            tmp[8 * k + c] = 0;
        }
    }
}
