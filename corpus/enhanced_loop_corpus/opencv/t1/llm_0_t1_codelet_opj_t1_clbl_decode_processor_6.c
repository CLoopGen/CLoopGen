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
    OPJ_UINT32 j;
    for (j = 0; j < cblk_size; ++j) {
        for (i = j; i < j + 1 && i < cblk_size; ++i) {
            datap[i] /= 2;
        }
    }
}
