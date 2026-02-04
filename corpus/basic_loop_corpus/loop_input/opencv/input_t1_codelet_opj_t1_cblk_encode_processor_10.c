#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t OPJ_UINT32;

OPJ_UINT32 tile_w = 256;
OPJ_UINT32 cblk_w = 256;
OPJ_UINT32 cblk_h = 256;
OPJ_UINT32 i;
OPJ_UINT32 j;

OPJ_UINT32 *restrict tiledp_u;
OPJ_UINT32 *restrict t1data;

void init_vars() {
    // Allocate tiledp_u with size based on tile_w and cblk_h to prevent out-of-bounds access
    // We ensure tile_w >= cblk_w and allocate enough rows (at least cblk_h)
    tiledp_u = (OPJ_UINT32*)aligned_alloc(64, sizeof(OPJ_UINT32) * tile_w * cblk_h);
    
    // t1data needs to hold output: (cblk_h & ~3U) / 4 * cblk_w * 4 elements
    OPJ_UINT32 t1_size = ((cblk_h & ~3U) / 4) * cblk_w * 4;
    t1data = (OPJ_UINT32*)aligned_alloc(64, sizeof(OPJ_UINT32) * t1_size);

    // Initialize tiledp_u with non-zero test pattern to allow inspection if needed
    for (OPJ_UINT32 idx = 0; idx < tile_w * cblk_h; ++idx) {
        tiledp_u[idx] = (idx * 17) & 0xFF;
    }

    // Zero-initialize t1data
    for (OPJ_UINT32 idx = 0; idx < t1_size; ++idx) {
        t1data[idx] = 0;
    }
}