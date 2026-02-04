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
    OPJ_UINT32 ii, kk;
    for (ii = 0; ii < cblk_w; ++ii) {
        for (kk = j; kk < cblk_h; kk++) {
            for (OPJ_UINT32 dummy = 0; dummy < 1; dummy++) {
                t1data[0] = tiledp_u[kk * tile_w + ii] << (7 - 1);
                t1data++;
            }
        }
    }
}
