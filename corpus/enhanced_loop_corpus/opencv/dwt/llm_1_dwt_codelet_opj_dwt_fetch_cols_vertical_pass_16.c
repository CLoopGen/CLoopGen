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
    OPJ_UINT32 block_size = 8;
    OPJ_UINT32 total_elements = height * block_size;
    OPJ_UINT32 idx;
    for (idx = 0; idx < total_elements; ++idx) {
        OPJ_UINT32 k = idx / block_size;
        OPJ_UINT32 c = idx % block_size;
        if (c < cols && k < height) {
            tmp[idx] = array[c + k * stride_width];
        } else if (k < height) {
            tmp[idx] = 0;
        }
    }
}
