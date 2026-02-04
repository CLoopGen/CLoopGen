#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *restrict datap;
extern OPJ_UINT32 i;
extern OPJ_UINT32 cblk_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 stride = 2;
    for (i = 0; i < cblk_size; i += stride) {
        if (i + stride - 1 < cblk_size) {
            datap[i] /= 2;
        }
    }
}
