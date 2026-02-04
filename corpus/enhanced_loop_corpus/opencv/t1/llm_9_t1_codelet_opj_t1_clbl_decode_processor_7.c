#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

typedef size_t OPJ_SIZE_T;

extern OPJ_INT32 *restrict datap;
extern OPJ_UINT32 cblk_w;
extern OPJ_UINT32 cblk_h;
extern OPJ_UINT32 i;
extern OPJ_UINT32 j;
extern OPJ_UINT32 tile_w;
extern OPJ_INT32 *restrict tiledp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < cblk_h; ++j) {
    for (i = 0; i < cblk_w; ++i) {
        OPJ_INT32 val = datap[j * cblk_w + i];
        OPJ_INT32 result;
        if (val >= 0) {
            result = (val + 1) >> 1;
        } else {
            result = (val - 1) >> 1;
        }
        ((OPJ_INT32 *)tiledp)[j * (OPJ_SIZE_T)tile_w + i] = result;
    }
}
}
