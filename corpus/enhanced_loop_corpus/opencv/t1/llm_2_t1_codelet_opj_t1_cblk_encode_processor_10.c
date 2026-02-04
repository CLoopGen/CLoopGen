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
    OPJ_UINT32 stride = tile_w * 4;
    for (j = 0; j < (cblk_h & ~3U); j += 4) {
        OPJ_UINT32 offset0 = (j + 0) * tile_w;
        OPJ_UINT32 offset1 = (j + 1) * tile_w;
        OPJ_UINT32 offset2 = (j + 2) * tile_w;
        OPJ_UINT32 offset3 = (j + 3) * tile_w;
        for (i = 0; i < cblk_w; ++i) {
            t1data[0] = tiledp_u[offset0 + i] << 6;
            t1data[1] = tiledp_u[offset1 + i] << 6;
            t1data[2] = tiledp_u[offset2 + i] << 6;
            t1data[3] = tiledp_u[offset3 + i] << 6;
            t1data += 4;
        }
    }
}
