#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern  OPJ_UINT32 tile_w;
extern OPJ_UINT32 cblk_w;
extern OPJ_UINT32 cblk_h;
extern OPJ_UINT32 i;
extern OPJ_UINT32 j;
extern OPJ_UINT32 *restrict tiledp_u;
extern OPJ_UINT32 *restrict t1data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < cblk_w; ++i) {
        OPJ_UINT32 col_offset = i;
        for (j = 0; j < (cblk_h & ~3U); j += 4) {
            OPJ_UINT32 base_offset = col_offset + j * tile_w;
            t1data[0] = tiledp_u[base_offset] << 6;
            t1data[1] = tiledp_u[base_offset + tile_w] << 6;
            t1data[2] = tiledp_u[base_offset + 2 * tile_w] << 6;
            t1data[3] = tiledp_u[base_offset + 3 * tile_w] << 6;
            t1data += 4;
        }
    }
}
