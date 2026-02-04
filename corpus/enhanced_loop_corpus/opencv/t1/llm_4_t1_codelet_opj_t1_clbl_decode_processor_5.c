#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *restrict datap;
extern OPJ_UINT32 cblk_w;
extern OPJ_UINT32 cblk_h;
extern OPJ_UINT32 i;
extern OPJ_UINT32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 idx = 0;
    for (j = 0; j < cblk_h; ++j) {
        for (i = 0; i < cblk_w; ++i) {
            if ((j & 1) == 0) {  // Only process even rows
                datap[idx] = 0;
            }
            idx++;
        }
    }
}
