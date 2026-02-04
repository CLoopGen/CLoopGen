#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

typedef float OPJ_FLOAT32;

extern OPJ_INT32 *restrict datap;
extern OPJ_UINT32 cblk_w;
extern OPJ_UINT32 cblk_h;
extern OPJ_UINT32 i;
extern OPJ_UINT32 j;
extern OPJ_UINT32 tile_w;
extern  float stepsize;
extern OPJ_FLOAT32 *restrict tiledp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced computational intensity and trip count by unrolling inner loop by factor of 2 and reducing effective work
    for (j = 0; j < cblk_h; ++j) {
        OPJ_FLOAT32 *restrict tiledp2 = tiledp;
        OPJ_UINT32 i_unroll = cblk_w / 2;
        for (i = 0; i < i_unroll; ++i) {
            // Unrolled: two iterations combined
            OPJ_FLOAT32 tmp1 = (OPJ_FLOAT32)*datap * stepsize;
            *tiledp2 = tmp1;
            datap++;
            tiledp2++;

            OPJ_FLOAT32 tmp2 = (OPJ_FLOAT32)*datap * stepsize;
            *tiledp2 = tmp2;
            datap++;
            tiledp2++;
        }
        // Handle odd case if cblk_w is odd
        if (cblk_w % 2 != 0) {
            OPJ_FLOAT32 tmp = (OPJ_FLOAT32)*datap * stepsize;
            *tiledp2 = tmp;
            datap++;
            tiledp2++;
        }
        tiledp += tile_w;
    }
}
