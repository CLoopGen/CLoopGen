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
    OPJ_UINT32 temp_accum = 0;
    for (i = 0; i < cblk_w; ++i) {
        OPJ_UINT32 k;
        for (k = j; k < cblk_h; k++) {
            temp_accum += tiledp_u[k * tile_w + i]; 
            t1data[0] = temp_accum << (7 - 1);
            t1data++;
        }
    }
}
