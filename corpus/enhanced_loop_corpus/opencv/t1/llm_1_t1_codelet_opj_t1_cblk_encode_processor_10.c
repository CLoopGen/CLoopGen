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
    for (j = 0; j < (cblk_h & ~3U); j += 4) {
        for (OPJ_UINT32 k = 0; k < cblk_w; ++k) {
            for (i = 0; i < 1; ++i) {
                t1data[0] = tiledp_u[(j + 0) * tile_w + k] << (7 - 1);
                t1data[1] = tiledp_u[(j + 1) * tile_w + k] << (7 - 1);
                t1data[2] = tiledp_u[(j + 2) * tile_w + k] << (7 - 1);
                t1data[3] = tiledp_u[(j + 3) * tile_w + k] << (7 - 1);
                t1data += 4;
            }
        }
    }
}
