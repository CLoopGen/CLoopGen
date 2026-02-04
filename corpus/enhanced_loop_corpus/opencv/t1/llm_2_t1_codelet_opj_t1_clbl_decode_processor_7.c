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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing by row-major with stride `cblk_w`, we precompute the base offset per row
    // and access elements consecutively within the inner loop for better spatial locality.

    OPJ_SIZE_T tile_stride = (OPJ_SIZE_T)tile_w;
    for (j = 0; j < cblk_h; ++j) {
        OPJ_SIZE_T data_row_base = j * cblk_w;
        OPJ_SIZE_T tile_row_base = j * tile_stride;
        i = 0;
        // Process 4 elements at a time with consecutive access from base
        for (; i < (cblk_w & ~(OPJ_UINT32)3U); i += 4U) {
            OPJ_INT32 tmp0 = datap[data_row_base + i + 0U];
            OPJ_INT32 tmp1 = datap[data_row_base + i + 1U];
            OPJ_INT32 tmp2 = datap[data_row_base + i + 2U];
            OPJ_INT32 tmp3 = datap[data_row_base + i + 3U];
            ((OPJ_INT32 *)tiledp)[tile_row_base + i + 0U] = tmp0 / 2;
            ((OPJ_INT32 *)tiledp)[tile_row_base + i + 1U] = tmp1 / 2;
            ((OPJ_INT32 *)tiledp)[tile_row_base + i + 2U] = tmp2 / 2;
            ((OPJ_INT32 *)tiledp)[tile_row_base + i + 3U] = tmp3 / 2;
        }
        // Handle remaining elements
        for (; i < cblk_w; ++i) {
            OPJ_INT32 tmp = datap[data_row_base + i];
            ((OPJ_INT32 *)tiledp)[tile_row_base + i] = tmp / 2;
        }
    }
}
