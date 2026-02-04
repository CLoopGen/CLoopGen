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
    for (i = 0; i < cblk_w; ++i) {
        OPJ_UINT32 val0 = tiledp_u[(j + 0) * tile_w + i];
        OPJ_UINT32 val1 = tiledp_u[(j + 1) * tile_w + i];
        OPJ_UINT32 val2 = tiledp_u[(j + 2) * tile_w + i];
        OPJ_UINT32 val3 = tiledp_u[(j + 3) * tile_w + i];
        
        t1data[0] = (val0 << (7 - 1)) + (val0 >> (32 - (7 - 1)));
        t1data[1] = (val1 << (7 - 1)) + (val1 >> (32 - (7 - 1)));
        t1data[2] = (val2 << (7 - 1)) + (val2 >> (32 - (7 - 1)));
        t1data[3] = (val3 << (7 - 1)) + (val3 >> (32 - (7 - 1)));
        
        t1data += 4;
    }
}
}
