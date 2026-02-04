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
OPJ_UINT32 step_j = (cblk_h & ~3U) > 8 ? 8 : 4;
for (j = 0; j < (cblk_h & ~3U); j += step_j) {
    if (j + 7 < (cblk_h & ~3U)) {
        for (i = 0; i < cblk_w; ++i) {
            t1data[0] = tiledp_u[(j + 0) * tile_w + i] << (7 - 1);
            t1data[1] = tiledp_u[(j + 1) * tile_w + i] << (7 - 1);
            t1data[2] = tiledp_u[(j + 2) * tile_w + i] << (7 - 1);
            t1data[3] = tiledp_u[(j + 3) * tile_w + i] << (7 - 1);
            t1data[4] = tiledp_u[(j + 4) * tile_w + i] << (7 - 1);
            t1data[5] = tiledp_u[(j + 5) * tile_w + i] << (7 - 1);
            t1data[6] = tiledp_u[(j + 6) * tile_w + i] << (7 - 1);
            t1data[7] = tiledp_u[(j + 7) * tile_w + i] << (7 - 1);
            t1data += 8;
        }
    } else {
        for (i = 0; i < cblk_w; ++i) {
            t1data[0] = tiledp_u[(j + 0) * tile_w + i] << (7 - 1);
            t1data[1] = tiledp_u[(j + 1) * tile_w + i] << (7 - 1);
            t1data[2] = tiledp_u[(j + 2) * tile_w + i] << (7 - 1);
            t1data[3] = tiledp_u[(j + 3) * tile_w + i] << (7 - 1);
            t1data += 4;
        }
    }
}
}
