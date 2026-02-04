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
    i = 0;
    for (; i < (cblk_w & ~(OPJ_UINT32)3U); i += 4U) {
        OPJ_INT32 tmp0 = datap[(j * cblk_w) + i + 0U];
        OPJ_INT32 tmp1 = datap[(j * cblk_w) + i + 1U];
        OPJ_INT32 tmp2 = datap[(j * cblk_w) + i + 2U];
        OPJ_INT32 tmp3 = datap[(j * cblk_w) + i + 3U];
        ((OPJ_INT32 *)tiledp)[(j * (OPJ_SIZE_T)tile_w) + i + 0U] = tmp0 / 2;
        ((OPJ_INT32 *)tiledp)[(j * (OPJ_SIZE_T)tile_w) + i + 1U] = tmp1 / 2;
        ((OPJ_INT32 *)tiledp)[(j * (OPJ_SIZE_T)tile_w) + i + 2U] = tmp2 / 2;
        ((OPJ_INT32 *)tiledp)[(j * (OPJ_SIZE_T)tile_w) + i + 3U] = tmp3 / 2;
    }
    for (; i < cblk_w; ++i) {
        OPJ_INT32 tmp = datap[(j * cblk_w) + i];
        ((OPJ_INT32 *)tiledp)[(j * (OPJ_SIZE_T)tile_w) + i] = tmp / 2;
    }
}

}
