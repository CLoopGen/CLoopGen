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
    OPJ_UINT32 j_start = 0;
    OPJ_UINT32 j_end = cblk_h;
    OPJ_UINT32 i_start, i_end;

    for (j = j_start; j < j_end; ++j) {
        i = 0;
        i_start = i;
        i_end = (cblk_w & ~(OPJ_UINT32)3U);

        for (; i < i_end; i += 4U) {
            OPJ_INT32 tmp0 = datap[(j * cblk_w) + i + 0U];
            OPJ_INT32 tmp1 = datap[(j * cblk_w) + i + 1U];
            OPJ_INT32 tmp2 = datap[(j * cblk_w) + i + 2U];
            OPJ_INT32 tmp3 = datap[(j * cblk_w) + i + 3U];

            OPJ_SIZE_T base_idx = (j * (OPJ_SIZE_T)tile_w) + i;
            ((OPJ_INT32 *)tiledp)[base_idx + 0U] = tmp0 / 2;
            ((OPJ_INT32 *)tiledp)[base_idx + 1U] = tmp1 / 2;
            ((OPJ_INT32 *)tiledp)[base_idx + 2U] = tmp2 / 2;
            ((OPJ_INT32 *)tiledp)[base_idx + 3U] = tmp3 / 2;
        }

        i_start = i;
        i_end = cblk_w;
        for (; i < i_end; ++i) {
            OPJ_INT32 tmp = datap[(j * cblk_w) + i];
            ((OPJ_INT32 *)tiledp)[(j * (OPJ_SIZE_T)tile_w) + i] = tmp / 2;
        }
    }
}
