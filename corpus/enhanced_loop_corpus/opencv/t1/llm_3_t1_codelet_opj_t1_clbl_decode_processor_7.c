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
    // Variant 2: Strided Memory Access Pattern
    // Reorganize the loop to traverse memory in a strided manner across rows,
    // processing one column at a time for all rows before moving to next column.
    // This creates a strided access pattern in both source (`datap`) and destination (`tiledp`).

    OPJ_SIZE_T tile_stride = (OPJ_SIZE_T)tile_w;
    // Process columns in chunks of 4 first
    OPJ_UINT32 col;
    for (col = 0; col < (cblk_w & ~(OPJ_UINT32)3U); col += 4U) {
        for (j = 0; j < cblk_h; ++j) {
            OPJ_SIZE_T data_idx = j * cblk_w + col;
            OPJ_SIZE_T tile_idx = j * tile_stride + col;
            ((OPJ_INT32 *)tiledp)[tile_idx + 0U] = datap[data_idx + 0U] / 2;
            ((OPJ_INT32 *)tiledp)[tile_idx + 1U] = datap[data_idx + 1U] / 2;
            ((OPJ_INT32 *)tiledp)[tile_idx + 2U] = datap[data_idx + 2U] / 2;
            ((OPJ_INT32 *)tiledp)[tile_idx + 3U] = datap[data_idx + 3U] / 2;
        }
    }
    // Handle leftover columns
    for (; col < cblk_w; ++col) {
        for (j = 0; j < cblk_h; ++j) {
            OPJ_SIZE_T data_idx = j * cblk_w + col;
            OPJ_SIZE_T tile_idx = j * tile_stride + col;
            ((OPJ_INT32 *)tiledp)[tile_idx] = datap[data_idx] / 2;
        }
    }
}
